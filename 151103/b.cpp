#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair

#define long int64_t

const int N = 1024;
const long mod = 1000000007;

int n, k, a[N];
long dp[2][N];

void input() {
    cin >> n >> k;
    rep(i, n) cin >> a[i];
}

void solve() {
    int cur = 0, suc = 1;
    fill_n(dp[cur], n + 1, 0);
    dp[cur][count(a, a + n, 1)] = 1;
    rep(t, k) {
        fill_n(dp[suc], n + 1, 0);
        rep(i, n+1) {
            if (i) (dp[suc][i-1] += i * dp[cur][i]) %= mod;
            (dp[suc][i+1] += (n-i) * dp[cur][i]) %= mod;
        }
        swap(cur, suc);
    }
    cout << dp[cur][0] << endl;
}

int main() {
    cout << fixed << setprecision(12);
    int t; cin >> t;
    rep(i,t) {
        cout << "Case #" << i+1 << ": ";
        input();
        solve();
    }
    return 0;
}
