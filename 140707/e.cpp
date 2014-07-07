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

const int N = 40;

int h, w, s, u[N][N], a[N][N], total;

void input()
{
    memset(u, 0, sizeof(u));
    memset(a, 0, sizeof(a));

    rep(i, h) rep(j, w) {
        cin >> u[i][j];
        a[i + 1][j + 1] = a[i + 1][j] + a[i][j + 1] - a[i][j] + u[i][j];
    }
    total = a[h][w];
}

inline int acc(int x, int y, int xx, int yy)
{
    return a[yy][xx] - a[y][xx] - a[yy][x] + a[y][x];
}

typedef pair<int, int> pii;

pii f(pii a, pii b)
{
    return mp(a.first + b.first, min(a.second, b.second));
}

pii mem[N][N][N][N];

pii recur(int x, int y, int xx, int yy)
{
    pii& ret = mem[x][y][xx][yy];
    if (ret.first >= 0) return ret;

    int part = acc(x, y, xx, yy);
    if (total - part > s) return mp(-1, -1);

    ret = mp(1, s - (total - part));
    repi(mx, x + 1, xx) {
        pii tmp = f(recur(x, y, mx, yy), recur(mx, y, xx, yy));
        ret = max(ret, tmp);
    }
    repi(my, y + 1, yy) {
        pii tmp = f(recur(x, y, xx, my), recur(x, my, xx, yy));
        ret = max(ret, tmp);
    }
    return ret;
}

void solve()
{
    memset(mem, -1, sizeof(mem));

    pii ans = recur(0, 0, w, h);
    cout << ans.first << ' ' << ans.second << endl;
}

int main()
{
    while (cin >> h >> w >> s and h) {
        input();
        solve();
    }

    return 0;
}
