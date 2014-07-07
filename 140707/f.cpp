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

int len, x, y, xx, yy, w, h;

void prepare()
{
    if ((y < 0) + (yy < 0) == 1) {
        swap(x, y), swap(xx, yy);
    }
    if (y < 0) {
        swap(y, yy);
        y = -y, yy = -yy;
    }
    if (x + xx < 0) {
        swap(x, xx);
        x = -x, xx = -xx;
    }
}

const double pi = acos(-1.0);

double left_pm()
{
    const double l = hypot(x, y);
    if (len <= l) {
        double th = asin((double) y / len);
        return th * len;
    }
    double th = asin(y / l);
    double ret = th * len;
    ret += (pi / 2.0 - th) * (len - l);
    if (len > l + h) {
        ret += (pi / 2.0) * (len - l - h);
    }
    return ret;
}

double left_nn()
{
    const double l = hypot(x, yy);
    if (len <= l) {
        double th = asin((double) x / len);
        return th * len;
    }
    double th = asin(x / l);
    double ret = th * len;
    ret += (pi / 2.0 - th) * (len - l);
    if (len > l + w) {
        ret += (pi / 2.0) * (len - l - w);
    }
    return ret;
}

double right()
{
    const double r = hypot(xx, y);
    if (len <= r) {
        double th = asin((double) y / len);
        return th * len;
    }
    double th = asin(y / r);
    double ret = th * len;
    ret += (pi / 2.0 - th) * (len - r);
    if (len > r + h) {
        ret += (pi / 2.0) * (len - r - h);
    }
    return ret;
}

inline bool tri(double a, double b, double c)
{
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    return a > 0.0 and a + b > c;
}

inline double angle(double a, double b, double c)
{
    return acos((a * a + b * b - c * c) / (2 * a * b));
}

double solve_pm()
{
    // cerr << "pm: ";
    if (len <= y) return pi * len;

    const double l = hypot((double) x, (double) y);
    const double r = hypot((double) xx, (double) y);
    const double D = hypot((double) w, (double) h);
    const double L = len - l - h;
    const double R = len - r;

    if (L >= 0.0 and R >= 0.0 and tri(D, L, R) and
        angle(D, L, R) >= angle(D, w, h) and
        angle(D, R, L) >= angle(D, h, w)) {
        double ret = 0.0;
        ret += asin(y / l) * len;
        ret += (pi / 2.0 - asin(y / l)) * (len - l);
        ret += (pi / 2.0 - (angle(D, L, R) - angle(D, w, h))) * (len - l - h);

        ret += asin(y / r) * len;
        ret += (pi / 2.0 - asin(y / r) - (angle(D, R, L) - angle(D, h, w))) * (len - r);
        return ret;
    }
    if (L - w >= 0.0 and R >= 0.0 and tri(L - w, R, h)) {
        double ret = 0.0;
        ret += asin(y / l) * len;
        ret += (pi / 2.0 - asin(y / l)) * (len - l);
        ret += (pi / 2.0) * (len - l - h);
        ret += (pi / 2.0 - angle(h, L - w, R)) * (len - l - h - w);

        ret += asin(y / r) * len;
        ret += (pi / 2.0 - asin(y / r) - angle(h, R, L - w)) * (len - r);
        return ret;
    }
    if (L >= 0.0 and R - h >= 0.0 and tri(L, R - h, w)) {
        double ret = 0.0;
        ret += asin(y / l) * len;
        ret += (pi / 2.0 - asin(y / l)) * (len - l);
        ret += (pi / 2.0 - angle(w, L, R - h)) * (len - l - h);

        ret += asin(y / r) * len;
        ret += (pi / 2.0 - asin(y / r)) * (len - r);
        ret += (pi / 2.0 - angle(w, R - h, L)) * (len - r - h);
        return ret;
    }
    return left_pm() + right();
}

double solve_nn()
{
    // cerr << "nn: ";
    if (len <= hypot(x, y)) return (pi / 2.0) * len;

    const double l = hypot((double) x, (double) yy);
    const double r = hypot((double) xx, (double) y);
    const double D = hypot((double) w, (double) h);
    const double L = len - l;
    const double R = len - r;

    if (L >= 0.0 and R >= 0.0 and tri(D, L, R) and
        angle(D, L, R) >= angle(D, w, h) and
        angle(D, R, L) >= angle(D, h, w)) {
        double ret = 0.0;
        ret += asin(x / l) * len;
        ret += (pi / 2.0 - asin(x / l) - (angle(D, L, R) - angle(D, w, h))) * (len - l);

        ret += asin(y / r) * len;
        ret += (pi / 2.0 - asin(y / r) - (angle(D, R, L) - angle(D, h, w))) * (len - r);
        return ret;
    }
    if (L - w >= 0.0 and R >= 0.0 and tri(L - w, R, h)) {
        double ret = 0.0;
        ret += asin(x / l) * len;
        ret += (pi / 2.0 - asin(x / l)) * (len - l);
        ret += (pi / 2.0 - angle(h, L - w, R)) * (len - l - w);

        ret += asin(y / r) * len;
        ret += (pi / 2.0 - asin(y / r) - angle(h, R, L - w)) * (len - r);
        return ret;
    }
    if (L >= 0.0 and R - h >= 0.0 and tri(L, R - h, w)) {
        double ret = 0.0;
        ret += asin(x / l) * len;
        ret += (pi / 2.0 - asin(x / l) - angle(w, L, R - h)) * (len - l);

        ret += asin(y / r) * len;
        ret += (pi / 2.0 - asin(y / r)) * (len - r);
        ret += (pi / 2.0 - angle(w, R - h, L)) * (len - r - h);
        return ret;
    }
    return left_nn() + right();
}

double solve()
{
    if (x < 0) return pi * len + solve_pm();
    return 1.5 * pi * len + solve_nn();
}

int main()
{
    while (cin >> len >> x >> y >> xx >> yy and len) {
        prepare();
        w = xx - x, h = yy - y;
        printf("%.8f\n", solve());
    }

    return 0;
}
