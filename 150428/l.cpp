#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<int(b);++i)

struct alien {
  int a, b, d;
  bool dead;
  alien(int a, int b, int d) : a(a), b(b), d(d) {
    dead = false;
  }
  bool operator<(const alien &o) const {
    if(b != o.b) return b < o.b;
    return d > o.d;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<alien> v;
  rep(i, n) {
    int a, b, d;
    cin >> a >> b >> d;
    v.push_back(alien(a, b, d));
  }
  sort(v.begin(), v.end());

  int ans = 0;
  rep(i, n) if(!v[i].dead) {
    int t = v[i].b;
    int R = v[i].d;
    rep(j, n) if(!v[j].dead and v[j].a <= t and t <= v[j].b) {
      R = max(R, v[j].d);
      v[j].dead = true;
    }
    ans += R;
  }
  cout << ans << endl;
}

int main()
{
  int T;
  cin >> T;
  rep(t, T) solve();

}
