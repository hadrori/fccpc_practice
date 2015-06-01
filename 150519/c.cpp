#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(u) begin(u),end(u)
template<class T>inline bool chmin(T&a,const T&b){return a>b?a=b,1:0;}

const int N = 200;

int n, m;
double x[N], y[N], z[N], d[N][N];

inline double sq(double x) { return x * x; }
inline double dist(int i, int j) {
  return sqrt(sq(x[i]-x[j]) + sq(y[i]-y[j]) + sq(z[i]-z[j]));
}

void input()
{
  cin >> n >> m;
  rep(i, n) {
    cin >> z[i] >> x[i] >> y[i], z[i] *= 5.0;
  }
  rep(i, n) rep(j, n) d[i][j] = 1e9;
  rep(i, n) d[i][i] = 0.0;
  rep(_, m) {
    int u, v; string s;
    cin >> u >> v >> s;
    if (s == "lift") {
      chmin(d[u][v], 1.0);
      chmin(d[v][u], 1.0);
    } else if (s == "escalator") {
      chmin(d[u][v], 1.0);
      chmin(d[v][u], dist(u, v) * 3.0);
    } else {
      chmin(d[u][v], dist(u, v));
      chmin(d[v][u], dist(u, v));
    }
  }
}

int mid[N][N];

void dfs(int s, int t, vector<int>& vec)
{
  const int m = mid[s][t];
  if (m == -1) return;
  dfs(s, m, vec);
  vec.push_back(m);
  dfs(m, t, vec);
}

void solve()
{
  rep(i, n) rep(j, n) mid[i][j] = -1;
  rep(k, n) rep(i, n) rep(j, n) {
    if (chmin(d[i][j], d[i][k] + d[k][j])) {
      mid[i][j] = k;
    }
  }
  int q;
  for (cin >> q; q--; ) {
    int s, t;
    cin >> s >> t;
    vector<int> ans;
    ans.push_back(s);
    dfs(s, t, ans);
    ans.push_back(t);
    rep(i, ans.size()) {
      if (i) cout << ' ';
      cout << ans[i];
    }
    cout << endl;
  }
}

int main()
{
  input();
  solve();
}
