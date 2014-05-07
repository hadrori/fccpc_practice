#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>ago
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double eps = 1e-8;

bool lt(double a, double b) { return a < b - eps; }
bool eq(double a, double b) { return !lt(a, b) and !lt(b, a); }

typedef complex<double> P;

struct L
{
    P a, b;
    L(const P &a, const P &b) : a(a), b(b) {}
};

double cross(const P &a, const P &b)
{
    return imag(conj(a) * b);
}

P cp(const L &l, const L &m)
{
    double A = cross(l.b - l.a, m.b - m.a);
    double B = cross(l.b - l.a, l.b - m.a);
    return m.a + B / A * (m.b - m.a);
}

double bx, cx, cy, dx, dy;

P a, b, c, d, a1, b1, c1, d1;

double area(P p, P q, P r)
{
    q -= p;
    r -= p;
    return cross(q, r) / 320.0;
}

void solve()
{
    a = P(0.0, 0.0);
    b = P(bx, 0.0);
    c = P(cx, cy);
    d = P(dx, dy);

    L l1(a, (b + c) / 2.0);
    L l2(b, (c + d) / 2.0);
    L l3(c, (d + a) / 2.0);
    L l4(d, (a + b) / 2.0);

    a1 = cp(l1, l2);
    b1 = cp(l2, l3);
    c1 = cp(l3, l4);
    d1 = cp(l4, l1);

    cout.setf(ios::fixed);
    cout.precision(3);

    cout << area(a, b, a1) << ' ';
    cout << area(b, c, b1) << ' ';
    cout << area(c, d, c1) << ' ';
    cout << area(d, a, d1) << ' ';
    cout << area(a1, b1, c1) + area(c1, d1, a1) << ' ';

    double l = 0.0;
    l += abs(b1 - a1);
    l += abs(c1 - b1);
    l += abs(d1 - c1);
    l += abs(a1 - d1);
    cout << int(ceil(16.5 * l)) << endl;
}

int main()
{
    int P;
    cin >> P;
    rep(i, P) {
        int N;
        cin >> N >> bx >> cx >> cy >> dx >> dy;
        cout << i + 1 << ' ';
        solve();
    }

    return 0;
}
