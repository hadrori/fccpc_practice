#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

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

int n, a, s, g;
vector<string> labels[42][42];

string solve()
{
  bool valid[42] = {};
  valid[g] = true;
  vector<string> cur(n, "");
  /*
  vector<bool> arege(n, false);
  vector<int> next(n, -1);
  set<pair<pair<int, int>, int> > used;
  */
  // bool changed = true;
  // while (changed) {
  rep(superstep, 20 * n) {
    // changed = false;
    rep(j, n) {
      if (!valid[j]) continue;
      rep(i, n) {
	rep(k, (int) labels[i][j].size()) {
	  string tmp(all(labels[i][j][k]));
	  tmp.insert(tmp.end(), all(cur[j]));
	  if (!valid[i] || tmp < cur[i]) {
	    valid[i] = true;
	    cur[i] = tmp;
	    /*
	    if (used.find(mp(mp(i, j), k)) != used.end())
	      arege[i] = true;
	    else
	      changed = true;
	    next[i] = j;
	    used.insert(mp(mp(i, j), k));
	    */
	    if (i == s && superstep >= 10 * n)
	      return "NO";
	  }
	}
      }
    }
  }

  if (!valid[s])
    return "NO";
  /*
  int v = s;
  while (next[v] >= 0) {
    if (arege[v])
      return "NO";
    v = next[v];
  }
  */
  return cur[s];
}

int main() {
  while (cin >> n >> a >> s >> g && n) {
    rep(i, 42) rep(j, 42) labels[i][j].clear();
    rep(i, a) {
      int x, y; string lab;
      cin >> x >> y >> lab;
      labels[x][y].pb(lab);
    }

    cout << solve() << endl;
  }

  return 0;
}


