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

typedef vector<double> point;

struct segment
{
    point a, b;
    segment(point a, point b) : a(a), b(b) {}
};

struct ball
{
    point p; double r; ll l;
    ball(point p, double r, ll l) : p(p), r(r), l(l) {}
};

bool intersect(segment s, ball b)
{
    point u(3), v(3);
    double num = 0.0, den = 0.0;
    rep(i, 3) {
        u[i] = s.b[i] - s.a[i];
        v[i] = b.p[i] - s.a[i];
        num += u[i] * v[i];
        den += u[i] * u[i];
    }
    const double c = num / den;
    if (c < 0.0 or 1.0 < c) {
        return false;
    }
    point h = s.a;
    rep(i, 3) {
        h[i] += c * u[i];
    }
    double d = 0.0;
    rep(i, 3) d += (h[i] - b.p[i]) * (h[i] - b.p[i]);
    return d < b.r * b.r + 1e-8;
}

int n, q;
vector<ball> balls;
vector<segment> ss;

point get()
{
    point ret(3);
    rep(i, 3) cin >> ret[i];
    return ret;
}    

void input()
{
    cin >> n >> q;
    rep(i, n) {
        point p = get();
        double r; ll l;
        cin >> r >> l;
        balls.pb(ball(p, r, l));
    }
    rep(i, q) {
        point p = get(), q = get();
        ss.pb(segment(p, q));
    }
}

void solve()
{
    rep(i, q) {
        ll ans = 0;
        rep(j, n) if (intersect(ss[i], balls[j])) {
            ans += balls[j].l;
        }
        cout << ans << endl;
    }
}

int main()
{
    input();
    solve();

    return 0;
}
