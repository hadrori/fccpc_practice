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
int n;
struct C {
    int x, y, r;
    C(int x, int y, int r) : x(x), y(y), r(r) {}
};

vector<C> v;
inline double sq(double x) { return x*x; }

bool check(double R, int x, int y) {
    rep(i, n) {
        double r = v[i].r;
        if(v[i].x == x && v[i].y == y) {
            if(R * R < r * r / 2) return false;
        } else {
            double d = sqrt(sq(x-v[i].x) + sq(y-v[i].y));
            if(R - r > d) continue;
            if(R + r < d) return false;
            double th1 = acos((r*r+d*d-R*R)/(2*r*d));
            double th2 = acos((R*R+d*d-r*r)/(2*R*d));
            double S = r*r*th1 + R*R*th2 - d*r*sin(th1);
            if(S < PI * r*r/2) return false;
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    rep(_, T) {
        cin >> n;
        v.clear();
        rep(i, n) {
            int x, y, r;
            cin >> x >> y >> r;
            v.pb(C(x, y, r));
        }
        double ans = INF;
        rep(i, n) {
            double lower = 0;
            double upper = INF;
            rep(j, 100) {
                double mid = (lower + upper) / 2.0;
                if(check(mid, v[i].x, v[i].y)) upper = mid;
                else lower = mid;
            }
            ans = min(ans, upper);
        }
        printf("%.4f\n", ans);
    }
    
    
    return 0;
}
