#include <bits/stdc++.h>
#define repi(i, a, b) for(int i = (a); (i) < (int)(b); i++)
#define rep(i, n) for(int i = 0; (i) < (int)(n); i++)
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;

const int pow10[] = {1,
                     10,
                     100,
                     1000,
                     10000,
                     100000,
                     1000000,
                     10000000,
                     100000000,
};
vector<int> gen_string(const string &s) {
  vector<int> ret;
  int tmp = 0;
  repi(l, 1, min(9, (int)s.size()+1)) {
    tmp = 0;
    rep(i, l) {
      tmp *= 10;
      tmp += s[i] - '0';
    }
    ret.pb(tmp);
    repi(i, l, s.size()) {
      tmp *= 10;
      tmp -= pow10[l] * (s[i-l] - '0');
      tmp += s[i] - '0';
      ret.pb(tmp);
    }
  }

  return ret;
}

void solve() {
  int n, w;
  cin >> n >> w;
  string s;
  cin.ignore();
  set<int> st;
  int cur = 0;
  rep(_, n) {
    getline(cin, s);
    vector<string> v;
    int bf = -1;
    rep(i, s.size()) {
      if(s[i] >= '0' and s[i] <= '9') {
        if(bf == -1)
          bf = i;
      } else if(bf >= 0) {
        v.pb(s.substr(bf, i-bf));
        bf = -1;
      }
    }
    if(bf >= 0)
      v.pb(s.substr(bf, (int)s.size()-bf));

    vector<int> tv;
    for(const string &a : v) {
      vector<int> tt = gen_string(a);
      for(int val : tt)
        tv.pb(val);
    }
    sort(all(tv));
    while(st.find(cur+1) != st.end() or
          (lower_bound(all(tv), cur+1) != tv.end() and
           *lower_bound(all(tv), cur+1) == cur+1))
      cur++;
    
    rep(i, tv.size()) {
      if(tv[i] <= cur + w)
        st.insert(tv[i]);
    }

  }

  int ans = 0;
  if(st.size()) {
    auto itr = st.end();
    itr--;
    ans = *itr;
  }
  cout << cur << " " << ans << endl;
}

int main() {
  int T;
  cin >> T;
  rep(t, T) {
    cout << "Case " << t+1 << ": ";
    solve();
  }
  
  return 0;
}
