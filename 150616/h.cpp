#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long ll;

int n, m;
vector<vector<pair<int, int>>> G;

void input()
{
  cin >> n >> m;
  G.assign(n, vector<pair<int, int>>());
  rep(_, m) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u-1].eb(v-1, w);
    G[v-1].eb(u-1, w);
  }
}

typedef vector<vector<pair<int, int>>> graph;
class bridge {
  const int n;
  graph G;
  int cnt;
  vector<int> num, low, in;
  stack<int> stk;
  vector<tuple<int, int, int>> brid;
  vector<vector<int>> comp;
  void dfs(int v, int u, int wt) {
    num[v] = low[v] = ++cnt;
    stk.push(v), in[v] = true;
    for (auto p : G[v]) {
      int nv = p.first;
      int nwt = p.second;
      if (num[nv] == 0) {
	dfs(nv, v, nwt);
	low[v] = min(low[v], low[nv]);
      } else if (nv != u and in[nv]) {
	low[v] = min(low[v], num[nv]);
      }       
    }
    if (low[v] == num[v]) {
      if (u != n) brid.eb(min(v, u), max(v, u), wt);
      comp.eb();
      int w;
      do {
	w = stk.top();
	stk.pop(), in[v] = false;
	comp.back().pb(w);
      } while (w != v);
    }
  }
public:
  bridge(const graph& G) : n(G.size()), G(G), cnt(0), num(n), low(n), in(n) {
    rep(i, n) if (num[i] == 0) dfs(i, n, -1);
  }
  vector<tuple<int, int, int>> get() {
    return brid;
  }
  vector<vector<int>> components() {
    return comp;
  }
};

const int N = 100010;

vector<vector<pair<int, int>>> T;
bool done[N];
ll V;
vector<int> id;
vector<ll> to_leaf[N];

void dfs(int v)
{
  done[v] = true;
  to_leaf[v].pb(0);
  for (auto p : T[v]) {
    int c, w;
    tie(c, w) = p;
    if (done[c]) continue;
    dfs(c);
    to_leaf[v].pb(w + to_leaf[c][0]);
  }
  sort(all(to_leaf[v]), greater<ll>());
}

pair<ll, int> dfs1(int v, ll d)
{
  done[v] = true;
  pair<ll, int> ret(max(to_leaf[v][0], d), id[v]);
  for (auto p : T[v]) {
    int c, w;
    tie(c, w) = p;
    if (done[c]) continue;
    ll d1 = d + w;
    if (to_leaf[v].size() >= 2) {
      ll tmp = w + to_leaf[c][0];
      if (tmp == to_leaf[v][0]) {
	d1 = max(d1, w + to_leaf[v][1]);
      } else {
	d1 = max(d1, w + to_leaf[v][0]);
      }
    }
    ret = min(ret, dfs1(c, d1));
  }
  return ret;
}

void solve()
{
  bridge br(G);
  auto C = br.components();
  auto brid = br.get();
  vector<int> zip(n);
  {
    rep(i, C.size()) {
      for (int v : C[i]) {
	zip[v] = i;
      }
    }
  }
  V = C.size();
  id.assign(V, n);
  rep(i, C.size()) {
    for (int v : C[i]) {
      id[i] = min(id[i], v);
    }
  }
  T.assign(V, vector<pair<int, int>>());
  for (auto b : brid) {
    int u, v, w;
    tie(u, v, w) = b;
    u = zip[u], v = zip[v];
    T[u].eb(v, w);
    T[v].eb(u, w);
  }
  rep(i, V) to_leaf[i].clear();
  fill_n(done, V, false);
  dfs(0);
  fill_n(done, V, false);
  auto ans = dfs1(0, 0);
  cout << ans.second + 1 << ' ' << ans.first << endl;
}

int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  for (cin >> t; t--; ) {
    input();
    solve();
  }
    return 0;
}
