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

typedef complex<double> point;

struct shape
{
    bool isline;
    point a, b;
    shape(point a) : isline(false), a(a), b(0.0, 0.0) {}
    shape(point a, point b) : isline(true), a(a), b(b) {}
};

const double eps = 1e-8; // choose carefully!
const double pi = acos(-1.0);

inline bool lt(double a, double b) { return a < b - eps; }
inline bool gt(double a, double b) { return lt(b, a); }
inline bool le(double a, double b) { return !lt(b, a); }
inline bool ge(double a, double b) { return !lt(a, b); }
inline bool ne(double a, double b) { return lt(a, b) or lt(b, a); }
inline bool eq(double a, double b) { return !ne(a, b); }

inline double dot(point a, point b) { return real(conj(a) * b); }
inline double cross(point a, point b) { return imag(conj(a) * b); }

struct line {
    point a, b;
    line(point a, point b) : a(a), b(b) {}
};

point crosspointLL(const line& l, const line& m) {
    double p = cross(l.b - l.a, m.b - m.a);
    double q = cross(l.b - l.a, m.a - l.a);
    if (eq(p, 0.0) and eq(q, 0.0)) return m.a; // overlap
    assert(ne(p, 0.0));                        // parallel
    return m.a - q / p * (m.b - m.a);
}
point proj(const line& l, point p) {
    double t = dot(l.b - l.a, p - l.a) / norm(l.b - l.a);
    return l.a + t * (l.b - l.a);
}
point reflection(const line& l, point p) { return 2.0 * proj(l, p) - p; }

shape combine(shape s, shape t)
{
    if (s.isline and t.isline) {
        return shape(crosspointLL(line(s.a, s.b), line(t.a, t.b)));
    } else if (s.isline) {
        return shape(reflection(line(s.a, s.b), t.a));
    } else if (t.isline) {
        return combine(t, s);
    } else {
        return shape(s.a, t.a);
    }
}

string line;

shape parseExpr(int& pos);

double parseNumber(int& pos)
{
    bool neg = false;
    if (line[pos] == '-') {
        ++pos, neg = true;
    }
    int ret = 0;
    while (isdigit(line[pos])) {
        ret *= 10, ret += line[pos++] & 15;
    }
    return neg ? -ret : ret;
}

shape parseFactor(int& pos)
{
    ++pos;
    if (line[pos] == '-' or isdigit(line[pos])) {
        const double x = parseNumber(pos);
        ++pos;
        const double y = parseNumber(pos);
        ++pos;
        return shape(point(x, y));
    }
    shape ret = parseExpr(pos);
    ++pos;
    return ret;
}

ostream& operator <<(ostream& out, shape s)
{
    if (s.isline) out << "(line " << s.a << ' ' << s.b << ')';
    else out << "(point " << s.a << ')';
    return out;
}

shape parseExpr(int& pos)
{
    shape ret = parseFactor(pos);
    while (pos < line.length() and line[pos] != ')') {
        ++pos;
        ret = combine(ret, parseFactor(pos));
    }
    return ret;
}

int main()
{
    while (cin >> line and line[0] != '#') {
        int pos = 0;
        shape ans = parseExpr(pos);
        printf("%.8f %.8f\n", ans.a.real(), ans.a.imag());
    }

    return 0;
}
