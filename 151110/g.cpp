#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define pb push_back
#define all(u) begin(u),end(u)
#define mp make_pair
#define long int64_t

const int N = 50010;

string s, t;

void input() {
    cin >> s >> t;
}

const int P = 4;
const long p[P] = {9973, 10007, 10013, 10000007};
const long mod = 1000000007;
long pow_p[P][N];
void prepare() {
    rep(iii, P) pow_p[iii][0] = 1;
    rep(iii, P) repi(i, 1, N) pow_p[iii][i] = pow_p[iii][i-1] * p[iii] % mod;
}

long sh[P][N], th[P][N];
long get(long (*h)[N], int iii, int a, int b) {
    return (h[iii][b] - h[iii][a] * pow_p[iii][b-a] % mod + mod) % mod;
}

void solve() {
    rep(iii, P) rep(i, s.length()) sh[iii][i+1] = (sh[iii][i] * p[iii] + s[i]) % mod;
    rep(iii, P) rep(i, t.length()) th[iii][i+1] = (th[iii][i] * p[iii] + t[i]) % mod;
    int ans = 0;
    const int k = s.length();
    rep(i, min<int>(k, t.length())+1) {
        bool flag = true;
        rep(iii, P) if (get(sh, iii, k-i, k) != get(th, iii, 0, i)) {
            flag = false;
            break;
        }
        if (flag) ++ans;
    }
    cout << ans << endl;
}

int main() {
    prepare();
    cin.tie(0);
    int _; cin >> _;
    while(_--) {
        input();
        solve();
    }
    return 0;
}
