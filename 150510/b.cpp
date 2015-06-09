#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(int)(b);++i)
#define all(u) begin(u),end(u)

const string name = "burrito";
ifstream in(name + ".in");
ofstream out(name + ".out");
#define cin in
#define cout out

int n, A, B;
vector<double> g, a, b;

struct node {
  double w, v, used, b;
  int id;
  node(double g, double a, double b, int id) : b(b), id(id) {
    w = g * b;
    v = a/b;
    used = 0;
  }
  node() {}
  bool operator<(const node &o) {
    return v < o.v;
  }
};
const double eps = 1e-10;
void input()
{
  cin >> n >> A >> B;
  g = vector<double>(n);
  a = vector<double>(n);
  b = vector<double>(n);
  rep(i, n) cin >> g[i] >> a[i] >> b[i];
}

void solve()
{
  vector<node> v;
  double V = 0;
  vector<double> ans(n);
  rep(i, n) {
    if(abs(b[i]) < eps) V += g[i] * a[i], ans[i] = g[i];
    else v.push_back(node(g[i], a[i], b[i], i));
  }
  sort(v.rbegin(), v.rend());

  double W = 0;
  
  rep(i, v.size()) {
    double u = min(B-W, v[i].w);
    W += u;
    v[i].used += u/v[i].b;
    V += v[i].v * u;
  }
  
  rep(i, v.size()) {
    ans[v[i].id] = v[i].used;
  }
  if(abs(V) < eps) V = 0.0;
  if(V < A - eps) {
    cout << -1 << " " << -1 << endl;
  } else {
    cout << fixed << setprecision(10) << V << " " << W << endl;
    rep(i, n) {      
      cout << ans[i];
      if(i < n-1) cout << " ";
    }
    cout << endl;
  }

}

int main()
{
  input();
  solve();
}
