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

const int N = 2014;
const int mod = 1000000007;

ll n, d, x;

ll dp[N][N];

void prepare()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    repi(k, 1, N) {
        repi(i, k, N) {
            ll& cur = dp[k][i];
            cur += dp[k][i - 1] + dp[k - 1][i - 1];
            if (i >= x) cur += mod - dp[k - 1][i - x];
            while (cur >= mod) cur -= mod;
        }
    }
}

ll mod_inv(ll n)
{
    return n == 1 ? 1 : mod_inv(mod % n) * (mod - mod / n) % mod;
}

void solve()
{
    ll ans = 0;
    repi(k, 1, min(d, n) + 1) {
        ll tmp = dp[k][n];
        rep(i, k) {
            tmp = tmp * ((d - i) % mod) % mod;
            tmp = tmp * mod_inv(k - i) % mod;
        }
        ans = (ans + tmp) % mod;
    }
    cout << ans << endl;
}

int main()
{
    while (cin >> n >> d >> x and n) {
        prepare();
        solve();
    }

    return 0;
}
