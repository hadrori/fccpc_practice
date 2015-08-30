#include <bits/stdc++.h>
using namespace std;

#define repi(i,a,b) for(int i = (int)(a); i<(int)(b); ++i)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 2000010;
const int mod = 997;

ll fact[mod], inv[mod];
void prepare() {
    fact[0] = 1;
    repi(i, 1, mod) {
        fact[i] = fact[i-1] * i % mod;
    }
    inv[1] = 1;
    repi(i, 2, mod) {
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
}
ll mod_fact(ll n, ll m, ll& e) {
    e = 0;
    if (n == 0) return 1;
    ll ret = mod_fact(n / m, m, e);
    e += n / m;
    return ret * (n / m % 2 ? m - fact[n % m] : fact[n % m]) % m;
}
ll mod_binom(ll n, ll k) {
    if (k < 0 or n < k) return 0;
    ll e1, e2, e3;
    ll a1 = mod_fact(n, mod, e1);
    ll a2 = mod_fact(k, mod, e2);
    ll a3 = mod_fact(n-k, mod, e3);
    if (e1 > e2 + e3) return 0;
    return a1 * inv[a2 * a3 % mod] % mod;
}
inline ll grid(int a, int b) { return mod_binom(a + b, a); }

int n, m, k;
vector<pair<int, int>> ps;

void input()
{
    cin >> n >> m >> k;
    ps.clear();
    rep(_, k) {
        int x, y;
        cin >> x >> y;
        rep(dx, 3) rep(dy, 3) {
            ps.emplace_back(x-dx, y-dy);
        }
    }
    ps.emplace_back(n-1, m-1);
    sort(all(ps));
}

int solve()
{
    const int s = ps.size();
    vector<ll> dp(s);
    rep(i, s) {
        dp[i] = grid(ps[i].first, ps[i].second);
        rep(j, i) {
            dp[i] += mod - dp[j] * grid(ps[i].first - ps[j].first, ps[i].second - ps[j].second) % mod;
            if (dp[i] >= mod) dp[i] -= mod;
        }
    }
    return dp.back();
}

int main()
{
    prepare();
    
    int t;
    cin >> t;
    rep(i, t) {
        input();
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}
