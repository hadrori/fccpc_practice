#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 200;

int n, m, a[N];

void input()
{
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    sort(a, a + n);
}

const int inf = 1000000010;
int dp[N][N] = {};

void solve()
{
    rep(i, N) rep(j, N) dp[i][j] = inf;
    dp[0][0] = 0;
    rep(i, n) rep(j, i + 1) rep(k, n) {
        dp[i + 1][k + 1] = min(dp[i + 1][k + 1], dp[j][k] + a[i] - a[j]);
    }
    cout << dp[n][m] << endl;
}

int main()
{
    int t;
    cin >> t;
    rep(i, t) {
        input();
        cout << "Case #" << i + 1 << ": "; 
        solve();
    }

    return 0;
}
