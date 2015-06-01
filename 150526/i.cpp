#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
#define mp make_pair
#define all(u) (u).begin(),(u).end()

int n, w;
double u, v, t1, t2;

int main()
{
  vector<pair<double, int>> eve;
  cin >> n >> w >> u >> v >> t1 >> t2;
  eve.emplace_back(t1, 1);
  eve.emplace_back(t2, -1);
  rep(i, n) {
    char dir;
    int m;
    cin >> dir >> m;
    rep(_, m) {
      double l, p;
      cin >> l >> p;
      if (dir == 'E') p = -p;
      eve.emplace_back(p/u - (i+1)*w/v, -1);
      eve.emplace_back((p+l)/u - i*w/v, 1);
    }
  }
  eve.emplace_back(1e9, -1);
  sort(all(eve));
  double ans = 0.0, last = 0.0;
  int t = 0;
  for (auto p : eve) {
    if (t == 1) ans = max(ans, p.first - last);
    last = p.first;
    t += p.second;
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
