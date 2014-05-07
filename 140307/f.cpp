#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N;
string num;

string numTobin(string str){
    string ret = "";
    for(int i = 0; i < str.size(); i++){
        int h = (str[i] >= 'A' and str[i] <= 'F')? 10 + str[i]-'A': str[i]-'0';
        for(int j = 3; j >= 0; j--)
            if(h & (1<<j)) ret.push_back('1');
            else ret.push_back('0');
    }
    return ret;
}

vector<int> sectBin(string bin){
    int cur = 0;
    vector<int> ret;
    while(cur < bin.size()){
        int mode = 0;
        for(int i = 0; i < 4; i++, cur++){
            mode <<= 1;
            mode += (bin[cur] == '1');
        }
        int cnt = 0;
        switch(mode){
        case 1: cnt = 10; break;
        case 2: cnt = 9; break;
        case 3: cnt = 8; break;
        case 4: cnt = 8; break;
        default: cnt = 0;
        }
        if(!cnt) return ret;
        ret.pb(mode);
        int cnt2 = 0;
        for(int i = 0; i < cnt; i++, cur++){
            cnt2 <<= 1;
            cnt2 += (bin[cur] == '1');
        }
        ret.pb(cnt2);
        switch(mode){
        case 1:
            for(int i = 0; i <= cnt2 / 3; i++){
                if(i < cnt2/3){
                    int res = 0;
                    for(int j = 0; j < 10; j++, cur++){
                        res <<= 1;
                        res += (bin[cur] == '1');
                    }
                    ret.pb(res);
                }
                else if(cnt2 % 3 == 2){
                    int res = 0;
                    for(int j = 0; j < 7; j++, cur++){
                        res <<= 1;
                        res += (bin[cur] == '1');
                    }
                    cerr << res << endl;
                    ret.pb(res);
                }
                else if(cnt2 % 3 == 1){
                    int res = 0;
                    for(int j = 0; j < 4; j++, cur++){
                        res <<= 1;
                        res += (bin[cur] == '1');
                    }
                    ret.pb(res);
                }
            }
            break;
        case 2:
            for(int i = 0; i <= cnt2 / 2; i++){
                if(i < cnt2/2){
                    int res = 0;
                    for(int j = 0; j < 11; j++, cur++){
                        res <<= 1;
                        res += (bin[cur] == '1');
                    }
                    ret.pb(res);
                }
                else if(cnt2 % 2 == 1){
                    int res = 0;
                    for(int j = 0; j < 6; j++, cur++){
                        res <<= 1;
                        res += (bin[cur] == '1');
                    }
                    ret.pb(res);
                }
            }
            break;
        case 4:
            for(int i = 0; i < cnt2; i++){
                int res = 0;
                for(int j = 0; j < 8; j++, cur++){
                    res <<= 1;
                    res += (bin[cur] == '1');
                }
                ret.pb(res);
            }
            break;
        case 8:
            for(int i = 0; i < cnt2; i++){
                int res = 0;
                for(int j = 0; j < 13; j++, cur++){
                    res <<= 1;
                    res += (bin[cur] == '1');
                }
                ret.pb(res);
            }
            break;
            
        }
    }
    return ret;
}

string charas = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";

string showQR(int bin, int mode, int pos, int cnt){
    string ret = "";
    stringstream ss;
    string str = "";
    int tmp;
    switch(mode){
    case 1:
        ss << bin;
        ss >> str;
        ret += str;
        break;
    case 2:
        cerr << bin << " " << pos << " " << cnt << endl;
        if(pos < cnt-1 or cnt % 2 == 0){
            tmp = bin / 45;
            bin /= 45;
            ret += charas[tmp];
        }
        ret += charas[bin];
        break;
    case 4:
        cerr << char(bin) << " " << pos << " " << cnt << endl;
        if(bin >= 0x20 and bin <= 0x7e){
            if(bin == '\\' or bin == '#') ret += "\\";
            ret += char(bin);
        }
        else{
            ret += "\\";
            ret += charas[bin/16];
            ret += charas[bin%16];
        }
        break;
    case 8:
        ret += "#";
        ret += charas[bin/4096];
        bin /= 4096;
        ret += charas[bin/256];
        bin /= 256;
        ret += charas[bin/16];
        bin /= 16;
        ret += charas[bin];
    }
    return ret;
}

void solve(){
    string bin = numTobin(num);
    vector<int> bins = sectBin(bin);
    string ans = "";
    int cur = 0;
    for(int i = 0; i < bins.size(); i++)
        cerr << bins[i] << endl;
    while(1){
        if(cur >= bins.size()) break;
        if(bins[cur] == 0) break;
        int mode = bins[cur++];
        cerr << "mode " << mode << endl;
        int cnt = bins[cur++];
        switch(mode){
        case 1:
            cnt /= 3;
            break;
        case 2:
            cnt /= 2;
        }
        for(int i = 0; i < cnt; i++, cur++)
            ans += showQR(bins[cur], mode, i, cnt);
    }
    cout << ans.size() << " " << ans << endl;
}

int main()
{
    int P; cin >> P;
    while(P--){
        cin >> N >> num;
        cout << N << " ";
        solve();
    }
    return 0;
}
