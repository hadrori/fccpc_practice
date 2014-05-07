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
double x[4], y[4];
typedef complex<double> P;
inline bool eq(double a, double b) { return fabs(a-b) < EPS; }
inline bool ps(double a) { return a > EPS; }
inline bool nq(double a) { return ps(-a); }
inline bool gr(double a, double b) { return ps(a-b);}

struct L {
    P a, b;
    L(const P &a, const P &b) : a(a), b(b){}
};
struct C{
    P p; double r;
    C() : p(0), r(0){}
    C(const P &p, double r) : p(p), r(r) {}
    C(double x, double y, double r) : p(P(x, y)), r(r) {}
};

bool intersectCC(C &c, C &d) {
    return (norm(c.p - d.p) - (c.r + d.r) * (c.r + d.r)) < -EPS &&
        (norm(c.p - d.p) - (c.r - d.r) * (c.r - d.r)) > EPS;
}

L crosspointCC(C &c1, C &c2) {
    double d = abs(c1.p - c2.p);
    double x = (c1.r * c1.r - c2.r * c2.r + d*d) / (2.0*d);
    P v = sqrt(c1.r * c1.r - x*x) * (c1.p - c2.p) / abs(c2.p - c1.p) * P(0, 1);
    P h = c1.p + x * (c2.p - c1.p)/abs(c2.p - c1.p);
    return L(h - v, h + v);
}

bool check(P p, double d) {
    rep(i, 4) if(abs(p - P(x[i], y[i])) > d + EPS) {
//        cout << abs(p-P(x[i], y[i])) << " " << d << endl;
        return false;
    }
    return true;
}

bool Cm(double d) {
    vector<P> pv;
    rep(i, 4) repi(j, i+1, 4) {
        C c1 = C(x[i], y[i], d);
        C c2 = C(x[j], y[j], d);
        if(!intersectCC(c1, c2)) continue;
        L tl = crosspointCC(c1, c2);
//        cout << tl.a << " " << tl.b << endl;
        pv.pb(tl.a);
        pv.pb(tl.b);
    }
    rep(i, pv.size()) {
        if(check(pv[i], d)) return true;
    }
    return false;
}

int main()
{
    while(cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3]) {
        bool ok = false;
        rep(i, 4) if(x[i] != -1 || y[i] != -1) ok = true;
        if(!ok) break;
        double upper = INF;
        double lower = 0;
        double mid;
        while(upper - lower > EPS) {
            mid = (lower + upper) / 2;
            if(Cm(mid)) lower = mid;
            else upper = mid;
        }
        printf("%.4f\n", lower);
    }
    return 0;
}
