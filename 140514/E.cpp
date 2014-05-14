#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <deque>
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
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const ll INF = 10000000000000;
ll dp[105][10005];

ll solve() {
    int n;
    ll d;
    cin >> n >> d;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    set<ll> st;

    rep(i, n) {
        for(ll j = -n*d; j <= n*d; j += d) st.insert(max(0LL, h[i]+j));
    }

    vector<ll> zip;
    repit(itr, st) zip.pb(*itr);
    int m = zip.size();
    
    rep(i, n+1) rep(j, m) dp[i][j] = INF;
    
    dp[0][h[0]] = 0;
    rep(i, n) {
        rep(j, m) if(zip[j] == h[i]) dp[i+1][j] = dp[i][j];
//      rep(j, m) dp[i+1][j] = min(dp[i+1][j],
//                                 dp[i][j] + abs(zip[j]-h[i]));
        int s = 0, t = 0;
        rep(j, m) {
            while(t < m && abs(zip[t]-j) <= d) {
                t++;
                
            }
        }
        rep(j, m-1) dp[i+1][j+1] = min(dp[i+1][j+1],
                                       dp[i+1][j] + zip[j+1]-zip[j]);
        repd(j, m-1, 1) dp[i+1][j-1] = min(dp[i+1][j-1],
                                           dp[i+1][j] + zip[j]-zip[j-1]);
    }
    
    rep(i, m) if(zip[i] == h[n-1]) return dp[n][i];
}

int main()
{
    int t;
    cin >> t;
    rep(i, t) {
        ll ans = solve();
        if(ans == INF) cout << "impossible" << endl;
        cout << ans << endl;
    }
    return 0;
}
