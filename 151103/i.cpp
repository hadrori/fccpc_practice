#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair

const int N = 512;
const int K = 8;

#define ulong uint64_t

int n, m;
char field[N][N];
ulong gs[N][K], ls[N][K];

void input() {
    cin >> n >> m;
    rep(i, n) cin >> field[i];
    rep(i, n) {
        fill_n(gs[i], K, 0);
        fill_n(ls[i], K, 0);
    }
    rep(i, n) rep(j, m) {
        if (field[i][j] == 'G') {
            gs[i][j>>6] |= 1ULL << (j&63);
        } else {
            ls[i][j>>6] |= 1ULL << (j&63);
        }
    }
}

int a, b;
char small[N][N];
ulong gs1[N][K], ls1[N][K];

void solve() {
    rep(i, a) {
        fill_n(gs1[i], K, 0);
        fill_n(ls1[i], K, 0);
    }
    rep(i, a) rep(j, b) {
        if (small[i][j] == 'G') {
            gs1[i][j>>6] |= 1ULL << (j&63);
        } else {
            ls1[i][j>>6] |= 1ULL << (j&63);
        }
    }
    pair<int,int> ans1 = {-1, -1};
    pair<int,int> ans = {n, n};
    int best = -1;
    rep(q, m-b+1) {
        rep(p, n-a+1) {
            int gcc = 0, lcc = 0;
            rep(i, a) rep(j, K) {
                gcc += __builtin_popcountll(gs[i+p][j] & gs1[i][j]);
                lcc += __builtin_popcountll(ls[i+p][j] & ls1[i][j]);
            }
            int acc = gcc + lcc;
            if (acc > best) {
                best = acc;
                ans = {p+1, q+1};
                ans1 = {gcc, lcc};
            } else if (acc == best) {
                ans = min(ans, mp(p+1, q+1));
                ans1 = {gcc, lcc};
            }
        }
        rep(i, a) {
            for (int j = K-1; j >= 0; --j) {
                if (j < K-1) {
                    gs1[i][j+1] |= gs1[i][j]>>63;
                    ls1[i][j+1] |= ls1[i][j]>>63;
                }
                gs1[i][j] <<= 1;
                ls1[i][j] <<= 1;
            }
        }
    }
    static int cnt = 0;
    cout << "Case #" << ++cnt << ": ";
    cout << ans.first << ' ' << ans.second << ' ' << ans1.first << ' ' << ans1.second << endl;
}

int main() {
    cout << fixed << setprecision(12);
    input();
    int t;
    for (cin >> t; t--; ) {
        cin >> a >> b;
        rep(i, a) cin >> small[i];
        solve();
    }
    return 0;
}
