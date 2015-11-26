#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
#define long int64_t

string s;

void input() {
  cin >> s;
}

string ans;

long cost(string t) {
  long a = 0, b = 0;
  long c = 1;
  rep(i, s.size()) {
    c *= 10;
    a *= 10;
    a += s[i] - '0';
  }
  rep(i, t.size()) {
    b *= 10;
    b += t[i] - '0';
  }
  
  return min(abs(a-b), c - abs(a-b));
}

void dfs(int pos, int type, int used, string route) {
  //
  if (pos == (int)s.size()) {
    if (ans == "") ans = route;
    //cout << route << " " << cost(route) << endl;
    if (cost(ans) < cost(route)) ans = route;
    else if (cost(ans) == cost(route) and ans > route) ans = route;
  } else if (type == 0) {    
    int use = (s[pos]-'0') % 10;
    if (pos == 0) use = (use + 5) % 10;
    if (((used>>use)&1) == 0) {
      dfs(pos+1, 0, used | (1<<use), route + (char)(use + '0'));
    } else {
      int tuse = use;
      while (true) {
	use = (use+1)%10;
	if (((used>>use)&1) == 0) {
	  dfs(pos+1, 1, used | (1<<use), route + (char)(use + '0'));
	  break;
	}	
      }
      
      use = tuse;
      while (true) {
	use = (use+9)%10;
	if (((used>>use)&1) == 0) {
	  dfs(pos+1, 2, used | (1<<use), route + (char)(use + '0'));
	  break;
	}	
      }      
    }    
  } else if (type == 2) {
    for (int i = 9; i >= 0; i--)
      if (((used>>i)&1) == 0) {
	dfs(pos+1, type, used | (1<<i), route + (char)(i + '0'));
      }        
  } else if (type == 1) {
    for (int i = 0; i <= 9; i++)
      if (((used>>i)&1) == 0) {
	dfs(pos+1, type, used | (1<<i), route + (char)(i + '0'));
      }
  }
  
}

void solve() {
  ans = "";
  //dfs(0, 0, 0, "");

  vector<int> v;
  rep(i, s.size()) v.pb(1);
  rep(i, 10-(int)s.size()) v.pb(0);
  sort(all(v));
  do {
    string tmp;  
    rep(i, v.size())
      if (v[i])
	tmp += (char) ('0' + i);
    do {
      if (ans == "") ans = tmp;    
      if (cost(tmp) > cost(ans)) ans = tmp;
      else if (cost(tmp) == cost(ans) and tmp < ans) ans = tmp;
    } while (next_permutation(all(tmp)));    
  } while (next_permutation(all(v)));
	   
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  input();
  solve();
  return 0;
}
