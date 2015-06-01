#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define all(u) begin(u),end(u)
#define long int64_t

const string name = "joke";
ifstream in(name + ".in");
ofstream out(name + ".out");
#define cin in
#define cout out

string line;
int L;

void input()
{
  cin >> line;
  L = line.length();
}

int n;
vector<char> done;
vector<int> vec;
vector<char> delim;

bool dfs(int k)
{
  if (k == min(10, n+1)) {
    vector<int> one_digit(L);
    for (int e : vec) one_digit[e] = 1;
    vector<int> ans;
    long S = 0;
    rep(i, L) {
      int e = line[i] - '0';
      if (one_digit[i]) {
        S |= 1LL << e, ans.push_back(e);
      } else {
        if (i == L-1 or one_digit[i+1]) return false;
        e = e * 10 + (line[i+1] - '0');
        if (e > n) return false;
        S |= 1LL << e, ans.push_back(e), ++i;
      }
    }
    if (S >> 1 == (1LL << n) - 1 and int(ans.size()) == n) {
      rep(i, n-1) cout << ans[i] << ' ';
      cout << ans.back() << endl;
      return true;
    } else {
      return false;
    }
  }
  vector<int> cand;
  int must = -1;
  rep(i, L) {
    if (!done[i] and line[i] == '0' + k) {
      cand.push_back(i);
      if ((i == 0 and k >= 6) or
          (i >= 1 and (delim[i-1] or line[i-1] >= '6') and (delim[i] or k >= 6))) {
        if (must == -1) {
          must = i;
        } else {
          return false;
        }
      }
    }
  }
  for (int c : cand) {
    if (must != -1 and c != must) continue;
    vector<char> _delim(delim);
    for (int d : cand) {
      if (d == c) {
        if (d >= 1) delim[d-1] = true;
        delim[d] = true;
      } else if (k >= 6) {
        if (d >= 2) delim[d-2] = true;
        delim[d] = true;
      }
    }
    vec.push_back(c);
    if (dfs(k + 1)) return true;
    vec.pop_back();
    delim = move(_delim);
  }
  return false;
}

void solve()
{
  n = 1;
  while (n + max(n - 9, 0) < L) ++n;
  delim.assign(L, 0);
  done.assign(L, 0);
  static vector<int> tmp[100];
  rep(i, L-1) {
    int k = (line[i] - '0') * 10 + (line[i+1] - '0');
    tmp[k].push_back(i);
  }
  repi(k, 10, n+1) {
    if (tmp[k].size() == 1) {
      int i = tmp[k][0];
      done[i] = done[i+1] = true;
      if (i >= 1) delim[i-1] = true;
      if (i+1 < L) delim[i+1] = true;
    }
  }
  dfs(1);
}

int main()
{
  input();
  solve();
}
