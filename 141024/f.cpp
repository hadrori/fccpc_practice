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

const int N = 1024;
const int mod = 2552;

int binom[N][N] = {1};

void prepare()
{
    repi(n, 1, N) {
        binom[n][0] = 1;
        repi(k, 1, n + 1) {
            binom[n][k] = binom[n - 1][k - 1] + binom[n - 1][k];
            if (binom[n][k] >= mod) binom[n][k] -= mod;
        }
    }
}

int w, h;

struct rect {
    int a, b, c, d;
    rect() {}
    rect(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
    pair<pair<int, int>, pair<int, int> > get() const {
        return mp(mp(a, b), mp(c, d));
    }
    bool operator <(const rect& t) const {
        return get() < t.get();
    }
    bool operator ==(const rect& t) const {
        return get() == t.get();
    }
};
int q;
rect rects[128];
int tmp[128];

int solve()
{
    int ans = binom[w + h][w];
    rep(i, q) {
        const int a = rects[i].a;
        const int b = rects[i].b;
        const int c = rects[i].c;
        const int d = rects[i].d;
        tmp[i] = binom[a + b][a];
        rep(j, i) {
            const int jc = rects[j].c;
            const int jd = rects[j].d;
            if (jc <= a and jd <= b) {
                tmp[i] -= tmp[j] * binom[a + b - jc - jd][a - jc] % mod;
            }
        }
        tmp[i] = (tmp[i] % mod + mod) % mod;
        ans -= tmp[i] * binom[w + h - c - d][w - c] % mod;
    }
    return (ans % mod + mod) % mod;
}

int main()
{
    prepare();

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> w >> h >> k;
        while (k--) {
            cin >> q;
            rep(i, q) {
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                rects[i] = rect(a, b, c, d);
            }
            sort(rects, rects + q);
            q = unique(rects, rects + q) - rects;
            cout << solve() << endl;
        }
    }

    return 0;
}
