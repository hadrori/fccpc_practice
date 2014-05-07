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

int h, w, s, u[50][50];

int rect(int x1, int y1, int x2, int y2)
{
    return u[x2][y2] - u[x1][y2] - u[x2][y1] + u[x1][y1];
}

pair<int,int> memo[36][36][36][36];

pair<int,int> recur(int x1, int y1, int x2, int y2)
{
    if (memo[x1][y1][x2][y2].first >= 0)
	return memo[x1][y1][x2][y2];

    pair<int,int> ret = mp(1, rect(x1, y1, x2, y2));
    for (int x = x1 + 1; x < x2; ++x) {
	pair<int,int> l = recur(x1, y1, x, y2);
	pair<int,int> r = recur(x, y1, x2, y2);
	pair<int,int> m = mp(l.first + r.first, min(l.second, r.second));
	if (m.second >= rect(0, 0, w, h) - s)
	    ret = max(ret, m);
    }
    for (int y = y1 + 1; y < y2; ++y) {
	pair<int,int> l = recur(x1, y1, x2, y);
	pair<int,int> r = recur(x1, y, x2, y2);
	pair<int,int> m = mp(l.first + r.first, min(l.second, r.second));
	if (m.second >= rect(0, 0, w, h) - s)
	    ret = max(ret, m);
    }
    return memo[x1][y1][x2][y2] = ret;
}

void solve()
{
    rep(i, 36) rep(j, 36) rep(k, 36) rep(l, 36)
	memo[i][j][k][l] = mp(-1, -1);

    pair<int,int> ans = recur(0, 0, w, h);
    cout << ans.first << ' ' << s + ans.second - rect(0, 0, w, h) << endl;
}

int main()
{
    while (cin >> h >> w >> s && h) {
	memset(u, 0, sizeof(u));
	rep(y, h) rep(x, w) cin >> u[x + 1][y + 1];
	for (int y = 1; y <= h; ++y)
	    for (int x = 1; x <= w; ++x)
		u[x][y] += u[x - 1][y] + u[x][y - 1] - u[x - 1][y - 1];

	solve();
    }
    return 0;
}
