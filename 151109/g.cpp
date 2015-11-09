#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define long int64_t

int n, m;
const int MAX = 4096;
int c[MAX][MAX];
int a[MAX][MAX];
int dp[4][MAX][MAX];
int llim[MAX];
int rlim[MAX];
void input() {
    cin >> n >> m;
    rep(i, n) rep(j, n) cin >> c[i][j];
    
    rep(i, n) rep(j, n) c[i+1][j] += c[i][j];
    rep(i, n) rep(j, n) c[i][j+1] += c[i][j];

    rep(i, n) rep(j, n) {
        a[i][j+1] = c[j][j];
        if (i > 0) {
            a[i][j+1] -= c[i-1][j] * 2;
            a[i][j+1] += c[i-1][i-1];
        }
        a[i][j+1] /= 2;
    }
}

void solve() {
    const int inf = 200000000;
    int now = 0, nxt = 1, mine = 2, nmine = 3;
    rep(i, 3) rep(j, n) rep(k, n+1) dp[i][j][k] = inf;
    rep(i, n+1) dp[mine][i][i] = 0;
    rep(i, n) repi(j, i, n+1) dp[now][i][j] = a[i][j];
    
    rep(level, 10) {
        rep(i, n) rep(j, n+1) dp[nxt][i][j] = inf;
        
        rep(i, n+1) llim[i] = 0;
        rep(i, n+1) rlim[i] = n;
        const int r = 0;
        // renew nxt
        rep(i, n) repi(j, i+1, n+1) {
            repi(k, max(i, llim[i]), min(rlim[j], j)+1) {
                if (dp[nxt][i][j] > dp[now][i][k] + dp[now][k][j]) {
                    //cout << i << " " << j << " " << k << endl;
                    dp[nxt][i][j] = dp[now][i][k] + dp[now][k][j];
                    rlim[j] = min(rlim[j], k+r);
                    llim[i] = max(llim[i], k-r);
                }
            }
        }

        if ((m >> level)&1) {
            rep(i, n+1) llim[i] = 0;
            rep(i, n+1) rlim[i] = n;
            rep(i, n) rep(j, n+1) dp[nmine][i][j] = inf;
            
            // renew mine
            rep(i, n) repi(j, i+1, n+1) {
                repi(k, max(i, llim[i]), min(rlim[j], j)+1) {
                    if (dp[nmine][i][j] > dp[mine][i][k] + dp[now][k][j]) {
                        dp[nmine][i][j] = dp[mine][i][k] + dp[now][k][j];
                        //cout << i << " " << j << " " << k << " " << dp[mine][i][k] << " " << dp[now][k][j] << " " << dp[nmine][i][j] << endl;
                        rlim[j] = min(rlim[j], k+r);
                        llim[i] = max(llim[i], k-r);
                    }
                }
            }            
            /*
            cout << "mine" << endl;
            rep(i, n) {
                rep(j, n) cout << dp[nmine][i][j] << " ";
                cout << endl;
                }*/
            swap(mine, nmine);
        }
        /*
        cout << level << endl;
        rep(i, n) {
            rep(j, n) cout << dp[now][i][j] << " ";
            cout << endl;
        }
        */
        swap(now, nxt);
    }

    cout << dp[mine][0][n] << endl;
}

int main() {
    cin.tie(0);
    input();
    solve();
    return 0;
}
