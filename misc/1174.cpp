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

int h, w, c, p[16][16];

bool in(int x, int y) { return 0 <= x && x < w && 0 <= y && y < h; }

int ans, op[8], q[16][16];
bool ved[16][16];

void shock(int x, int y, int c, int nc)
{
    if (!in(x, y) || q[y][x] != c || ved[y][x]) return;
    q[y][x] = nc;
    ved[y][x] = true;

    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};
    rep(i, 4)
	shock(x + dx[i], y + dy[i], c, nc);
}

int cnt;

void ponyo(int x, int y, int c)
{
    if (!in(x, y) || q[y][x] != c || ved[y][x]) return;
    ved[y][x] = true;
    ++cnt;

    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};
    rep(i, 4)
	ponyo(x + dx[i], y + dy[i], c);
}

void attempt()
{
    rep(y, h) rep(x, w) q[y][x] = p[y][x];
    rep(i, 5) {
	memset(ved, 0, sizeof(ved));
	shock(0, 0, q[0][0], op[i]);
    }

    memset(ved, 0, sizeof(ved));
    cnt = 0;
    ponyo(0, 0, c);
    ans = max(ans, cnt);
}

void dfs(int d, int prev)
{
    if (d == 5) {
	attempt();
	return;
    }
    for (int i = 1; i <= 6; ++i) {
	op[d] = i;
	dfs(d + 1, i);
    }
}

int solve()
{
    ans = 0;
    dfs(0, 0);
    return ans;
}

int main() {
    while (cin >> h >> w >> c && h) {
	rep(y, h) rep(x, w) cin >> p[y][x];
	op[4] = c;

	cout << solve() << endl;
    }
    return 0;
}
