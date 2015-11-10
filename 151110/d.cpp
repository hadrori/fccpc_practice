#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define pb push_back
#define all(u) begin(u),end(u)
#define mp make_pair
#define long int64_t


int n, m;
const int MAX = 200008;
bool vis[MAX];
map<int, int> lst;

struct Point {
    int type;
    int x, y;
    int now;
    int id;
    Point(int type, int x, int y, int id): type(type), x(x), y(y), id(id) { now = 0; }
    void next() {
        if (now == 0) {
            x *= -1;
        } else if (now == 1) {
            type *= -1;
            swap(x, y);
        } else if (now == 2) {
            y *= -1;
        }
        now++;
    }

    bool operator<(const Point &o) const {
        if (x != o.x) return x < o.x;
        return type < o.type;
    }
};

void solve(const vector<Point> &pv) {
    lst.clear();
    int now = 0;
    for (Point p: pv) {
        if (p.type == 1) continue;
        else if (p.type == -1) { // bar
            now++;
        } else { // point
            if (lst[p.y] != now and now != 0) {
                vis[p.id] = true;
                lst[p.y] = now;
            }
        }
    }
}

void input() {
    cin >> n >> m;    
    vector<Point> pv;
    int id = 0;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        pv.pb(Point(0, x, y, id++));
    }
    rep(i, m) {
        char c;
        int x, y;
        cin >> c;
        if (c == 'H') {
            cin >> y;
            pv.pb(Point(1, 0, y, id++));
        } else if (c == 'V') {
            cin >> x;
            pv.pb(Point(-1, x, 0, id++));
        }
    }
    memset(vis, 0, sizeof(vis));
    rep(_, 4) {
        sort(all(pv));
        solve(pv);
        rep(i, pv.size()) pv[i].next();
    }
    int ans = 0;
    rep(i, pv.size()) if (vis[i]) ans++;
    if (n * 60 <= ans * 100) cout << "PASSED" << endl;
    else cout << "FAILED" << endl;

}

int main() {
    cin.tie(0);
    int _; cin >> _;
    while(_--) {
        input();
    }
    return 0;
}
