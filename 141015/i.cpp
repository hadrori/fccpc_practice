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
#define repi(i,a,b) for(int i = (int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i = (int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it = (u).begin(); it!=(u).end(); ++it)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef complex<double> point;

const double eps = 1e-8;

inline double dot  (point a, point b) { return real(conj(a) * b); }
inline double cross(point a, point b) { return imag(conj(a) * b); }

struct line {
    point a, b;
    line(point a, point b) : a(a), b(b) {}
};
point crosspointLL(const line& l, const line& m) {
    double p = cross(l.b - l.a, m.b - m.a);
    double q = cross(l.b - l.a, m.a - l.a);
    if (abs(p) < eps and abs(p) < eps) return m.a;
    return m.a - q / p * (m.b - m.a);
}
line bisector(point a, point b) {
    point m = (a + b) / 2.0;
    return line(m, m + (b - a) * point(0, 1));
}

point get()
{
    double x, y;
    cin >> x >> y;
    return point(x, y);
}

point a, b, c;

bool input()
{
    a = get(), b = get(), c = get();
    return cin;
}

const double pi = acos(-1.0);

bool check(double d, int n)
{
    double k = d * n - int(round(d * n / (2.0 * pi))) * 2.0 * pi;
    return abs(k) < 1e-4;
}

void solve()
{
    line l = bisector(a, b);
    line m = bisector(a, c);
    point o = crosspointLL(l, m);

    double th = arg(a - o);
    double p = arg(b - o) - th;
    double q = arg(c - o) - th;
    repi(i, 3, 1001) {
        if (check(p, i) and check(q, i)) {
            cout << i << endl;
            return;
        }
    }
}

int main()
{
    while (input()) solve();

    return 0;
}
