#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
#define long int64_t

string s, t;

void input() {
  cin >> s >> t;
}

bool solve(const string& orig, const string& a, const string& b) {
  const int L = orig.length();
  const int n = a.length();
  const int m = b.length();
  int t = 0, i = 0, j = 0;
  while (t < L and i < n and j < m) {
    if (t & 1) {
      if (a[i] == orig[t]) ++t;
      ++i;
    } else {
      if (b[j] == orig[t]) ++t;
      ++j;
    }
  }
  return t == L;
}

bool solve() {
  return solve(s,s,t) or solve(s,t,s);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  input();
  cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}
