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

const double eps = 1e-8;

typedef complex<double> point;

struct line
{
    point a, b;
    line(point a, point b) : a(a), b(b) {}
};

struct circle
{
    point o;
    double r;
    circle(point o, double r) : o(o), r(r) {}
};

line tangent(circle c, double th)
{
    point p = c.o + polar(c.r, th);
    point dp = polar(c.r, th) * point(0, 1);
    return line(p - dp, p + dp);
}

vector<line> common(circle c1, circle c2)
{
    vector<line> ret;

    double d = abs(c2.o - c1.o);
    double th = arg(c2.o - c1.o);
    double dth = acos((c1.r - c2.r) / abs(c2.o - c1.o));
    if (abs(c2.r - c1.r) < d - eps) {
        ret.pb(tangent(c1, th - dth));
        ret.pb(tangent(c1, th + dth));
    }
    dth = acos((c1.r + c2.r) / abs(c2.o - c1.o));
    if (abs(c2.r + c2.r) < d) {
        ret.pb(tangent(c1, th - dth));
        ret.pb(tangent(c1, th + dth));
    }
    return ret;
}

const int N = 1024;

int n;
vector<circle> cs;

void input()
{
    cs.clear();

    cin >> n;
    rep(i, n) {
        double x, y, r;
        cin >> x >> y >> r;
        cs.pb(circle(point(x, y), r));
    }
}

double dot(point a, point b)
{
    return real(conj(a) * b);
}

point proj(line l, point p)
{
    double t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);
    return l.a + t * (l.b - l.a);
}

bool intersect(line l, circle c)
{
    return norm(proj(l, c.o) - c.o) - c.r * c.r < eps;
}

int attempt(line l)
{
    int ret = 0;
    rep(i, n) if (intersect(l, cs[i]))
        ++ret;
    return ret;
}

void solve()
{
    int ans = 1;
    rep(i, n) repi(j, i + 1, n) {
        vector<line> cands = common(cs[i], cs[j]);
        rep(k, cands.size())
            ans = max(ans, attempt(cands[k]));
    }
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    for(int _ = 0; _ < T; _++){
        cout << "Case #" << _+1 << ": ";
        input();
        solve();
    }
    return 0;
}
