#include <bits/stdc++.h>
using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) _repi(i,0,n)
#define _repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)

const int N = 10;

int n, len[N][3];
bool dp[1<<N][N][3][3];

void input()
{
    rep(i, n) rep(j, 3) {
        cin >> len[i][j];
    }
}

void solve()
{
    memset(dp, 0, sizeof(dp));
    rep(i, n) rep(a, 3) rep(b, a+1, 3) {
        dp[1<<i][i][a][b] = true;
    }
    int ans = 1;
    rep(S, 1<<n) rep(i, n) if (S>>i & 1) {
        rep(a, 3) rep(b, a+1, 3) {
            if (not dp[S][i][a][b]) continue;
            ans = max(ans, __builtin_popcount(S));
            rep(ni, n) if (~S>>ni & 1) {
                rep(na, 3) rep(nb, na+1, 3) {
                    if ((len[ni][na] <= len[i][a] and len[ni][nb] <= len[i][b]) or
                        (len[ni][nb] <= len[i][a] and len[ni][na] <= len[i][b])) {
                        dp[S|1<<ni][ni][na][nb] = true;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t = 0;
    while (cin >> n, n) {
        cout << "Case " << ++t << ": ";
        input();
        solve();
    }
}
