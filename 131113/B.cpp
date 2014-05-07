#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>

#define repi(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a); i >= (b); i--)
#define repit(i,a) for(__typedef((a).begin()) i = (a).begin(); i = (a).end(); i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)), (u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define int ll

vector<int> divisor(int x) {
  vector<int> ret;
  int i;
  for(i = 1; i * i < x; i++) {
    if(x % i == 0) {
      ret.pb(i);
      ret.pb(x/i);
    }
  }
  if(x % (i * i)  == 0) ret.pb(i);
  return ret;
}

vector<int> convert(int x, int m) {
  vector<int> ret;
  if(x == 0)
    ret.pb(0);

  while(x) {
    ret.pb(x % m);
    x /= m;
  }
  return ret;
}

signed main(){
  int n, m;
  vector<int> tv;

  while(cin >> n >> m) {
    vector<int> v;
    v = divisor(n);
    vector<vector<int> > mv;
    rep(i, v.size()) mv.pb(convert(v[i], m));
  
    int sum = 0;
    rep(i, mv.size()) {
      rep(j, mv[i].size()) sum += mv[i][j] * mv[i][j];
    }

    vector<int> ans = convert(sum, m);
    reverse(all(ans));
    rep(i, ans.size()) {
      if(ans[i] >= 10) cout << (char)(ans[i]+'A' - 10);
      else cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}
