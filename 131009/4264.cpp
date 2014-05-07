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

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
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
typedef vector<vi> image;

vector<char> chars;
vector<image> images;

image get()
{
    image ret = image(10, vi(10));
    rep(y, 10) {
	string line;
	cin >> line;
	rep(x, 10)
	    ret[x][y] = line[x] & 1;
    }
    return ret;
}

int n;

void input()
{
    cin >> n;
    chars.resize(n);
    rep(i, n)
	cin >> chars[i], images.pb(get());
}

int dist(image i1, image i2, int sx, int sy, int dx, int dy, bool flip)
{
    int ret = 0;
    int x1 = sx, y1;
    rep(x, 10) {
	y1 = sy;
	rep(y, 10) {
	    ret += (flip ? i1[x][y] != i2[x1][y1] : i1[x][y] != i2[y1][x1]);
	    y1 += dy;
	}
	x1 += dx;
    }
    return ret;
}

void solve1()
{
    image t = get();
    int mn = (int) INF, mi = -1;
    rep(i, n) {
	int tmp = dist(images[i], t, 0, 0, 1, 1, false);
	tmp = min(tmp, dist(images[i], t, 0, 0, 1, 1, true));
	tmp = min(tmp, dist(images[i], t, 0, 9, 1, -1, false));
	tmp = min(tmp, dist(images[i], t, 0, 9, 1, -1, true));
	tmp = min(tmp, dist(images[i], t, 9, 0, -1, 1, false));
	tmp = min(tmp, dist(images[i], t, 9, 0, -1, 1, true));
	tmp = min(tmp, dist(images[i], t, 9, 9, -1, -1, false));
	tmp = min(tmp, dist(images[i], t, 9, 9, -1, -1, true));
	if (tmp < mn) {
	    mn = tmp;
	    mi = i;
	}
    }
    cout << chars[mi];
}

void solve()
{
    int m;
    cin >> m;
    rep(i, m)
	solve1();
    cout << endl;
}

int main()
{
    input();
    solve();

    return 0;
}
