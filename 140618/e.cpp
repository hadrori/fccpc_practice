#include <algorithm>
#include <bitset>
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

// constants and eps-considered operators

const double eps = 1e-8; // choose carefully!
const double pi = acos(-1.0);

inline bool lt(double a, double b) { return a < b - eps; }
inline bool gt(double a, double b) { return lt(b, a); }
inline bool le(double a, double b) { return !lt(b, a); }
inline bool ge(double a, double b) { return !lt(a, b); }
inline bool ne(double a, double b) { return lt(a, b) or lt(b, a); }
inline bool eq(double a, double b) { return !ne(a, b); }

// points and lines

typedef complex<double> point;

inline double dot(point a, point b)   { return real(conj(a) * b); }
inline double cross(point a, point b) { return imag(conj(a) * b); }

struct line {
    point a, b;
    line(point a, point b) : a(a), b(b) {}
};

/*
 *  Here is what ccw(a, b, c) returns:
 *
 *          1
 *  ------------------
 *    2 |a  0  b| -2
 *  ------------------
 *         -1
 *
 *  Note: we can implement intersectPS(p, s) as !ccw(s.a, s.b, p).
 */
int ccw(point a, point b, point c) {
    b -= a, c -= a;
    if (gt(cross(b, c), 0.0)) return +1;
    if (lt(cross(b, c), 0.0)) return -1;
    if (lt(dot(b, c), 0.0))   return +2; // c -- a -- b
    if (lt(norm(b), norm(c))) return -2; // a -- b -- c
    return 0;
}
bool intersectLS(const line& l, const line& s) {
    return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) <= 0;
}
bool intersectSS(const line& s, const line& t) {
    return intersectLS(s, t) and intersectLS(t, s);
}

point proj(const line& l, point p) {
    double t = dot(l.b - l.a, p - l.a) / norm(l.b - l.a);
    return l.a + t * (l.b - l.a);
}
double distancePS(point p, const line& s) {
    point h = proj(s, p);
    return ccw(s.a, s.b, h) ? min(abs(s.a - p), abs(s.b - p)) : abs(h - p);
}
double distanceSS(line &s, line &t) {
    return intersectSS(s, t) ? 0.0 :
        min(min(distancePS(s.a, t), distancePS(s.b, t)),
            min(distancePS(t.a, s), distancePS(t.b, s)));
}

int n;
point s, e;
vector<point> a;
vector<double> h;

point in() { double x, y; cin >> x >> y; return point(x, y); }

void input()
{
    a.clear(), h.clear();

    s = in(), e = in();
    rep(i, n) {
        double ax, ay, bx, by, tmp;
        cin >> ax >> ay >> bx >> by >> tmp;
        a.pb(point(ax, ay));
        a.pb(point(ax, by));
        a.pb(point(bx, by));
        a.pb(point(bx, ay));
        h.pb(tmp);
    }
}

bool check()
{
    line l(s, e);
    rep(i, n) rep(j, 4) {
        line w(a[4 * i + j], a[4 * i + (j + 1) % 4]);
        if (intersectSS(l, w)) return false;
    }

    return true;
}

double f(double h, double d)
{
    if (h >= d) return d;

    return (h * h + d * d) / (2 * h);
}

double solve()
{
    if (not check()) return 0.0;

    line l(s, e);

    double ans = 1000.0;
    rep(i, n) rep(j, 4) {
        line w(a[4 * i + j], a[4 * i + (j + 1) % 4]);
        // cout << w.a << ' ' << w.b << endl;
        ans = min(ans, f(h[i], distanceSS(w, l)));

        double mx = real(a[4 * i]);
        double my = imag(a[4 * i]);
        double Mx = real(a[4 * i + 2]);
        double My = imag(a[4 * i + 2]);
        if (mx <= real(s) and real(s) <= Mx and my <= imag(s) and imag(s) <= My) ans = 0.0;
        if (mx <= real(e) and real(e) <= Mx and my <= imag(e) and imag(e) <= My) ans = 0.0;
    }
    return ans;
}

int main()
{
    while (cin >> n and n) {
        input();
        printf("%.11f\n", solve());
    }

    return 0;
}
