#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

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

const int N = 100010;

int n;
double p[N], opt[N];

void solve()
{
    double ans = 0.0;
    int prev = 0;
    for (int i = 1; i <= n; ++i) {
        const double save = (opt[i - 1] - opt[prev]) + 1.0 + 1.0 / p[i - 1];
        const double dont = ((opt[i - 1] - opt[prev]) + 1.0) / p[i - 1];

        opt[i] = min(save, dont);
        if (save < dont) {
            opt[i] -= opt[i - 1];
            ans += opt[i - 1];
            prev = i - 1;
        }
    }
    printf("%.10f\n", ans + opt[n]);
}

int main()
{
    while (cin >> n and n) {
        rep(i, n) cin >> p[i];
        solve();
    }

    return 0;
}
