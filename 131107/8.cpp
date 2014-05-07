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

const int N = 80010;

int len;
char line[N];

int dp[N][11];

int solve()
{
  memset(dp, 0, sizeof(dp));
  rep(i, len) {
    int d = line[i] - '0';
    dp[i + 1][d] = !!d;
    rep(j, 11)
      dp[i + 1][j] += dp[i][(d - j + 11) % 11];
  }

  int ret = 0;
  rep(i, len)
    ret += dp[i + 1][0];
  return ret;
}

int main()
{
  while (fgets(line, sizeof(line), stdin), *line != '0') {
    len = strlen(line);
    line[--len] = '\0';
    printf("%d\n", solve());
  }

  return 0;
}
