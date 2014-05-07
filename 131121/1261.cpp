#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>

#define repi(i,a,b) for(int i = int(a); i < int(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = int(a); i >= int(b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);

using namespace std;

typedef long long ll;

const int N = 6;

int n;
double room, a[6], sum[1 << N];

void input()
{
    cin >> room >> n;
    rep(i, n) cin >> a[i];

    sum[0] = 0.0;
    rep(i, n) sum[1 << i] = a[i];
    rep(i, 1 << n) if (__builtin_popcount(i) >= 2)
        sum[i] = sum[i & -i] + sum[i & i - 1];
}

typedef pair<double, double> P;

vector<set<P> > dp;

void solve()
{
    dp.assign(1 << n, set<P>());

    rep(i, n) dp[1 << i].insert(P(0.0, 0.0));
    rep(s, 1 << n) if (__builtin_popcount(s) >= 2) {
        for (int t = s; t = t - 1 & s; ) {
            double r = sum[t] / sum[s], l = 1.0 - r;
            repit(ii, dp[t]) repit(jj, dp[s ^ t]) {
                dp[s].insert(P(max(l + ii->first, jj->second - r),
                               max(r + jj->first, ii->second - l)));
                dp[s].insert(P(max(l + ii->first, jj->first - r),
                               max(r + jj->second, ii->second - l)));
                dp[s].insert(P(max(l + ii->second, jj->second - r),
                               max(r + jj->first, ii->first - l)));
                dp[s].insert(P(max(l + ii->second, jj->first - r),
                               max(r + jj->second, ii->first - l)));
            }
        }
    }

    double ans = -1.0;
    repit(it, dp[(1 << n) - 1])
        if (it->first + it->second <= room)
            ans = max(ans, it->first + it->second);

    if (ans >= 0.0)
        printf("%.16f\n", ans);
    else
        puts("-1");
}

signed main()
{
    int T; cin >> T;
    while (T--) {
        input();
        solve();
    }

    return 0;
}
