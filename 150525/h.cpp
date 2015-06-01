#include <bits/stdc++.h>
#define repi(i, a, b) for(int i = (a); (i) < (int)(b); i++)
#define rep(i, n) for(int i = 0; (i) < (int)(n); i++)
#define eb emplace_back
using namespace std;

const int inf = 1e9;
struct edge {
  int to, cap, cost, rev;
  edge(int to, int cap, int cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
};
typedef vector<vector<edge> > graph;

void add_edge(graph& G, int from, int to, int cap, int cost) {
  G[from].eb(to, cap, cost, G[to].size());
  G[to].eb(from, 0, -cost, G[from].size() - 1);
}

int min_cost_flow(graph& G, int s, int t, int f) {
  const int n = G.size();
  struct state {
    int v, d;
    state(int v, int d) : v(v), d(d) {}
    bool operator <(const state& t) const { return d > t.d; }
  };

  int ret = 0;
  vector<int> h(n, 0), dist, prev(n), prev_e(n);
  while (f > 0) {
    dist.assign(n, inf);
    priority_queue<state> q;
    dist[s] = 0, q.emplace(s, 0);
    while (not q.empty()) {
      const int v = q.top().v;
      const int d = q.top().d;
      q.pop();
      if (dist[v] < d) continue;
      rep(i, G[v].size()) {
        const edge& e = G[v][i];
        if (e.cap > 0 and dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prev[e.to] = v, prev_e[e.to] = i;
          q.emplace(e.to, dist[e.to]);
        }
      }
    }
    if (dist[t] == inf) return -1;
    rep(i, n) h[i] += dist[i];

    int d = f;
    for (int v = t; v != s; v = prev[v]) {
      d = min(d, G[prev[v]][prev_e[v]].cap);
    }
    f -= d, ret += d * h[t];
    for (int v = t; v != s; v = prev[v]) {
      edge& e = G[prev[v]][prev_e[v]];
      e.cap -= d, G[v][e.rev].cap += d;
    }
  }
  return ret;
}

const int MAX = 64;
int a[MAX][MAX], b[MAX][MAX];
void solve(int n) {
  rep(i, n) rep(j, n) cin >> a[i][j];
  rep(i, n) rep(j, n) cin >> b[i][j];
  
  
  int s = 2*n, t = s+1;
  graph G(t+1);
  rep(i, n) add_edge(G, s, i, 1, 0);
  rep(j, n) add_edge(G, j+n, t, 1, 0);
  rep(i, n) rep(j, n) {
    add_edge(G, i, j+n, 1, a[i][j]);
  }

  min_cost_flow(G, s, t, n);
  vector<int> worker(n), job(n);
  rep(i, n) {
    for(edge e : G[i]) {
      if(e.to >= n and e.to < 2*n and e.cap == 0) {
        worker[e.to - n] = i;
        job[i] = e.to - n;
      }
    }
  }

  G.assign(t+1, vector<edge>());
  rep(i, n) add_edge(G, s, i, 1, 0);
  rep(j, n) add_edge(G, j+n, t, 1, 0);
  rep(i, n) rep(j, n) {
    int w = max(0, a[worker[j]][j] - a[i][job[i]]);
    add_edge(G, i, j+n, 1, w + b[i][j]);
  }
  min_cost_flow(G, s, t, n);

  vector<int> worker2(n), job2(n);
  rep(i, n) {
    for(edge e : G[i]) {
      if(e.to >= n and e.to < 2*n and e.cap == 0) {
        worker2[e.to - n] = i;
        job2[i] = e.to - n;
      }
    }
  }

  int times = 0;
  rep(i, n) {
    cout << "Worker " << i+1 << ": ";
    cout << job[i]+1 << " " << job2[i]+1 << " ";
    cout << a[i][job[i]] + b[i][job2[i]] + max(0, a[worker[job2[i]]][job2[i]] - a[i][job[i]]) << endl;
    times += max(0, a[worker[job2[i]]][job2[i]] - a[i][job[i]]);
  }
  
  cout << "Total idle time: " << times << endl;
  
}

int main() {
  int n;
  int t = 0;
  while(cin >> n, n) {
    cout << "Case " << ++t << ":" << endl;
    solve(n);
  }
  
  return 0;
}
