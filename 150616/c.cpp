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

int main()
{
  int t;
  for (cin >> t; t--; ) {
    int k, m, n, a[128];
    cin >> k >> m >> n;
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    int s = accumulate(a, a + n, 0);
    int space = k - s, ans = 0;
    for (int i = n-1; space < m; --i) {
      space += a[i];
      ++ans;
    }
    cout << ans << endl;
  }
    return 0;
}
