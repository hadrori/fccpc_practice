#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
#define mp make_pair
#define all(u) (u).begin(),(u).end()

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
typedef vector<point> polygon;

istream& operator>>(istream& in, point& p) { double x, y; in >> x >> y; p = point(x, y); return in; }

inline double dot  (point a, point b) { return real(conj(a) * b); }
inline double cross(point a, point b) { return imag(conj(a) * b); }

struct line {
  point a, b;
  line(point a, point b) : a(a), b(b) {}
};

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

polygon convex_cut(const polygon& g, const line& l) {
    polygon ret;
    int j = g.size() - 1;
    rep(i, g.size()) {
        if (ccw(l.a, l.b, g[j]) != -1) ret.pb(g[j]);
        if (intersectLS(l, line(g[j], g[i]))) ret.pb(crosspointLL(l, line(g[j], g[i])));
        j = i;
    }
    return ret;
}

double area(const polygon& g) {
  const int n = g.size();
  double ret = 0.0;
  rep(i, n) ret += cross(g[i], g[(i+1)%n]);
  return ret / 2.0;
}

int n, m;
polygon A, B;
point v;

double area_at(double t)
{
  polygon A1(A);
  rep(i, n) A1[i] += v * t;
  rep(j, m) {
    A1 = convex_cut(A1, line(B[j], B[(j+1)%m]));
  }
  return area(A1);
}

void solve()
{
  vector<double> events;
  rep(i, n) rep(j, m) {
    if (intersectLS(line(A[i], A[i] + v), line(B[j], B[(j+1)%m]))) {
      const point p = crosspointLL(line(A[i], A[i] + v), line(B[j], B[(j+1)%m]));
      const double t = real((p - A[i]) / v);
      if (t > 0.0) events.pb(t);
    }
    if (intersectLS(line(B[j], B[j] - v), line(A[i], A[(i+1)%m]))) {
      const point p = crosspointLL(line(B[j], B[j] - v), line(A[i], A[(i+1)%m]));
      const double t = real((B[j] - p) / v);
      if (t > 0.0) events.pb(t);
    }
  }
  if (events.empty()) {
    cout << "never" << endl;
    return;
  }
  sort(all(events));
  double ans = 0.0;
  rep(i, events.size() - 1) {
    double t1 = events[i], t2 = events[i+1];
    double a = area_at(t1);
    double b = area_at((t1+t2)/2.0);
    double c = area_at(t2);
    double p = (a+c-b-b)/2.0;
    double q = (c-a)/2.0;
    double r = b;
    ans = max(ans, max(a, c));
    if (abs(p) < 1e-9) continue;
    double x = -q/(2.0*p);
    if (abs(x) > 1.0) continue;
    double tmp = p*x*x + q*x + r;
    cerr<<a<<' '<<b<<' '<<c<<" -> "<<tmp<<endl;
    ans = max(ans, tmp);
  }
  cout << fixed << setprecision(6) << ans << endl;
}

int main()
{
  cin>>n;A.resize(n);rep(i,n)cin>>A[i];
  reverse(all(A));
  point p;cin>>p;v+=p;
  cin>>m;B.resize(m);rep(i,m)cin>>B[i];
  reverse(all(B));
  cin>>p;v-=p;
  solve();

  return 0;
}
