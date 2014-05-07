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

#define repi(i,a,b) for(int i = (a);i < (b); i++)
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

int n;

struct futon
{
  int x, y; bool dir;
  futon(int x, int y, bool dir) : x(x), y(y), dir(dir) {}
};

vector<futon> v;
map<pair<int, int>, int> mem;

void input()
{
  v.clear();
  mem.clear();
  rep(i, n) {
    int x, y; char dir;
    cin >> x >> y >> dir;
    v.pb(futon(x, y, dir == 'x'));
    mem[mp(x, y)] = i;
  }
}

struct edge
{
  int to, rev;
  edge(int to, int rev) : to(to), rev(rev) {}
};

vector<vector<edge> > G;

const int dx1[] = {-2, -1, -1, 0, 0, 1, 1, 2};
const int dy1[] = {0, -1, 1, -1, 1, -1, 1, 0};
const int rev1[] = {-1, -1, -1, 1, 1, -1, -1, -1};

const int dx2[] = {-1, -1, 0, 0, 1, 1, 2, 2};
const int dy2[] = {-1, 0, -2, 1, -2, 1, -1, 0};
const int rev2[] = {-1, 1, -1, 1, 1, -1, 1, -1};

void gen()
{
  G.assign(n, vector<edge>());
  rep(i, n) {
    int x = v[i].x, y = v[i].y;
    if (v[i].dir) {
      rep(j, 8) {
	map<pair<int,int>,int>::iterator it = mem.find(mp(x + dx1[j], y + dy1[j]));
	if (it != mem.end()) {
	  int k = it->second;
	  if (v[k].dir) {
	    G[i].pb(edge(k, rev1[j]));
	    G[k].pb(edge(i, rev1[j]));
	  }
	}
	it = mem.find(mp(x + dx2[j], y + dy2[j]));
	if (it != mem.end()) {
	  int k = it->second;
	  if (!v[k].dir) {
	    G[i].pb(edge(k, rev2[j]));
	    G[k].pb(edge(i, rev2[j]));
	  }
	}
      }
    } else {
      rep(j, 8) {
	map<pair<int,int>,int>::iterator it = mem.find(mp(x + dy1[j], y + dx1[j]));
	if (it != mem.end()) {
	  int k = it->second;
	  if (!v[k].dir) {
	    G[i].pb(edge(k, rev1[j]));
	    G[k].pb(edge(i, rev1[j]));
	  }
	}
	it = mem.find(mp(x + dy2[j], y + dx2[j]));
	if (it != mem.end()) {
	  int k = it->second;
	  if (v[k].dir) {
	    G[i].pb(edge(k, rev2[j]));
	    G[k].pb(edge(i, rev2[j]));
	  }
	}
      }
    }
  }
}

vector<int> color;

bool bicolor(int v, int c)
{
  if (color[v])
    return color[v] == c;

  color[v] = c;
  rep(i, G[v].size())
    if (!bicolor(G[v][i].to, G[v][i].rev * c))
      return false;
  return true;
}

bool solve()
{
  color.assign(n, 0);
  rep(i, n)
    if (!color[i] && !bicolor(i, 1))
      return false;
  return true;
}

int main()
{
  while (cin >> n && n) {
    input();
    gen();
    cout << (solve() ? "Yes" : "No") << endl;
  }

  return 0;
}
