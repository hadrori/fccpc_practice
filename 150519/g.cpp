#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(u) begin(u),end(u)

const int N = 128;

int n;
bool A[N][N];

void input()
{
  cin >> n;
  int a, b;
  while (cin >> a >> b) {
    b = -b;
    A[a-1][b-1] = A[b-1][a-1] = true;
  }
}

int rest, ans[N], blocked[N];

bool dfs()
{
  if (rest == 0) {
    rep(i, n) cout << i + 1 << ' ' << ans[i] + 1 << endl;
    return true;
  }
  rep(v, n) if (blocked[v] == 15) return false;
  struct entry {
    int block, v, color;
    entry(int block, int v, int color) : block(block), v(v), color(color) {}
    bool operator <(const entry& t) const { return block > t.block; }
  };
  vector<entry> cands;
  rep(v, n) if (ans[v] == -1) {
    rep(c, 4) if (~blocked[v] >> c & 1) {
      int b = __builtin_popcount(blocked[v]) << 8;
      rep(u, n) if (A[v][u]) {
        if (~blocked[u] >> c & 1) ++b;
      }
      cands.emplace_back(b, v, c);
    }
  }
  sort(all(cands));
  int _blocked[N];
  for (auto cand : cands) {
    copy_n(blocked, n, _blocked);
    --rest;
    ans[cand.v] = cand.color;
    rep(u, n) if (A[cand.v][u]) {
      blocked[u] |= 1 << cand.color;
    }
    if (dfs()) return true;
    copy_n(_blocked, n, blocked);
    ans[cand.v] = -1;
    ++rest;
  }
  return false;
}

void solve()
{
  rest = n;
  fill_n(ans, n, -1);
  dfs();
}

int main()
{
  input();
  solve();
}
