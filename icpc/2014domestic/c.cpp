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

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define repd(i,a,b) for(int i=int(a);i>=int(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 100;
const int base = 50;

int r, n, h[N];

void input()
{
    memset(h, 0, sizeof(h));

    rep(i, n) {
        int l, r, hi;
        cin >> l >> r >> hi;
        repi(j, l, r) {
            h[base + j] = max(h[base + j], hi);
        }
    }
}

void solve()
{
    double ans = 1e9;
    for (int i = -r; i < r; ++i) {
        int a = i;
        if (a < 0) ++a;
        a = abs(a);
        double pre = r - sqrt((double) (r * r - a * a));
        ans = min(ans, pre + h[i + base]);
    }
    printf("%.4f\n", ans);
}

int main()
{
    while (cin >> r >> n and r) {
        input();
        solve();
    }

    return 0;
}
