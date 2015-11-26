#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
#define long int64_t

vector<int> cat(const vector<int>& a, const vector<int>& b) {
  const int n = a.size();
  vector<int> ret(n);
  rep(i, n) ret[i] = a[b[i]];
  return ret;
}
vector<int> repeat(const vector<int>& a, int k) {
  const int n = a.size();
  vector<int> ret(n), done(n);
  rep(i, n) if (not done[i]) {
    vector<int> orbit;
    orbit.push_back(i);
    for (int t = a[i]; t != i; t = a[t]) {
      orbit.push_back(t);
    }
    int len = orbit.size();
    rep(j, len) {
      done[orbit[j]] = 1;
      ret[orbit[j]] = orbit[(j+k)%len];
    }
  }
  return ret;
}

int n, L;
string op;

void input() {
  cin >> n >> L >> op;
}

int parseNumber(int& i) {
  int ret = 0;
  while (isdigit(op[i])) {
    ret *= 10, ret += op[i] & 15;
    ++i;
  }
  return ret;
}
vector<int> parseExpr(int& i);
vector<int> parseTerm(int& i) {
  if (op[i] == '(') {
    auto tmp = parseExpr(++i);
    int t = parseNumber(++i);
    return repeat(tmp, t);
  } else {
    char dir = op[i];
    int t = parseNumber(++i) - 1;
    vector<int> ret(n*n);
    iota(all(ret), 0);
    if (dir == 'L') {
      rep(j, n-1) swap(ret[t*n + j], ret[t*n + j+1]);
    } else if (dir == 'R') {
      for(int j=n-2;j>=0;--j) swap(ret[t*n + j], ret[t*n + j+1]);
    } else if (dir == 'U') {
      rep(j, n-1) swap(ret[j*n + t], ret[(j+1)*n + t]);
    } else if (dir == 'D') {
      for(int j=n-2;j>=0;--j) swap(ret[j*n + t], ret[(j+1)*n + t]);
    }
    return ret;
  }
}
vector<int> parseExpr(int& i) {
  vector<int> ret = parseTerm(i);
  while (i < (int)op.length() and op[i] != ')') {
    ret = cat(ret, parseTerm(i));
  }
  return ret;
}

void solve() {
  int pos = 0;
  auto ans = parseExpr(pos);
  rep(i, n) rep(j, n) cout << ans[i*n + j] + 1 << (j<n-1 ? ' ' : '\n');
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  input();
  solve();
  return 0;
}
