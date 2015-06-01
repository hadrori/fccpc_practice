#include <bits/stdc++.h>
#define repi(i, a, b) for(int i = (a); (i) < (int)(b); i++)
#define rep(i, n) for(int i = 0; (i) < (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;

vector<int> ans;

void rotate(vector<int>& a, int k, int x) {
  vector<int> b(a.size());
  rep(i, a.size()) 
    if(a[i] == x) {
      rep(j, a.size()) 
        b[(j+k)%a.size()] = a[(j+i)%a.size()];
      break;
    }
  a = b;
}

vector<int> ord;
vector<vector<int> > v;
vector<vector<int> > tv;
void dfs(int d, int S) {
  if(d == 7) {
    if(tv[1][4] == tv[6][1]) {
      ans = ord;
    }
    return;
  }

  /*
  if(ord.size() and ord[0] == 3) {
    rep(i, tv.size()) {
      rep(j, 6) cout << tv[i][j] << " ";
      cout << endl;
    }
    cout << endl;
    }*/
  rep(i, 7)
    if(((S>>i)&1) == 0) {
      vector<int> now = v[i];
      if(d == 0)
        rotate(now, 0, 1);
      else 
        rotate(now, (d+2)%6, tv[0][d-1]);
      if(d > 1 and tv[d-1][d%6] != now[(d+3)%6])
        continue;

      tv.push_back(now);
      ord.push_back(i);      
      dfs(d+1, S|(1<<i));
      tv.pop_back();
      ord.pop_back();
    }
    
}

void solve() {
  v.assign(7, vector<int>(6));
  rep(i, 7) rep(j, 6) cin >> v[i][j];
  tv.clear();
  dfs(0, 0);
}

int main() {
  int T;
  cin >> T;
  rep(t, T) {
    ans.clear();
    cout << "Case " << t+1 << ": ";
    solve();
    if(ans.size()) {
      rep(i, ans.size()) {
        cout << ans[i];
        if(i+1 == (int)ans.size()) cout << endl;
        else cout << " ";
      }
    } else {
      cout << "No solution" << endl;
    }
  }
    
  
  return 0;
}
