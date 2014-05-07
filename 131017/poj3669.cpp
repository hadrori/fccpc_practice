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
int m;
int meteor[310][310];
int memo[310][310];
bool inrange(int x, int y) {
    return x >= 0 && y >= 0 && x < 310 && y < 310;
}

struct node{
    int x, y, step;
    node(int x, int y, int step) : x(x), y(y), step(step){

    }
};

int main()
{
    cin >> m;
    const int dx[] = {-1, 0, 1, 0, 0};
    const int dy[] = {0, 1, 0, -1, 0};
    rep(i, 310) rep(j, 310) meteor[i][j] = INF;
    rep(i, 310) rep(j, 310) memo[i][j] = INF;
    rep(i, m) {
	int x, y, t;
	cin >> x >> y >> t;
	rep(j, 5) {
	    int nx = x + dx[j];
	    int ny = y + dy[j];
	    if(inrange(nx, ny)) meteor[nx][ny] = min(meteor[nx][ny], t);
	}
    }
    
    queue<node> q;
    q.push(node(0, 0, 0));

    while(!q.empty()) {
	int x = q.front().x;
	int y = q.front().y;
	int step = q.front().step;
	q.pop();
	if(meteor[x][y] <= step) continue;
	if(memo[x][y] <= step) continue;
	memo[x][y] = step;
	rep(i, 4) {
	    int nx = x + dx[i];
	    int ny = y + dy[i];
	    if(inrange(nx, ny)) q.push(node(nx, ny, step+1));
	}
    }

    int ans = INF;
    rep(i, 310) rep(j, 310) if(meteor[i][j] == INF) ans = min(ans, memo[i][j]);
    if(ans < INF) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}
