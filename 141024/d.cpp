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

int n, len;
char frac[10];

ll num, den;

const int inf = 1e9;

// p / q, r / s
int dfs(int p, int q, int r, int s)
{
    int ans = inf;
    if ((2 * num - 1) * q <= 2 * den * p and 2 * den * p < (2 * num + 1) * q) {
        ans = min(ans, q);
    }
    if ((2 * num - 1) * s <= 2 * den * r and 2 * den * r < (2 * num + 1) * s) {
        ans = min(ans, s);
    }
    if (ans < inf) return ans;

    ll pr = p + r, qs = q + s;
    if (num * qs < den * pr) {
        return dfs(p, q, pr, qs);
    } else {
        return dfs(pr, qs, r, s);
    }
}

void solve()
{
    num = atoi(frac);
    den = 1;
    rep(i, len) den *= 10;

    cout << dfs(0, 1, 1, 1) << endl;
}

int main()
{
    int t = 0;
    char tmp;
    while (cin >> n >> tmp >> frac and n >= 0) {
        cout << "Case " << ++t << ": ";
        len = strlen(frac);
        solve();
    }

    return 0;
}
