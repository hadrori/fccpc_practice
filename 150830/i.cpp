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

const long K = 65;
const long mod = 1000000007;

long binom[K][K];

void prepare()
{
    rep(i, K) {
        binom[i][0] = 1;
        repi(j, 1, i+1) {
            binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
            if (binom[i][j] >= mod) binom[i][j] -= mod;
        }
    }
}

int n, m, k;

void input() 
{
    cin >> n >> m >> k;
}

long dp[2][1<<8][65];

int solve()
{
    /**/
    int cur = 0, suc = 1;
    rep(S, 1<<m) rep(j, k+1) dp[cur][S][j] = 0;
    dp[cur][1][0] = 1;
    rep(i, n) {
        rep(S, 1<<m) rep(j, k+1) dp[suc][S][j] = 0;
        rep(S, 1<<m) rep(j, k+1) rep(T, 1<<m) {
            int nj = j + __builtin_popcount(T);
            if (nj > k) continue;
            int nS = 0, t = 0;
            rep(k, m) {
                if (S >> k & 1) t = 1;
                if (T >> k & 1) t = 0;
                nS |= t << k;
            }
            dp[suc][nS][nj] += dp[cur][S][j];
            if (dp[suc][nS][nj] >= mod) dp[suc][nS][nj] -= mod;
        }
        swap(cur, suc);
    }
    /*/
    unordered_map<int, int> cur, suc;
    cur.clear();
    cur[1] = 1;
    rep(i, n) {
        suc.clear();
        for (auto p : cur) {
            const int S = p.first & ((1<<m)-1);
            const int j = p.first >> m;
            rep(T, 1<<m) {
                const int nj = j + __builtin_popcount(T);
                if (nj > k) continue;
                int nS = 0, t = 0;
                rep(k, m) {
                    if (S >> k & 1) t = 1;
                    if (T >> k & 1) t = 0;
                    nS |= t << k;
                }
                suc[nS | nj << m] += p.second;
                if (suc[nS | nj << m] >= mod) suc[nS | nj << m] -= mod;
            }
        }
        swap(cur, suc);
    }
    /**/
    long ans = 0;
    rep(S, 1<<(m-1)) rep(j, k+1) {
    /*
    for (auto p : cur) {
        if (p.first >> (m-1) & 1) continue;
    */
        ans += dp[cur][S][j];
        if (ans >= mod) ans -= mod;
    }
    return ans;
}

int main()
{
    prepare();
    cout << '{';
    rep(nn, 9) {
        if (nn) cout << ',';
        cout << '{';
        rep(mm, 9) {
            cerr<<nn<<' '<<mm<<endl;
            if (mm) cout << ',';
            cout << '{';
            rep(kk, 65) {
                if (kk) cout << ',';
                n = nn, m = mm, k = kk;
                cout << solve();
            }
            cout << '}';
        }
        cout << '}';
    }
    cout << '}';
    return 0;
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        input();
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}
