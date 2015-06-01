#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<int(b);++i)
#define pb push_back
#define mp make_pair
#define long int64_t

void solve() {
  int n;
  cin >> n;
  vector<pair<long, long> > v;
  rep(i, n) {
    long k;
    char c;
    cin >> k >> c;
    if(c == 'B') v.pb(mp(k, 0));
    else v.pb(mp(k, 1));
  }
  
  vector<long> cnts(2);
  rep(i, v.size()) {
    cnts[v[i].second] += v[i].first;
  }
  if(cnts[0] == 0 or cnts[1] == 0) {
    cout << max(cnts[0], cnts[1]) << endl;
    return;
  }

  long c = cnts[0];
  long d = cnts[1];
  long g = __gcd(c, d);
  c /= g; d /= g;
  vector<long> num(2);
  long ans = 0;
  rep(i, v.size()) {
    long a = num[0];
    long b = num[1];
    num[v[i].second] += v[i].first;
    long a_ = num[0];
    long b_ = num[1];
    if(v[i].second == 1) {
      if(a%c != 0) continue;
    } else {
      if(b%d != 0) continue;
    }
    if((b*c < a*d and a_*d <= c*b_) or (b*c > a*d and a_*d >= c*b_))
      ans++;
  }
  cout << ans << endl;
}

int main()
{
  int T;
  cin >> T;
  rep(t, T) solve();

}
