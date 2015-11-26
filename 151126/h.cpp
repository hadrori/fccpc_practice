#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
#define long int64_t

const int inf = 1e9;
struct state {
  int lo, hi;
  state() : lo(-1), hi(-1) {}
  state(int lo, int hi) : lo(lo), hi(hi) {}
  bool empty() const { return lo < 0; }
  bool na() const { return lo == inf; }
};
state& operator +=(state& a, const state& b) {
  if (a.empty()) {
    a = b;
  } else if (a.na() or b.empty()) {
    // nothing
  } else if (not b.na() and a.hi == b.lo - 1) {
    a.hi = b.hi;
  } else {
    a.lo = a.hi = inf;
  }
  return a;
}
struct node {
  int a, b;
  state s;
  node *l = NULL, *r = NULL;
  node(int a, int b) : a(a), b(b) {}
};
node *construct(int a, int b) {
  if (a == b) return NULL;
  node *ret = new node(a, b);
  if (a == b-1) return ret;
  int m = (a + b) / 2;
  ret->l = construct(a, m);
  ret->r = construct(m, b);
  return ret;
}
void push(node *v) {
  if (!v or (!v->l and !v->r)) return;
  if (v->l) v->l->s += v->s;
  if (v->r) v->r->s += v->s;
  v->s = state();
}
void decorate(node *v, int l, int r, state s) {
  if (!v) return;
  if (r <= v->a or v->b <= l) return;
  if (l <= v->a and v->b <= r) {
    v->s += s;
    return;
  }
  push(v);
  if (v->l) decorate(v->l, l, r, s);
  if (v->r) decorate(v->r, l, r, s);
}
int dfs(node *v, int k) {
  if (!v) return 0;
  if (!v->l and !v->r) {
    return v->s.hi == k;
  } else {
    push(v);
    int ret = 0;
    if (v->l) ret += dfs(v->l, k);
    if (v->r) ret += dfs(v->r, k);
    return ret;
  }
}

void solve() {
  int n, k, t;
  cin >> n >> k >> t;
  node *root = construct(0, n);
  decorate(root, 0, n, state(0, 0));
  rep(_, t) {
    int l, r, x;
    cin >> l >> r >> x, --l;
    decorate(root, l, r, state(x, x));
  }
  cout << dfs(root, k) << endl;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
