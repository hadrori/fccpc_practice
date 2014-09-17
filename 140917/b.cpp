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

using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;
int n, m, q;

char conv(int num) {
    if(num < 10) return '0' + num;
    return (char)('A'+num-10);
}

void solve() {
    vector<string> S(q), B(q);
    rep(i, q) cin >> S[i] >> B[i];
    if(q == 0) {
        if(n == 1) {
            rep(i, m) cout << 0;
            cout << endl;
        } else {
            rep(i, m) cout << '?';
            cout << endl;
        }
        return;
    }
    
    // state
    vector<string> state(q);
    state[0] = S[0];
    rep(i, q-1) {
        state[i+1] = state[i];
        rep(j, n) {
            if(S[i+1][j] == '1') {
                if(state[i+1][j] == '1') state[i+1][j] = '0';
                else state[i+1][j] = '1';
            }
        }
    }

    map<string, int> table;
    set<string> dbl;
    rep(i, n) {
        string ts = "";
        rep(j, q) ts += state[j][i];
        if(table.find(ts) != table.end()) {
            dbl.insert(ts);
        }
        table[ts] = i;
    }

    rep(i, m) {
        string ts = "";
        rep(j, q) ts += B[j][i];
        if(dbl.find(ts) != dbl.end()) cout << '?';
        else cout << conv(table[ts]);
    }
    cout << endl;
}
int main()
{
    while(cin >> n >> m >> q, n or m or q) {
        solve();
    }
    return 0;
}
