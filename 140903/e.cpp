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

int n;
vector<int> root;
vector<vector<int> > G;

void input()
{
    cin >> n;
    root.assign(n, 1);
    G.assign(n, vector<int>());
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        root[b] = 0;
    }
}

const int N = 210;
const ll mod = 1000000007;

ll binom_[N][N] = {1};

void prepare()
{
    repi(i, 1, N) {
        binom_[i][0] = 1;
        repi(j, 1, i + 1) {
            binom_[i][j] = binom_[i - 1][j - 1] + binom_[i - 1][j];
            if (binom_[i][j] >= mod) binom_[i][j] -= mod;
        }
    }
}

ll binom(int n, int k)
{
    return 0 <= k and k <= n ? binom_[n][k] : 0;
}

ll dp[N][N] = {};

void recur(int v)
{
    if (G[v].empty()) {
        rep(i, N) dp[v][i] = 0;
        dp[v][1] = 1;
        return;
    }

    rep(i, int(G[v].size())) recur(G[v][i]);

    repi(k, 1, n + 1) {
        ll& ret = dp[v][k] = 1;
        rep(i, int(G[v].size())) {
            ll tmp = 0;
            repi(ck, 1, n + 1) {
                tmp += binom(k - 1, ck) * dp[G[v][i]][ck] % mod;
                if (tmp >= mod) tmp -= mod;
            }
            ret = ret * tmp % mod;
        }
    }

    repi(k, 1, n + 1) repi(i, 1, k) {
        dp[v][k] = ((dp[v][k] - binom(k - 1, i - 1) * dp[v][i]) % mod + mod) % mod;
    }
}

void solve()
{
    prepare();

    rep(i, n) if (root[i]) recur(i);

    ll ans = 0;
    rep(i, n) if (root[i]) {
        repi(j, 1, n + 1) {
            ans += dp[i][j];
            if (ans >= mod) ans -= mod;
        }
    }
    cout << ans << endl;
}

int main()
{
    input();
    solve();

    return 0;
}
