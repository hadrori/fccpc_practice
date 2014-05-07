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
 
#define double long double
 
const double eps = 1e-12;
const double inf = 1e12;
 
typedef complex<double> point;
 
struct circle
{
    point o; double r;
    circle() : o(0.0, 0.0), r(0.0) {}
    circle(point o, double r) : o(o), r(r) {}
};
 
struct line {
    point a, b;
    line(point a, point b) : a(a), b(b) {}
};
 
double dot(point a, point b) { return real(conj(a) * b); }
double cross(point a, point b) { return imag(conj(a) * b); }
 
point proj(line l, point p)
{
    double t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);
    return l.a + t * (l.b - l.a);
}
 
line crosspoint(circle c, line l)
{
    point h = proj(l, c.o);
    double d2 = norm(h - c.o);
    point v = sqrt(c.r * c.r - d2) * (l.b - l.a) / abs(l.b - l.a);
    return line(h - v, h + v);
}
 
point crossll(line l, line m)
{
    double A = cross(l.b - l.a, m.b - m.a);
    double B = cross(l.b - l.a, l.b - m.a);
    if (abs(A) < eps and abs(B) < eps) return m.a; // 重なっている
    if (abs(A) < eps) return point(1e9, 1e9); // 交差しない
    return m.a + B / A * (m.b - m.a);
}
 
point monkey, vm;
double vh;
 
void solve()
{
    if (abs(monkey) < eps or abs(vm) < eps) {
        printf("%.8Lf\n", abs(monkey) / vh);
        return;
    }
 
    const line l(monkey, monkey + vm);
 
    if (abs(vh - abs(vm)) < eps) {
        const point m = monkey / 2.0L;
        const line bs(m, m + monkey * point(0, 1));
        const point cand = crossll(bs, l);
        double ans = inf;
        if (dot(vm, cand - monkey) > -eps) {
            ans = min(ans, abs(cand - monkey) / abs(vm));
        }
        if (ans == inf) {
            puts("IMPOSSIBLE");
        } else {
            printf("%.8Lf\n", ans);
        }
        return;
    }
 
    const point pa = vh / (vh + abs(vm)) * monkey;
    const point pb = vh / (vh - abs(vm)) * monkey;
    const point o = (pa + pb) / 2.0L;
    const circle c(o, abs(o - pa));
    const line cand = crosspoint(c, l);
 
    double ans = inf;
    if (dot(vm, cand.a - monkey) > -eps) {
        ans = min(ans, abs(cand.a - monkey) / abs(vm));
    }
    if (dot(vm, cand.b - monkey) > -eps) {
        ans = min(ans, abs(cand.b - monkey) / abs(vm));
    }
    if (ans == inf) {
        puts("IMPOSSIBLE");
    } else {
        printf("%.8Lf\n", ans);
    }
}
 
int main()
{
    double x, y, vx, vy;
    cin >> x >> y >> vx >> vy >> vh;
    monkey = point(x, y);
    vm = point(vx, vy);
 
    solve();
 
    return 0;
}
