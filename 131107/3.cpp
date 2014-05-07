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

ll champer(ll n)
{
  ll ret = 0;
  for (ll d = 1; d <= n; d *= 10)
    ret += n - d + 1;
  return ret;
}

string solve(ll n, ll k)
{
  ll l = 0, r = (int) 1e9;
  while (l + 1 < r) {
    ll m = (l + r) / 2;
    if (champer(m) < n)
      l = m;
    else
      r = m;
  }
  int offset = n - champer(r - 1) - 1;
  ostringstream ret;
  for (ll i = r; ret.str().length() < k + offset; ++i)
    ret << i;
  return ret.str().substr(offset, k);
}

int main()
{
  ll n, k;
  while (cin >> n >> k && n)
    cout << solve(n, k) << endl;

  return 0;
}
