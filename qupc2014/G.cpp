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
#define EPS 1e-6
#define PI acos(-1.0)

using namespace std;

#define double long double
typedef long long ll;
typedef vector<int> vi;
typedef complex<double> P;
typedef vector<P> G;

inline bool eq(double a, double b){ return fabs(a-b) < EPS; } // a == 0
inline bool ps(double a) { return a > EPS; } // a > 0
inline bool ng(double a) { return ps(-a); } // a < 0
inline bool gr(double a, double b) { return ps(a-b); } // a > b
namespace std {
    bool operator < (const P& a, const P& b) {
        return !eq(real(a), real(b)) ? gr(real(b), real(a)) : gr(imag(b), imag(a));
    }
}
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
struct L {
    P a, b;
    L(const P &a, const P &b) : a(a), b(b){ }
};

struct C {
    P p; double r;
    C() : p(0), r(0) {}
    C(const P &p, double r) : p(p), r(r) { }
};

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (ps(cross(b, c)))   return +1;       // +1 : 反時計回り
    if (ng(cross(b, c)))   return -1;       // -1 : 時計回り
    if (ng(dot(b, c)))     return +2;       // +2 : 線上(c--a--b)
    if (gr(norm(c), norm(b))) return -2;       // -2 : 線上(a--b--c)
    return 0;
}

P projection(const L &l, const P &p) {
    double t = dot(p-l.a, l.a-l.b) / norm(l.a-l.b);
    return l.a + t*(l.a-l.b);
}

int intersectCS(const C &c, const L &l){ // 交点数を返す
    if(ps(norm(projection(l, c.p) - c.p) - c.r*c.r)) return 0;
    double d1 = abs(c.p - l.a);
    double d2 = abs(c.p - l.b);
    if(!gr(d1, c.r) && !gr(d2, c.r)) return 0;
    if(gr(c.r, d1) && !gr(d2, c.r)
       || gr(d1, c.r) && gr(c.r, d2) ) return 1;
    P h = projection(l, c.p);
    if(ng(dot(l.a - h, l.b - h))) return 2;
    return 0;
}

G convex_hull(G gg) {
    int n = gg.size(), k = 0;
    sort(gg.begin(), gg.end());
    G ch(2*n);
    for (int i = 0; i < n; ch[k++] = gg[i++])
        while (k >= 2 && ccw(ch[k-2], ch[k-1], gg[i]) <= 0) --k;
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = gg[i--])
        while (k >= t && ccw(ch[k-2], ch[k-1], gg[i]) <= 0) --k;
    ch.resize(k-1);
    return ch;
}

int n, m;

struct Rect{
    int x, y, w, h;
    Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
};

bool inC(C c, P p) {
    return abs(c.p - p) < c.r + EPS;
}

bool intersectRect(C c, Rect r) {
    P p[4] = {
        P(r.x, r.y),
        P(r.x+r.w, r.y),
        P(r.x+r.w, r.y+r.h),
        P(r.x, r.y+r.h),
    };
    rep(i, 4) if(inC(c, p[i]) || intersectCS(c, L(p[i], p[(i+1)%4]))) return true;
    if(r.x <= c.p.real() && c.p.real() <= r.x + r.w &&
       r.y <= c.p.imag() && c.p.imag() <= r.y + r.h) return true;
    return false;

}

int main()
{
    cin >> n >> m;
    vector<C> cv;
    rep(i, n) {
        int x, y, r;
        cin >> x >> y >> r;
        cv.pb(C(P(x, y), r));
    }
    vector<Rect> rv;
    rep(i, m) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        rv.pb(Rect(x, y, w, h));
    }
    vector<bool> ok(m);
    rep(i, n) rep(j, m) if(intersectRect(cv[i], rv[j])) ok[j] = true;
    G g;
    rep(i, m) if(ok[i]) {
        Rect r = rv[i];
        g.pb(P(r.x, r.y));
        g.pb(P(r.x+r.w, r.y));
        g.pb(P(r.x+r.w, r.y+r.h));
        g.pb(P(r.x, r.y+r.h));
    }
    double ans = 0;
    if(g.size()) {
        g = convex_hull(g);
        rep(i, g.size()) ans += abs(g[(i+1)%g.size()] - g[i]);
    }
    printf("%.4Lf\n", ans);
    return 0;
}
