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

typedef complex<double> point;

const int N = 108;

int n, m;
point p[N], q[N];

point in() { double x, y; cin >> x >> y; return point(x, y); }

void input()
{
    cin >> n;
    rep(i, n) p[i] = in();
    cin >> m;
    rep(i, m) q[i] = in();

    p[n] = p[0], q[m] = q[0];
}

const double eps = 1e-8;

double dot(point a, point b) { return real(conj(a) * b); }
double cross(point a, point b) { return imag(conj(a) * b); }

bool in(point p, point a, point b)
{
    return dot(p - a, b - a) > 0.0 and abs(p - a) < abs(b - a);
}

point proj(point p, point a, point b)
{
    return a + dot(p - a, b - a) * (b - a) / norm(b - a);
}

double dist(point p, point a, point b)
{
    const point h = proj(p, a, b);

    if (!in(h, a, b)) return min(abs(p - a), abs(p - b));

    return abs(h - p);
}

void solve()
{
    double ans = 1e9;
    rep(i, n) rep(j, m) {
        ans = min(ans, dist(p[i], q[j], q[j + 1]));
        ans = min(ans, dist(q[j], p[i], p[i + 1]));
    }
    printf("%.8f\n", ans / 2.0);
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        input();
        solve();
    }

    return 0;
}
