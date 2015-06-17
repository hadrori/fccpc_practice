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
    int n;
    cin >> n;
    vector<int> vec;
    rep(_, n) {
      int t;
      cin >> t;
      vec.pb(t);
    }
    sort(all(vec));
    int ans = 0, j = 1;
    rep(i, n) {
      while (j < n and vec[j] < vec[i] + 32) ++j;
      ans += j - i - 1;
    }
    cout << ans << endl;
  }
    return 0;
}
