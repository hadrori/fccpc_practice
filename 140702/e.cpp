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

int main()
{
    int n, a, s, g;
    while(cin >> n >> a >> s >> g, n || a || s || g) {
        // input
        vector<vector<pair<int , string> > >E(n);
        rep(i, a) {
            int from, to;
            string str;
            cin >> from >> to >> str;
            E[from].pb(mp(to, str));
        }

        // init
        vector<bool> done(n);
        vector<string> dp(n);
        rep(i, n) dp[i] = "";
        done[g] = true;

        // calc
        rep(_, 250) {
            rep(from, n) rep(i, E[from].size()) {
                int to = E[from][i].first;
                if(done[to] && (!done[from] || E[from][i].second + dp[to] < dp[from])) {
                    dp[from] = E[from][i].second + dp[to];
                    done[from] = true;
                }
            }
        }

        
        // output
        if(dp[s] == "" or dp[s].size() > 241) cout << "NO" << endl;
        else cout << dp[s] << endl;
        
    }

    return 0;
}
