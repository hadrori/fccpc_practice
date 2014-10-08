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

const int N = 200010;

int n, a[N];

void input()
{
    cin >> n;
    rep(i, n) cin >> a[i];
}

int dp[2][N], dp1[N];

void solve()
{
    const int inf = (int) 1e9 + 10;
    fill(dp1, dp1 + N, inf);
    dp[0][0] = 1, dp1[0] = a[0];
    repi(i, 1, n) {
        rep(j, 2) {
            if (a[i] > a[i - 1]) {
                dp[j][i] = dp[j][i - 1] + 1;
            } else {
                dp[j][i] = 1;
            }
        }
        const int pos = lower_bound(dp1, dp1 + n, a[i]) - dp1;
        dp[1][i] = max(dp[1][i], pos + 1);
        dp1[dp[0][i] - 1] = min(dp1[dp[0][i] - 1], a[i]);
    }

    int ans = 0;
    rep(i, n) rep(j, 2) {
        ans = max(ans, dp[j][i]);
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }

    return 0;
}
