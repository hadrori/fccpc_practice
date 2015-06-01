#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define all(u) begin(u),end(u)
#define long int64_t

ifstream in("knockout.in");
ofstream out("knockout.out");
#define cin in
#define cout out

const int N = 1024;

long n, m, a[N], b[N];

void input()
{
  cin >> n >> m;
  rep(i, n) cin >> a[i] >> b[i];
}

long pos(int i, long t)
{
  long d = abs(b[i] - a[i]);
  long x = t % (2 * d);
  if (x > d) x = 2 * d - x;
  return a[i] < b[i] ? a[i] + x : a[i] - x;
}

void solve()
{
  rep(_, m) {
    long x, y, t;
    cin >> x >> y >> t;
    int ans = 0;
    rep(i, n) {
      long p = pos(i, t);
      ans += x <= p and p <= y;
    }
    cout << ans << endl;
  }
}

int main()
{
  input();
  solve();
}
