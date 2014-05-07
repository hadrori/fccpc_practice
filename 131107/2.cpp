#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
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

int n, d, sum;
vector<vector<int> > c;
vector<int> f;

void input()
{
  sum = 0;
  c.assign(n, vector<int>());
  f.assign(n, 0);
  rep(i, n) {
    int m; cin >> m;
    sum += m;
    c[i].resize(m);
    rep(j, m)
      cin >> c[i][j];
    f[i] = accumulate(c[i].begin(), c[i].end(), 0);
  }
}

bool solve()
{
  if (n <= 1)
    return true;

  bool loop = true;
  while (loop) {
    loop = false;
    int fst = f[0];
    int snd = f[1];
    if (snd > fst)
      swap(fst, snd);
    repi(i, 2, n) {
      if (f[i] > snd) {
	snd = f[i];
	if (snd > fst)
	  swap(fst, snd);
      }
    }

    int update = -1;
    rep(i, n) {
      if (c[i].empty())
	continue;

      int after = f[i] - c[i].back();
      if (f[i] < fst) {
	if (after >= fst - d) {
	  update = i;
	  break;
	}
      } else {
	if (after >= snd - d) {
	  update = i;
	  break;
	}
      }
    }

    if (update >= 0) {
      loop = true;
      f[update] -= c[update].back();
      c[update].pop_back();
      --sum;
    }
  }

  return !sum;
}

int main()
{
  while (cin >> n >> d && n) {
    input();
    cout << (solve() ? "Yes" : "No") << endl;
  }

  return 0;
}
