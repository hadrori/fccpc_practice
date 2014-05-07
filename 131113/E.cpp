#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>

#define repi(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a); i >= (b); i--)
#define repit(i,a) for(__typedef((a).begin()) i = (a).begin(); i = (a).end(); i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)), (u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int M = 150;

int N, D, x[M], y[M], d[M][M];

inline int sq(int n) { return n * n; }

void input()
{
  rep(i, N)
    cin >> x[i] >> y[i];
  rep(i, N) rep(j, N)
    d[i][j] = int(ceil(sqrt(sq(x[i] - x[j]) + sq(y[i] - y[j]))));
}

vector<bool> gas, ved;

int dfs(int i)
{
  if (!gas[i] || ved[i]) return 0;
  ved[i] = true;

  int ret = 1;
  rep(j, N) if (d[i][j] <= D)
    ret += dfs(j);
  return ret;
}

bool attempt()
{
  rep(i, N) {
    if (!gas[i]) {
      int mn = INF;
      rep(j, N) if (gas[j])
	mn = min(mn, d[i][j]);
      if (2 * mn > D)
	return false;
    }
  }

  ved.assign(N, false);
  return dfs(0) == count(all(gas), true);
}

void solve()
{
  gas.assign(N, false);

  repd(i, N - 1, 1) {
    fill(gas.begin(), gas.begin() + i, true);
    gas[i] = false;
    if (!attempt()) {
      gas[i] = true;
      if (!attempt()) {
	cout << "-1" << endl;
	return;
      }
    }
  }

  bool flg = false;
  repd(i, N - 1, 0) {
    flg |= gas[i];
    if (flg) cout << (gas[i] ? 1 : 0);
  }
  cout << endl;
}

int main()
{
  while (cin >> N >> D && N) {
    input();
    solve();
  }

  return 0;
}
