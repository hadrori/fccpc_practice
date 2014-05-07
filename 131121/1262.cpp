#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>

#define repi(i,a,b) for(int i = int(a); i < int(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = int(a); i >= int(b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);

using namespace std;

typedef long long ll;

const int N = 128;
const int M = 10010;

int n, a[N], r;
double b, v, e, f;

void input()
{
    rep(i, n) cin >> a[i + 1];
    cin >> b >> r >> v >> e >> f;
}

double t[M];

void gen()
{
    t[0] = 0.0;
    rep(i, M - 1)
        t[i + 1] = t[i] + 1.0 / (v - (i >= r ? e * (i - r) : f * (r - i)));
}

const double inf = 1e9;

double dp[N];

void solve()
{
    dp[0] = 0.0;
    fill(dp + 1, dp + n + 1, inf);

    repi(i, 1, n + 1) rep(j, i)
        dp[i] = min(dp[i], dp[j] + (j ? b : 0) + t[a[i] - a[j]]);
    printf("%.4f\n", dp[n]);
}

signed main()
{
    while (cin >> n && n) {
        input();
        gen();
        solve();
    }

    return 0;
}
