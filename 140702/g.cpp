#include <algorithm>
#include <cassert>
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

using namespace std;

const double inf = 1e9;

// constants and eps-considered operators

const double eps = 1e-4; // choose carefully!
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
    if (lt(dot(b, c), 0.0))   return 0; // c -- a -- b
    if (lt(norm(b), norm(c))) return 0; // a -- b -- c
    return 0;
}
bool intersectLS(const line& l, const line& s) {
    return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) < 0;
}
bool intersectSS(const line& s, const line& t) {
    return intersectLS(s, t) and intersectLS(t, s);
}
bool intersectLL(const line& l, const line& m) {
    return ne(cross(l.b - l.a, m.b - m.a), 0.0)  // not parallel
        or eq(cross(l.b - l.a, m.a - l.a), 0.0); // overlap
}
point crosspointLL(const line& l, const line& m) {
    double p = cross(l.b - l.a, m.b - m.a);
    double q = cross(l.b - l.a, m.a - l.a);
    if (eq(p, 0.0) and eq(q, 0.0)) return m.a; // overlap
    //assert(ne(p, 0.0));                        // parallel
    return m.a - q / p * (m.b - m.a);
}
point proj(const line& l, point p) {
    double t = dot(l.b - l.a, p - l.a) / norm(l.b - l.a);
    return l.a + t * (l.b - l.a);
}
point reflection(const line& l, point p) { return 2.0 * proj(l, p) - p; }

int n;
vector<line> mirror;
point s, target;

inline point in() { double x, y; cin >> x >> y; return point(x, y); }
inline line in2() { point a = in(), b = in(); return line(a, b); }

void input()
{
    mirror.clear();
    rep(i, n) mirror.pb(in2());
    target = in();
    s = in();
}

vector<point> cands;

void prepare()
{
    cands.clear();
    cands.pb(target);
    vector<point> curr(cands), next;
    rep(i, 5) {
        repit(it, curr) repit(itm, mirror) {
            next.pb(reflection(*itm, *it));
        }
        cands.insert(cands.end(), all(next));
        curr = next;
        next.clear();
    }
}

double simulate(point s, point t, int cnt)
{
    if (cnt >= 6) return inf;
    if(abs(s-t) < eps) return inf;
    int id = -1;
    point m = t;
    rep(i, n) if (intersectLS(line(s, t), mirror[i])) {
        point x = crosspointLL(line(s, t), mirror[i]);
        if (le(dot(t - s, x - s), 0.0)) continue;
        if (ge(abs(x - s), abs(m - s))) continue;
        id = i, m = x;
    }

    if (id < 0) {
        if (abs(target - t) < eps) return abs(t-s);
        else return inf;
    }

    if (abs(target - t) < eps and le(abs(t - s), abs(m - s))) {
        return abs(t-s);
    }

    double ret = abs(m - s);
    ret += simulate(m, reflection(mirror[id], t), cnt + 1);
    return min(ret, inf);
}

void solve()
{
    prepare();

    double ans = inf;
    double tmp;
    repit(it, cands) {
        tmp = simulate(s, *it, 0);
        // if(tmp < ans) cout << "a " << *it << " " << tmp << endl;
        ans = min(ans, tmp);
    }
    printf("%.14f\n", ans);
}

int main()
{
    while (cin >> n and n) {
        input();
        solve();
    }

    return 0;
}
