#include <bits/stdc++.h>
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

int n, d, x, p[10][10];

void input()
{
    cin >> n >> d >> x;
    rep(i, d) rep(j, n) {
        cin >> p[i][j];
    }
}

const int K = 100010;

int dp[10][11][K] = {};

void solve()
{
    rep(i, 10) rep(j, 11) rep(k, K) {
        dp[i][j][k] = k;
    }

    repi(gap, 1, d + 1) rep(a, d - gap + 1) {
        const int b = a + gap;
        rep(k, K) {
            int& cur = dp[a][b][k];
            rep(i, n) if (k >= p[a][i]) {
                cur = max(cur, dp[a][b][k - p[a][i]] + p[b][i]);
            }
            repi(i, a + 1, b) {
                cur = max(cur, dp[i][b][min(dp[a][i][k], K)]);
            }
        }
    }

    cout << dp[0][d][x] << endl;
}

int main()
{
    input();
    solve();

    return 0;
}
