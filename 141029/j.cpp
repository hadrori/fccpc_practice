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

int binom(int n, int k) {
    int ret = 1;
    rep(i, k) ret *= n - i, ret /= i + 1;
    return ret;
}

inline int nextInt() { int n; scanf("%d", &n); return n; }
inline double nextDouble() { double x; scanf("%lf", &x); return x; }

const int R = 150;
const int N = 10010;

int r;
double p[R][R];
int n, t[N];

double dp[N][R] = {};

void solve()
{
    memset(dp, 0, sizeof(dp));

    rep(i, r) dp[0][i] = 1.0;
    rep(i, n) rep(j, r) {
        double tmp = dp[i][j] * p[j][t[i]];
        dp[i + 1][j] = max(dp[i + 1][j], tmp);
        dp[i + 1][t[i]] = max(dp[i + 1][t[i]], tmp);
    }
    printf("%.8f\n", *max_element(dp[n], dp[n] + r));
}

int main()
{
    int m;
    while (~scanf("%d", &m)) {
        r = binom(m, 3);
        rep(i, r) rep(j, r) p[i][j] = nextDouble();
        n = nextInt();
        rep(i, n) t[i] = nextInt();
        solve();
    }

    return 0;
}
