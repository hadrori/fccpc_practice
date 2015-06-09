#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<int(b);++i)

const int N = 100010;

ll n, x[N], y[N];

int ans[N];

struct entry {
  int id; ll x, y;
  entry(int id, ll x, ll y) : id(id), x(x), y(y) {}
};

bool above(int i, int j)
{
  return (y[i+1] - y[i]) * (x[j+1] - x[j]) < (y[j+1] - y[j]) * (x[i+1] - x[i]);
}

void solve()
{
  stack<int> stk;
  for (int i = n-2; i >= 0; --i) {
    while (not stk.empty() and not above(i, stk.top())) {
      cerr << i << ' ' << stk.top() << endl;
      stk.pop();
    }
    ans[i] = stk.empty() ? 0 : stk.top();
    stk.push(i);
  }
  rep(i, n-2) printf("%d ", ans[i]);
  printf("%d\n", ans[n-2]);
}

int main()
{
  int t;
  for (scanf("%d", &t); t--; ) {
    scanf("%lld", &n);
    rep(i, n) scanf("%lld%lld", x+i, y+i);
    solve();
  }
}
