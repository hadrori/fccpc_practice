#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<int(b);++i)

const int N = 1024;

int n, x[N], y[N], r[N];

void input()
{
  cin >> n;
  rep(i, n) {
    cin >> x[i] >> y[i] >> r[i];
  }
}

inline int sq(int n) { return n * n; }
inline bool touch(int i, int j) { return sq(x[i] - x[j]) + sq(y[i] - y[j]) == sq(r[i] + r[j]); }

bool done[N], ccw[N];

void solve()
{
  rep(i, n) done[i] = false;
  queue<int> que;
  done[0] = true, ccw[0] = false, que.push(0);
  while (not que.empty()) {
    int v = que.front();
    que.pop();
    rep(nv, n) if (not done[nv] and touch(v, nv)) {
      done[nv] = true, ccw[nv] = !ccw[v], que.push(nv);
    }
  }
  rep(i, n) {
    if (done[i]) {
      int p = abs(r[0]), q = abs(r[i]);
      int g = __gcd(p, q);
      p /= g, q /= g;
      cout << p;
      if (q > 1) cout << '/' << q;
      cout << ' ';
      if (ccw[i]) cout << "counter";
      cout << "clockwise\n";
    } else {
      cout << "not moving\n";
    }
  }
}

int main()
{
  int t;
  for (cin >> t; t--; ) {
    input();
    solve();
  }
}
