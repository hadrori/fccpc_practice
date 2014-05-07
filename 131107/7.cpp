#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i,a,b) for(int i = (a);i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void topological_sort(vector<vi> &G, vi &in, vi & v){
  int n = in.size();
  v.clear();
  queue<int> q;
  rep(i,n) if(!in[i]) q.push(i);
  vector<bool> done(n);
  bool ok = true;
  int cnt = 0;
  while(!q.empty()){
    if(q.size() > 1) ok = false;
    int now = q.front(); q.pop();
    if(done[now]) continue;
    done[now] = true;
    cnt++;
    v.pb(now);
    rep(i,G[now].size()){
      in[G[now][i]]--;
      if(!in[G[now][i]]) q.push(G[now][i]);
    }
  }
}

ll sq(ll a) { return a * a; }
ll dst(ll x1, ll y1, ll x2, ll y2) { return sq(x1 - x2) + sq(y1- y2); }


struct circle {
  ll x, y, r;
};
bool contain(circle c1, circle c2) {
  ll d2 = dst(c1.x, c1.y, c2.x, c2.y);
  if(c1.r <= c2.r) return false;
  return d2 < sq(c1.r - c2.r);
}

bool intersect(circle c1, circle c2) {
  ll d2 = dst(c1.x, c1.y, c2.x, c2.y);
  return d2 <= sq(c1.r + c2.r);
}

int n;
ll xs, ys, xt, yt;
vector<circle> A, B;
vector<ll> x, y, r;
vector<vector<int> > G;
int BASE;
int main(){
  while(cin >> n, n) {
    cin >> xs >> ys >> xt >> yt;
    x.resize(n);
    y.resize(n);
    r.resize(n);
    rep(i, n) cin >> x[i] >> y[i] >> r[i];
    A.clear(); B.clear();
    rep(i, n) {
      bool f1 = (dst(x[i], y[i], xs, ys) < r[i] * r[i] );
      bool f2 = (dst(x[i], y[i], xt, yt) < r[i] * r[i] );
      if(f1 && !f2) {
	A.pb((circle){x[i], y[i], r[i]});
      } else if(!f1 && f2) {
	B.pb((circle){x[i], y[i], r[i]});
      }
    }
    BASE = A.size();

    G.clear();
    G.resize(BASE + B.size() + 2);
    int s = BASE + B.size();
    int t = s + 1;

    
    rep(i, A.size()) G[i].pb(t);
    rep(i, B.size()) G[s].pb(i+BASE);

    rep(i, A.size()) G[s].pb(i);
    rep(i, B.size()) G[i+BASE].pb(t);
    G[s].pb(t);

    // rat to lair
    rep(i, A.size()) rep(j, A.size()) if(i != j) {
      if(contain(A[i], A[j])) G[j].pb(i);
    }

    // lair to cat
    rep(i, A.size()) rep(j, B.size()) {
      if(!intersect(A[i], B[j])) G[i].pb(j + BASE);
    }

    // cat to fish
    rep(i, B.size()) rep(j, B.size()) if(i != j) {
      if(contain(B[i], B[j])) G[i + BASE].pb(j + BASE);
    }

    vector<int> in(G.size());
    rep(i, G.size()) rep(j, G[i].size()) in[G[i][j]]++;
    vector<int> v;
    topological_sort(G, in, v);
    
    vector<ll> len(G.size());
    rep(i, v.size()) {
      rep(j, G[v[i]].size()) len[G[v[i]][j]] = max(len[G[v[i]][j]], len[v[i]] + 1);
    }
    cout << len[t] - 1 << endl;
  }
  return 0;
}
