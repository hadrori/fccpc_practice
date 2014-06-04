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

const int N = 1024;

int n, m;
char grid[N][N];

void input()
{
    cin >> n >> m;
    rep(i, n) cin >> grid[i];
}

bool in(int y, int x) { return 0 <= y and y < n and 0 <= x and x < m; }

const int top[] = {0, 0, 1, 1, 0, 1};
const int btm[] = {0, 1, 0, 0, 1, 1};
const int lft[] = {0, 1, 1, 0, 0, 1};
const int rgt[] = {0, 0, 0, 1, 1, 1};

int dir(int y, int x) { return grid[y][x] - 'A'; }

void bfs(int sy, int sx)
{
    queue<pair<int, int> > q;
    q.push(mp(sy, sx));
    while (not q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int d = grid[y][x] - 'A';
        q.pop();

        if (not in(y, x) or grid[y][x] == 'A') continue;
        grid[y][x] = 'A';
        
        if (y > 0 and top[d]) {
            int nd = dir(y - 1, x);
            if (btm[nd]) q.push(mp(y - 1, x));
        }
        if (y < n - 1 and btm[d]) {
            int nd = dir(y + 1, x);
            if (top[nd]) q.push(mp(y + 1, x));
        }
        if (x > 0 and lft[d]) {
            int nd = dir(y, x - 1);
            if (rgt[nd]) q.push(mp(y, x - 1));
        }
        if (x < m - 1 and rgt[d]) {
            int nd = dir(y, x + 1);
            if (lft[nd]) q.push(mp(y, x + 1));
        }
    }
}

void solve()
{
    int ans = 0;
    rep(i, n) rep(j, m) {
        if (grid[i][j] != 'A') {
            bfs(i, j);
            ++ans;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }

    return 0;
}
