#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

#define long int64_t

vector<pair<int, int>> get_polygon()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ret;
    rep(_, n) {
        int x, y;
        cin >> x >> y;
        ret.emplace_back(x, y);
    }
    return ret;
}

long cross(long ax, long ay,
           long bx, long by,
           long cx, long cy)
{
    bx -= ax, by -= ay;
    cx -= ax, cy -= ay;
    long t = bx * cy - by * cx;
    return (t > 0) - (t < 0);
}

long dot(long ax, long ay,
         long bx, long by)
{
    return ax * bx + ay * by;
}

bool on(long x, long y,
        long ax, long ay,
        long bx, long by)
{
    return dot(x - ax, y - ay, bx - ax, by - ay) >= 0 and
        dot(x - bx, y - by, ax - bx, ay - by) >= 0 and
        cross(ax, ay, bx, by, x, y) == 0;
}

bool downside(long x, long y,
              long ax, long ay,
              long bx, long by)
{
    if (ax == bx) return false;
    return ((by - ay) * (x - ax) + ay * (bx - ax) < y * (bx - ax)) ^ (ax < bx);
}

int solve(int x, int y, vector<pair<int, int>> P)
{
    const int k = P.size();
    int t = 0;
    rep(i, k) {
        int ax, ay, bx, by;
        tie(ax, ay) = P[i];
        tie(bx, by) = P[(i+1)%k];
        if (on(x, y, ax, ay, bx, by)) {
            return 0;
        } else if (downside(x, y, ax, ay, bx, by)) {
            t += (ax < x) - (bx < x);
        }
    }
    return t ? 1 : 2;
}

int main()
{
    int t;
    for (cin >> t; t--; ) {
        int n, x, y;
        cin >> n >> x >> y;
        rep(i, n) {
            if (i) cout << ' ';
            auto P = get_polygon();
            cout << solve(x, y, P);
        }
        cout << endl;
    }
    return 0;
}
