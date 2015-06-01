#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
#define mp make_pair
#define all(u) (u).begin(),(u).end()


bool check_sub(const string &s, const string &t) {
  int j = 0;
  rep(i, s.size()) {
    if(s[i] == t[j]) j++;
    if(j == (int)t.size()) return true;
  }
  return false;
}

int main()
{
  int n;
  string s;
  cin >> n;
  cin >> s;
  vector<string> vs(n);
  rep(i, n) cin >> vs[i];
  rep(i, n) rep(j, n-1) if(vs[j].size() > vs[j+1].size())
    swap(vs[j], vs[j+1]);

  bool ok = true;
  rep(i, n) if(!check_sub(s, vs[i]))
    ok = false;
  string before = "";
  vector<string> ans1, ans2;
  vector<bool> used(n);
  rep(i, n) {
    if(check_sub(vs[i], before)) {
      used[i] = true;
      ans1.pb(vs[i]);
      before = vs[i];
    }
  }
  before = "";
  rep(i, n) {
    if(!used[i] and check_sub(vs[i], before)) {
      used[i] = true;
      ans2.pb(vs[i]);
      before = vs[i];
    }
  }
  rep(i, n) if(!used[i]) ok = false;
  if(ok) {
    cout << ans1.size() << " " << ans2.size() << endl;
    rep(i, ans1.size()) {
      cout << ans1[i] << endl;
    }
    rep(i, ans2.size()) {
      cout << ans2[i] << endl;
    }
    
  } else {
    cout << "impossible" << endl;
  }
  
  return 0;
}
