#include <bits/stdc++.h>
#define repi(i, a, b) for(int i = (a); (i) < (int)(b); i++)
#define rep(i, n) for(int i = 0; (i) < (int)(n); i++)
using namespace std;
const int inf = 1500000000;
int solve(vector<int> a, int &x) {
  sort(a.begin(), a.end());
  int ai = -1;
  int ad = inf;
  rep(i, a.size()) {
    int tmp = 0;
    rep(j, a.size()) tmp += abs(a[i] - a[j]);
    if(ad > tmp) {
      ad = tmp;
      ai = i;
    }
  }
  x = a[ai];
  return ad;
}

int main() {
  int n;
  int cnt = 0;
  while(cin >> n, n) {
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    int x, y;
    int ans = solve(a, x) + solve(b, y);
    cout << "Case " << ++cnt << ": ";
    cout << "(";
    cout << x;
    cout << ",";
    cout << y;
    cout << ") ";
    cout << ans << endl;
  }
  return 0;
}
