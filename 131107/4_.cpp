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
  int x, y; int id;
  futon(int x, int y, int id) : x(x), y(y), id(id) {}
};

map<pair<int, int>, int> ftn;

void input()
{
  v.clear();
  mem.clear();
  int id = 0;
  rep(i, n) {
    int x, y; char dir;
    cin >> x >> y >> dir;
    ftn[mp(x, y)] = id;
    if(dir == 'x') ftn[mp(x+1, y)] = id;
    else ftn[mp(x, y+1)] = id;
    id++;
  }
}

struct edge
{
  int to, rev;
  edge(int to, int rev) : to(to), rev(rev) {}
};

vector<vector<edge> > G;

void gen() {
  repit(itr, ftn) {
    ll x = itr->x;
    ll y = itr->y;
    const ll dx[] = {-1, 0, 1, 0};
    const ll dy[] = {0, -1, 0, 1};
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
