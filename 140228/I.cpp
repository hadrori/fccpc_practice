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

int T, N, M;
char table[64][64];
bool mask[64][64];
vector<string> pattern;
string gen[4];

void init(){
    pattern.clear();
}

void input(){
    cin >> N;
    rep(i,N)rep(j,N)
        cin >> table[i][j];
    rep(i,N)rep(j,N){
        char c; cin >> c;
        mask[i][j] = (c == '*');
    }
    cin >> M;
    rep(i,M){
        string str; cin >> str;
        pattern.push_back(str);
    }
}

struct PMA{
    PMA *next[256];
    int matched;
    ~PMA(){rep(i,256)if(next[i])delete next[i];}
    PMA(){ memset(next, 0, sizeof(next)); matched = -1;}
};

PMA *buildPMA(){
    PMA *root = new PMA, *now;
    rep(i,pattern.size()){
        now = root;
        rep(j,pattern[i].size()){
            if(!now->next[int(pattern[i][j])]) now->next[int(pattern[i][j])] = new PMA;
            now = now->next[int(pattern[i][j])];
        }
        now->matched = i;
    }
    return root;
}

string elim(string str){
    int cur = 0;
    while(cur < str.size() && str[cur] == ' ') cur++;
    return str.substr(cur);
}

bool matched(PMA *root, string str, vector<int> &res){
    PMA *pma = root;
    bool prev = 1;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            if(!prev) return 0;
            res.pb(pma->matched);
            while(str[i] == ' ') i++;
            prev = 0;
            pma = root;
            if(i == str.size()) return 1;
        }

        int c = int(str[i]);
        if(!pma->next[c]) return 0;
        pma = pma->next[c];
        if(pma->matched >= 0) prev = 1;
    }
    return 1;
}

void rotate(){
    bool tmask[64][64];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            tmask[j][N-i-1] = mask[i][j];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            mask[i][j] = tmask[i][j];
}

string solve(){
    for(int i = 0; i < 4; i++){
        string str = "";
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(mask[i][j]){
                    if(table[i][j] == '.') str.pb(' ');
                    else str.pb(table[i][j]);
                }
        rotate();
        gen[i] = str;
    }
    PMA *root = buildPMA();
    string ans = "";
    bool exist = 0;
    for(int i = 0; i < 4; i++){
        string str = "";
        for(int j = 0; j < 4; j++)
            str += gen[(i+j)%4];
        str += " ";
        while(str[0] == ' ') str = str.substr(1);
        vector<int> res;
        if(matched(root,str,res)){
            string tmp = "";
            exist = 1;
            rep(k,res.size()){
                tmp += pattern[res[k]];
                if(k < res.size()-1) tmp += " ";
            }
            if(ans.size() == 0) ans = tmp;
            else {
                ans = min(ans, tmp);
            }
        }
    }
    if(!exist) return "FAIL TO DECRYPT";
    else return ans;
}

int main()
{
    cin >> T;
    for(int i = 0; i < T; i++){
        init();
        input();
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}
