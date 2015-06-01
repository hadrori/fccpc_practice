#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(u) begin(u),end(u)
#define long int64_t

const int K = 28;

long pow5[K] = {1};
long even[K] = {1};

void prepare()
{
  repi(i, 1, K) pow5[i] = pow5[i-1] * 5;
  repi(i, 1, K) {
    if (i & 1) {
      even[i] = even[i-1] * 5;
    } else {
      even[i] = pow5[i-1] * 2 + even[i-1];
    }
  }
}

long n;

void solve()
{
  ++n;
  int a[K] = {};
  rep(i, K) {
    a[i] = n % 5;
    n /= 5;
  }
  long ans = 0, t = 0;
  rep(i, K) {
    if (i & 1 and a[i] & 1) ans = t - ans;
    rep(d, a[i]) {
      if (~i & 1 or ~d & 1) ans += even[i];
      else ans += pow5[i] - even[i];
    }
    t += a[i] * pow5[i];
  }
  cout << ans << endl;
}

int main()
{
  prepare();
  while (cin >> n, n != -1) {
    solve();
  }
}
