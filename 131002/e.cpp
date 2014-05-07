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

#define repi(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) repi(i, 0, a)
#define repd(i, a, b) for(int i = (a); i >= (b); i--)
#define repit(i, a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

#define all(u) (u).begin(), (u).end()
#define rall(u) (u).rbegin(), (u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)), (u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vector<vector<bool> > wall, wall1;
vector<pair<int, int> > a, b;

int n, m;

bool inrange(int x, int y)
{
    return 0 <= x && x < m && 0 <= y && y < n;
}

bool canmove(int x, int y)
{
    return inrange(x, y) && !wall[x][y];
}

bool canmove1(int x, int y)
{
    return inrange(x, y) && !wall1[x][y];
}

struct node
{
    int x, y, d;
    vector<pair<int, int> > hist;
    node(int x, int y, int d, vector<pair<int, int> > hist) : x(x), y(y), d(d), hist(hist) {}
};

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int solve1(vector<pair<int, int> > u)
{
    int ret = INF;

    vector<vector<int> > dist(m, vector<int>(n, INF));
    queue<node> q;
    q.push(node(u.front().first, u.front().second, 0, vector<pair<int, int> >(1, mp(u.front().first, u.front().second))));
    while (!q.empty()) {
	node cur = q.front();
	q.pop();

	if (dist[cur.x][cur.y] < cur.d)
	    continue;
	dist[cur.x][cur.y] = cur.d;
	if (cur.x == u.back().first && cur.y == u.back().second)
	    return cur.d;

	rep(i, 4) {
	    int nx = cur.x + dx[i];
	    int ny = cur.y + dy[i];
	    if (canmove1(nx, ny)) {
		int nd = cur.d + 1;
		vector<pair<int, int> > nhist(cur.hist);
		nhist.pb(mp(nx, ny));
		q.push(node(nx, ny, nd, nhist));
	    }
	}
    }
    return INF;
}

int solve(vector<pair<int, int> > u, vector<pair<int, int> > v)
{
    int ret = INF;

    vector<vector<int> > dist(m, vector<int>(n, INF));
    queue<node> q;
    q.push(node(u.front().first, u.front().second, 0, vector<pair<int, int> >(1, mp(u.front().first, u.front().second))));
    while (!q.empty()) {
	node cur = q.front();
	q.pop();

	if (dist[cur.x][cur.y] < cur.d)
	    continue;
	dist[cur.x][cur.y] = cur.d;

	if (cur.x == u.back().first && cur.y == u.back().second) {
	    wall1 = wall;
	    repit(it, cur.hist)
		wall1[it->first][it->second] = true;
	    ret = min(ret, cur.d + solve1(v));
	}

	rep(i, 4) {
	    int nx = cur.x + dx[i];
	    int ny = cur.y + dy[i];
	    if (canmove(nx, ny)) {
		int nd = cur.d + 1;
		vector<pair<int, int> > nhist(cur.hist);
		nhist.pb(mp(nx, ny));
		q.push(node(nx, ny, nd, nhist));
	    }
	}
    }

    return ret;
}

int main()
{
    while (cin >> n >> m && n) {
	wall.assign(m, vector<bool>(n));
	a.clear();
	b.clear();

	rep(y, n) rep(x, m) {
	    int tmp; cin >> tmp;
	    wall[x][y] = tmp == 1;
	    if (tmp == 2)
		a.pb(mp(x, y));
	    else if (tmp == 3)
		b.pb(mp(x, y));
	}

	cout << min(solve(a, b), solve(b, a)) << endl;
    }

    return 0;
}
