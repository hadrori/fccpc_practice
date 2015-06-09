#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<int(b);++i)

void solve(ll n)
{
  const ll m = 2 * n;
  for (ll p = 2; p * p < m; ++p) {
    if (m % p == 0 and (p ^ m / p) & 1) {
      const ll q = m / p;
      const ll a = (q - p + 1) / 2;
      const ll b = q - a;
      printf("%lld = %lld", n, a);
      for (ll i = a+1; i <= b; ++i) {
        printf(" + %lld", i);
      }
      puts("");
      return;
    }
  }
  puts("IMPOSSIBLE");
}

int main()
{
  int t;
  for (cin >> t; t--; ) {
    int n;
    cin >> n;
    solve(n);
  }
}
