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

const int N = 50010;

int d, n, a[N];
int dp[1000010];

void solve()
{
    rep(i, n) a[i] %= d;
    repi(i, 1, n) {
        a[i] += a[i - 1];
        if (a[i] >= d) a[i] -= d;
    }

    fill(dp, dp + d, 0);
    dp[0] = 1;

    ll ans = 0;
    rep(i, n) {
        ans += dp[a[i]];
        ++dp[a[i]];
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> d >> n;
        rep(i, n) cin >> a[i];
        solve();
    }

    return 0;
}
