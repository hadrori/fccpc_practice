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

inline double dot  (point a, point b) { return real(conj(a) * b); }
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
    if (cross(b, c) > eps)    return +1;
    if (cross(b, c) < eps)    return -1;
    if (dot(b, c) < eps)      return +2; // c -- a -- b
    if (lt(norm(b), norm(c))) return -2; // a -- b -- c
    return 0;
}
bool intersectLS(const line& l, const line& s) {
    return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) <= 0;
}
bool intersectSS(const line& s, const line& t) {
    return intersectLS(s, t) and intersectLS(t, s);
}
bool intersectLL(const line& l, const line& m) {
    return ne(cross(l.b - l.a, m.b - m.a), 0.0)  // not parallel
        or eq(cross(l.b - l.a, m.a - l.a), 0.0); // overlap
}
point crosspointLL(const line& l, const line& m) {
    double A = cross(l.b - l.a, m.b - m.a);
    double B = cross(l.b - l.a, m.a - l.a);
    if (eq(A, 0.0) and eq(B, 0.0)) return m.a; // overlap
    assert(ne(A, 0.0));                        // not parallel
    return m.a - B / A * (m.b - m.a);
}
point proj(const line& l, point p) {
    double t = dot(l.b - l.a, p - l.a) / norm(l.b - l.a);
    return l.a + t * (l.b - l.a);
}
point reflection(const line& l, point p) { return 2.0 * proj(l, p) - p; }

// distances (for shortest path)

double distanceLP(const line& l, point p) { return abs(proj(l, p) - p); }
double distanceLL(const line& l, const line& m) {
    return intersectLL(l, m) ? 0.0 : distanceLP(l, m.a);
}
double distanceLS(const line& l, const line& s) {
    return intersectLS(l, s) ? 0.0 : min(distanceLP(l, s.a), distanceLP(l, s.b));
}
double distancePS(point p, const line& s) {
    point h = proj(s, p);
    return ccw(s.a, s.b, h) ? min(abs(s.a - p), abs(s.b - p)) : abs(h - p);
}
double distanceSS(const line& s, const line& t) {
    if (intersectSS(s, t)) return 0.0;
    return min(min(distancePS(s.a, t), distancePS(s.b, t)),
               min(distancePS(t.a, s), distancePS(t.b, s)));
}

// circles

struct circle {
    point o; double r;
    circle(point o, double r) : o(o), r(r) {}
};

bool intersectCL(const circle& c, const line& l) {
    return le(norm(proj(l, c.o) - c.o), c.r * c.r);
}
int intersectCS(const circle& c, const line& s) {
    if (not intersectCL(c, s)) return 0;
    double a = abs(s.a - c.o);
    double b = abs(s.b - c.o);
    if (lt(a, c.r) and lt(b, c.r)) return 0;
    if (lt(a, c.r) or lt(b, c.r)) return 1;
    return ccw(s.a, s.b, proj(s, c.o)) ? 0 : 2;
}
bool intersectCC(const circle& c, const circle& d) {
    double dist = abs(d.o - c.o);
    return le(abs(c.r - d.r), dist) and le(dist, c.r + d.r);
}
line crosspointCL(const circle& c, const line& l) {
    point h = proj(l, c.o);
    double a = sqrt(c.r * c.r - norm(h - c.o));
    point d = a * (l.b - l.a) / abs(l.b - l.a);
    return line(h - d, h + d);
}
line crosspointCC(const circle& c, const circle& d) {
    double dist = abs(d.o - c.o), th = arg(d.o - c.o);
    double ph = acos((c.r * c.r + dist * dist - d.r * d.r) / (2.0 * c.r * dist));
    return line(c.o + polar(c.r, th - ph), c.o + polar(c.r, th + ph));
}

line tangent(const circle& c, double th) {
    point h = c.o + polar(c.r, th);
    point d = polar(c.r, th) * point(0, 1);
    return line(h - d, h + d);
}

int main()
{
    double Rm, R, r, x, y, vx, vy;
    while(cin >> Rm >> R >> r >> x >> y >> vx >> vy) {
        point a(x, y), b(vx, vy);
        line l(a, a+b);
        circle c1(point(0, 0), Rm+r);
        circle c2(point(0, 0), R +r);
        line cp1 = crosspointCL(c1, l);
        line cp2 = crosspointCL(c2, l);
        //cout << cp1.a << " " << cp1.b << endl;
        //cout << cp2.a << " " << cp2.b << endl;
        double ans;
        if(!intersectCL(c2, l) or dot(point(0, 0) - a, b) < 0.0)
            ans = 0.0;
        else if(!intersectCL(c1, l))
            ans = abs(cp2.a - cp2.b);
        else
            ans = min(abs(cp1.a-cp2.a), abs(cp1.a-cp2.b))*2;
        printf("%.3f\n", ans/abs(b));
    }
    return 0;
}
