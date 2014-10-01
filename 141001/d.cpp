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

const int N = 200010;

int n, q, x[N], y[N], ax, ay, bx, by;
int u[N], v[N];

inline int sq(int n) { return n * n; }

void input()
{
    rep(i, n) scanf("%d%d", x + i, y + i);
    scanf("%d%d%d%d%d", &ax, &ay, &bx, &by, &q);
    rep(i, n) {
        u[i] = sq(x[i] - ax) + sq(y[i] - ay);
        v[i] = sq(x[i] - bx) + sq(y[i] - by);
    }
    sort(u, u + n);
    sort(v, v + n);
}

void solve(int r1, int r2)
{
    const int foo = upper_bound(u, u + n, r1 * r1) - u;
    const int bar = upper_bound(v, v + n, r2 * r2) - v;
    const int ans = max(n - (foo + bar), 0);

    cout << ans << endl;
}

int main()
{
    int t = 0;
    while (~scanf("%d", &n) and n) {
        printf("Case %d:\n", ++t);
        input();
        rep(i, q) {
            int r1, r2;
            scanf("%d%d", &r1, &r2);
            solve(r1, r2);
        }
    }

    return 0;
}
