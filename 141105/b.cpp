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
#define int ll
const int N = 50010;

int n, m, d, a[N], b[N];

void input()
{
    cin >> n >> m >> d;
    rep(i, n) cin >> a[i];
    a[n++] = 100000000;
    rep(i, m) cin >> b[i];
}

const int D = 300;
const int mod = 1000000009;

int dp[N][D], pl, pr;

int ans;
//const int LIM = 1000000;
void dfs(int i, int j) {
    if(i == n or j == m) ans++;
    else if((a[i] <= b[j] and b[j] < a[i]+d) or
            (b[j] <= a[i] and a[i] < b[j]+d)) {
        dfs(i+1, j);
        dfs(i, j+1);
    } else if(a[i] < b[j]) dfs(i+1, j);
    else dfs(i, j+1);
    
}
int solve_naive() {
    ans = 0;
    dfs(0, 0);
    cout << "naive " << ans << endl;
    return ans;
}

int solve()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    pl = 0, pr = 1;
    rep(i, m) {
        int l = pl, r = pr;
        while (l < n and a[l] + d <= b[i]) ++l;
        while (r - 1 < n and a[r - 1] < b[i] + d) ++r;
        rep(j, r - l) {
            dp[i + 1][j] = dp[i][min(j + l - pl, pr - pl - 1)];
        }
        repi(j, 1, r - l) {
            dp[i + 1][j] += dp[i + 1][j - 1];
            if (dp[i + 1][j] >= mod) dp[i + 1][j] -= mod;
        }
        pl = l, pr = r;
    }
    cout << dp[m][pr - pl - 1] << endl;
    return dp[m][pr - pl - 1];
}

signed main()
{
    int t;
    cin >> t;
    rep(i, t) {
        input();
        cout << "Case #" << i + 1 << ": ";
        solve();
        //assert(solve() == solve_naive());
    }

    return 0;
}
