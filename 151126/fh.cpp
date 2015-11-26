#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
#define long int64_t

const int MX = 10010;

int n, A, B, C, m, a[MX], b[MX], c[MX];
vector<int> ms;
vector<vector<int>> G, H, gs, dists;
map<int,int> zip;

void input_group(int len) {
  vector<int> g(len);
  rep(i,len) {
    cin >> g[i];
    g[i]--;
  }
  ms.pb(*min_element(all(g)));
  rep(i,len) zip[g[i]] = ms.back();
  gs.pb(g);
}

void input() {
  cin >> n >> A >> B >> C;
  G.assign(n,vector<int>());
  rep(i,n) zip[i] = i;
  input_group(A);
  input_group(B);
  input_group(C);
  cin >> m;
  int x, y;
  rep(i,m) {
    cin >> x >> y;
    x = zip[x-1];
    y = zip[y-1];
    G[x].pb(y);
    G[y].pb(x);
  }
}

void bfs(int root, vector<int> &dist) {
  dist.assign(n,-1);
  dist[root] = 0;
  queue<int> q;
  q.push(root);
  while(!q.empty()) {
    int v = q.front(); q.pop();
    for(auto &w: H[v]) if(dist[w] < 0) {
	dist[w] = dist[v] + 1;
	q.push(w);
    }
  }
}

vector<vector<int>> hs;

void solve() {
  set<int> ss[3];
  vector<bool> used(3,false);
  rep(i,3) rep(j,3) if(i != j)
    if(find(all(G[ms[i]]), ms[j]) != end(G[ms[i]])) ss[i].insert(j);
  rep(i,3) if(!used[i]) {
    vector<int> vs = gs[i];
    for(int j: ss[i]) {
      vs.insert(end(vs), all(gs[j]));
      used[j] = 1;
    }
    hs.pb(vs);
  }

  int l = hs.size();
  // rep(i,l) {
  //   rep(j,hs[i].size()) cerr << hs[i][j] << ' '; cerr << endl;
  // }
  ms.clear();
  H.assign(n,vector<int>());
  rep(i,l) ms.pb(*min_element(all(hs[i])));
  rep(i,l) for(int &v: hs[i]) zip[v] = ms[i];
  rep(i,n) for(int &v: G[i]) H[zip[i]].pb(zip[v]);
  dists.resize(l);

  rep(i,l) bfs(ms[i], dists[i]);
  // rep(i,l) {
  //   cerr << ms[i] << endl;
  //   rep(j,n) cerr << dists[i][j] << ' '; cerr << endl;
  // }
  //cerr << l << endl;
  int ansd = 1e9, ans = -1;
  rep(i,n) if(zip[i] == i) {
    int val = 0;
    //cerr << i << endl;
    rep(j,l) val += dists[j][i];
    //rep(j,l) cerr << dists[j][i] << ' '; cerr << endl;
    if(ansd > val) {
      ansd = val;
      ans = i;
    }
  }
  ansd += 3-l;
  cout << ansd << ' ' << ans+1 << endl;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  input();
  solve();
  return 0;
}
