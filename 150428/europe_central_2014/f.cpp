#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<int(b);++i)

const int sigma = 26;
int id[256], coef[sigma+2][sigma+2][sigma+2][4][4];

void prepare()
{
  rep(a, sigma+1) rep(b, sigma+1) rep(c, sigma+1) rep(ord, 4) {
    if (!(ord & 2) and a > b) continue;
    if (!(ord & 1) and b > c) continue;
    rep(mask, 8) {
      if (a == 0 and (mask & 4)) continue;
      if (b == 0 and (mask & 2)) continue;
      if (c == 0 and (mask & 1)) continue;
      int na = mask & 4 ? sigma+1 : a;
      int nb = mask & 2 ? sigma+1 : b;
      int nc = mask & 1 ? sigma+1 : c;
      int nord = ord;
      if (a < b) nord |= 2;
      if (b < c) nord |= 1;
      ++coef[na][nb][nc][ord][nord];
    }
  }
  rep(i, 256) id[i] = i - 'a' + 1;
  id[int(' ')] = 0;
  id[int('?')] = sigma+1;
}

const int N = 1<<20;
const ll mod = 1000000009;

char line[3][N];
int len[3];

int chomp(char *s)
{
  int ret = strlen(s);
  if (s[ret-1] == '\n') s[--ret] = '\0';
  return ret;
}

ll dp[N][4] = {1};

void solve()
{
  const int n = *max_element(len, len + 3);
  rep(i, 3) repi(j, len[i], n) line[i][j] = ' ';
  rep(i, n) {
    rep(j, 4) dp[i+1][j] = 0;
    rep(ord, 4) rep(nord, 4) {
      ll &t = dp[i+1][nord];
      t += coef[id[int(line[0][i])]][id[int(line[1][i])]][id[int(line[2][i])]][ord][nord] * dp[i][ord] % mod;
      if (t >= mod) t -= mod;
    }
  }
  printf("%lld\n", dp[n][3]);
}

int main()
{
  prepare();
  int t;
  for (scanf("%d ", &t); t--; ) {
    rep(i, 3) fgets(line[i], N, stdin), len[i] = chomp(line[i]);
    solve();
  }
}
