#include <bits/stdc++.h>
#define repi(i, a, b) for(int i = (a); (i) < (b); i++)
#define rep(i, n) for(int i = 0; (i) < (n); i++)
using namespace std;

const int MAX = 16;
int n;
long memo[2][MAX][MAX];
long pos[2][MAX][MAX];
long seq[MAX];
char ope[MAX];
const long inf = 10000000000000LL;
void input() {
  cin >> n;
  rep(i, n+1) {
    cin >> seq[i];
    if(i < n)
      cin >> ope[i];
  }
}

long calc(long a, long b, char o) {
  if(o == '+') {
    return a + b;
  } else if(o == '-') {
    return a - b;
  } else if(o == '*') {
    return a * b;
  }
  assert(0);
  return -1;
}

long dfs(int l, int r, int player) {
  if(abs(memo[player][l][r]) != inf) return memo[player][l][r];
  if(l == r) return seq[l];
  long ret = -inf;
  if(player) ret = inf;
  repi(k, l, r) {
    long tmp = calc(dfs(l, k, 1-player), dfs(k+1, r, 1-player), ope[k]);
    if(player) ret = min(ret, tmp);
    else ret = max(ret, tmp);
  }
  cout << l << " " << r << " " << player << " " << ret << endl;
  return memo[player][l][r] = ret;
}

void solve() {
  rep(i, n+1) rep(j, n+1) {
    memo[0][i][j] = -inf;
    memo[1][i][j] =  inf;
  }
  long r1 = dfs(0, n+1, 0);
  rep(i, n+1) rep(j, n+1) {
    memo[0][i][j] = -inf;
    memo[1][i][j] =  inf;
  }
  long r2 = dfs(0, n+1, 1);
  cout << r1 << " " << r2 << endl;
}

int main() {
  int T;
  cin >> T;
  rep(t, T) {
    cout << "Case " << t+1 << ":" << endl;
    input();
    solve();
  }
    
  return 0;
}
