#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <vector>

#define rep(i,a) for(int i = 0; i < a; i++)

using namespace std;

const int N = 1000010;

struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
    point operator +(const point& t) const {
        return point(x + t.x, y + t.y);
    }
    point operator -(const point& t) const {
        return point(x - t.x, y - t.y);
    }
};

int n;
vector<point> ps;

point perp(point p) {
    return point(-p.y, p.x);
}

int dot(point p, point q) {
    return p.x * q.x + p.y * q.y;
}

int side(point p1, point p2, point q) {
    int d = dot(q - p1, perp(p2 - p1));
    return d < 0 ? -1 : !!d;
}

double solve() {
    vector<bool> visited(n, false);

    double ans = 0.0;
    point now(0, 0);
    while (true) {
        int nexti = -1;
        point next;
        for (int i = 0; i < n; ++i) {
            if (visited[i])
                continue;
            if (nexti < 0 || side(now, next, ps[i]) > 0 || side(now, next, ps[i]) == 0 &&
                hypot(next.x - now.x, next.y - now.y) > hypot(ps[i].x - now.x, ps[i].y - now.y)) {
                nexti = i;
                next = ps[i];
            }
        }

        if (nexti == -1)
            return ans;

        ans += hypot(next.x - now.x, next.y - now.y);
        visited[nexti] = true;
        now = next;
    }
}

int main(){
    while (cin >> n, n) {
        ps.clear();
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            ps.push_back(point(x, y));
        }
        printf("%.1f\n", solve());
    }
}
