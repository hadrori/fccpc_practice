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

const int N = 1280;

int n, m;
double c[N], w[N];

void input()
{
    cin >> n >> m;
    rep(i, n) cin >> c[i], c[i] /= 100.0;
    rep(i, n) cin >> w[i], w[i] /= 100.0;
}

double dp[N][N][2];

void solve()
{
    rep(i, N) rep(j, N) {
        dp[i][j][0] = 1.0;
        dp[i][j][1] = -1.0;
    }
    rep(i, 2) dp[0][0][i] = 1.0;
    rep(i, n) rep(j, m+1) {
        if (dp[i][j][1] < -0.5) continue;
        // set correct
        {
            const double cc = 1.0 - w[i];
            const double ww = w[i];
            rep(k, 2) {
                dp[i+1][j][0] = min(dp[i+1][j][0],
                                    cc * dp[i][j][k] + ww * (1.0 - dp[i][j][k]));
                dp[i+1][j][1] = max(dp[i+1][j][1],
                                    cc * dp[i][j][k] + ww * (1.0 - dp[i][j][k]));
            }
        }
        // set wrong
        {
            const double cc = c[i];
            const double ww = 1.0 - c[i];
            rep(k, 2) {
                dp[i+1][j+1][0] = min(dp[i+1][j+1][0],
                                      cc * dp[i][j][k] + ww * (1.0 - dp[i][j][k]));
                dp[i+1][j+1][1] = max(dp[i+1][j+1][1],
                                      cc * dp[i][j][k] + ww * (1.0 - dp[i][j][k]));
            }
        }
    }
    double p = dp[n][0][0];
    rep(i, m + 1) p = min(p, dp[n][i][0]);
    double ans = 30000.0 * p - 15000.0;
    printf("%.3f\n", ans);
}

int main()
{
    int t;
    cin >> t;
    rep(i, t) {
        input();
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
