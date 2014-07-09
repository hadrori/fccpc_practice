#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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
#include <sstream>

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int T, n, m;
vector<int> S;
void input() {
    cin >> n >> m;
    cin.ignore();
    //cout << n << " " << m << endl;
    S.clear();
    S.resize(m);
    rep(i, m) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int tmp;
        while(ss >> tmp) {
            S[i] |= 1 << (tmp-1);
        }
    }
    /*
    rep(i, m) {
        cout << bitset<10>(S[i]) << endl;
        }*/
}

bool solve() {
    vector<int> num(m);
    rep(i, m) {
        num[i] = __builtin_popcount(S[i]);
        //if(num[i] == 0) return false;
    }
    
    rep(bits, 1<<n) {
        bool ok = true;
        rep(i, m) {
            int cnt = __builtin_popcount(bits&S[i]);
            if(cnt == 0 or cnt == num[i]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            //cout << bitset<10>(bits) << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> T;
    while(T--) {
        input();
        if(solve()) cout << 'Y';
        else cout << 'N';
    }
    cout << endl;
    return 0;
}
