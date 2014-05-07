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

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
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

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int w, h;
vector<string> _p;

inline bool in(int x, int y) { return 0 <= x && x < w && 0 <= y && y < h; }
inline char p(int x, int y) { return in(x, y) ? _p[y][x] : '.'; }

struct coor
{
    int x, y;
    coor(int x = -1, int y = -1) : x(x), y(y) {}
    bool operator <(const coor &t) const {
        return x < t.x || x == t.x && y < t.y;
    }
    bool operator !=(const coor &t) const {
        return x != t.x || y != t.y;
    }
};

coor leader[10][60], root;
map<coor,int> xl, xr, sum, cnt;
map<coor,set<coor> > child;

void dfs(int x, int y, int sx, int sy, char c)
{
    if (p(x, y) != c)
        return;
    coor l(sx, sy);
    leader[x][y] = l;
    sum[l] += x;
    ++cnt[l];
    _p[y][x] = '@';
    rep(i,4)
        dfs(x + dx[i], y + dy[i], sx, sy, c);
}

bool recur(coor c)
{
    bool ret = true;
    repit(it,child[c])
        ret &= recur(*it);
    if (!ret)
        return false;

    repit(it,child[c]) {
        sum[c] += sum[*it];
        cnt[c] += cnt[*it];
    }
    if (2 * sum[c] <= (2 * xl[c] - 1) * cnt[c])
        return false;
    if ((2 * xr[c] + 1) * cnt[c] <= 2 * sum[c])
        return false;
    return true;
}

bool solve()
{
    rep(x,10) rep(y,60)
        leader[x][y] = coor();

    xl.clear();
    xr.clear();
    sum.clear();
    cnt.clear();
    child.clear();

    rep(y,h) {
        rep(x,w) {
            if (p(x, y) != '.' && p(x, y) != '@')
                dfs(x, y, x, y, p(x, y));
        }
    }
    rep(y,h-1) {
        rep(x,w) {
            coor above = leader[x][y];
            coor under = leader[x][y + 1];
            if (above.x >= 0 && under.x >= 0 && above != under) {
                child[under].insert(above);
                if (xl.find(above) != xl.end()) {
                    xl[above] = min(xl[above], x);
                    xr[above] = max(xr[above], x);
                } else {
                    xl[above] = x;
                    xr[above] = x;
                }
            }
        }
    }
    rep(x,w) {
        if (leader[x][h - 1].x >= 0) {
            root = leader[x][h - 1];
            if (xl.find(root) != xl.end()) {
                xl[root] = min(xl[root], x);
                xr[root] = max(xr[root], x);
            } else {
                xl[root] = x;
                xr[root] = x;
            }
        }
    }
    return recur(root);
}

int main()
{
    while (cin >> w >> h && w) {
        _p.clear();
        _p.resize(h);
        rep(i,h)
            cin >> _p[i];

        cout << (solve() ? "STABLE" : "UNSTABLE") << endl;
    }
    
    return 0;
}
