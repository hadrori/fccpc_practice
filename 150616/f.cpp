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
#define mp make_pair

typedef long long ll;

struct disjoint_set {
  vector<int> p;
  disjoint_set() {}
  disjoint_set(int n) : p(n, -1) {}
  int root(int i) { return p[i] >= 0 ? p[i] = root(p[i]) : i; }
  bool merge(int i, int j) {
    i = root(i), j = root(j);
    if (i == j) return false;
    if (-p[i] < -p[j]) swap(i, j);
    p[i] += p[j], p[j] = i;
    return true;
  }
  bool same(int i, int j) { return root(i) == root(j); }
};

int main()
{
  int t;
  for (cin >> t; t--; ) {
    int n, m;
    cin >> n >> m;
    disjoint_set ds(n + 27);
    string s;
    cin >> s;
    rep(i, n) if (s[i] != '?') {
      ds.merge(i, n + s[i] - 'a');
    }
    rep(i, n) ds.merge(i, n-i-1);
    rep(_, m) {
      int a, b;
      cin >> a >> b;
      ds.merge(a-1, b-1);
    }
    const ll mod = 1000000007;
    ll ans = 1;
    rep(i, 26) repi(j, i+1, 26) {
      if (ds.same(n+i, n+j)) ans = 0;
    }
    rep(i, 26) ds.merge(n+i, n+26);
    rep(i, n) if (ds.root(i) == i) {
      if (not ds.same(i, n+26)) {
	ans = ans * 26 % mod;
      }
    }
    cout << ans << endl;
  }
    return 0;
}
