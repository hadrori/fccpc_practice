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

const double eps = 1e-9;

double x, y, vx, vy, vh;

inline double sq(double x) { return x * x; }

void solve()
{
    const double a = sq(vx) + sq(vy) - sq(vh);
    const double b = 2.0 * (x * vx + y * vy);
    const double c = sq(x) + sq(y);
    const double D = sq(b) - 4.0 * a * c;
    if (abs(a) < eps) {
        if (abs(b) < eps) {
            if (abs(c) < eps) {
                puts("0");
            } else {
                puts("IMPOSSIBLE");
            }
            return;
        }
        const double cand = -c / b;
        if (cand > eps) {
            printf("%.8Lf\n", max(cand, 0.0L));
        } else {
            puts("IMPOSSIBLE");
        }
        return;
    }
    if (D < 0.0L) {
        puts("IMPOSSIBLE");
        return;
    }

    const double ans0 = (-b - sqrt(D)) / (2.0 * a);
    if (ans0 > eps) {
        printf("%.8Lf\n", max(ans0, 0.0L));
        return;
    }

    const double ans1 = (-b + sqrt(D)) / (2.0 * a);
    if (ans1 > eps) {
        printf("%.8Lf\n", max(ans1, 0.0L));
        return;
    }

    puts("IMPOSSIBLE");
    return;
}

int main()
{
    cin >> x >> y >> vx >> vy >> vh;

    solve();

    return 0;
}
