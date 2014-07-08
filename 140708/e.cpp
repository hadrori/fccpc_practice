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

const int N = 210;
const double eps = 1e-8;

typedef complex<double> point;

int n;
double x[N], y[N], r[N], d[N][N];
point c[N], p[N];

void generate()
{
    rep(i, n) c[i] = point(x[i], y[i]);

    p[0] = c[0];
    rep(i, n - 1) {
        double d = abs(c[i + 1] - c[i]);
        double th = arg(c[i + 1] - c[i]);
        double dth = acos((r[i] * r[i] + d * d - r[i + 1] * r[i + 1]) / (2 * r[i] * d));
        p[2 * i + 1] = c[i] + polar(r[i], th - dth);
        p[2 * i + 2] = c[i] + polar(r[i], th + dth);
    }
    p[2 * n - 1] = c[n - 1];
}

double cross(point a, point b) { return imag(conj(a) * b); }

bool reachable(int i, int j)
{
    repi(k, i + 1, j) {
        if (k % 2 == 1 and cross(p[j] - p[i], p[k] - p[i]) > eps) return false;            
        if (k % 2 == 0 and cross(p[j] - p[i], p[k] - p[i]) < eps) return false;
    }
    return true;
}

void prepare()
{
    rep(i, 2 * n) rep(j, 2 * n) {
        d[i][j] = 1e9;
    }
    rep(i, 2 * n) d[i][i] = 0.0;
    rep(i, 2 * n) repi(j, i + 1, 2 * n) {
        if (reachable(i, j)) {
            d[i][j] = abs(p[j] - p[i]);
        }
    }
}

void solve()
{
    generate();
    prepare();

    rep(k, 2 * n) rep(i, 2 * n) rep(j, 2 * n) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    printf("%.6f\n", d[0][2 * n - 1]);
}

int main()
{
    while (cin >> n and n) {
        rep(i, n) cin >> x[i] >> y[i] >> r[i];
        solve();
    }

    return 0;
}
