#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(u) begin(u),end(u)

const int L = 9;

string dr[L], rdr[L];

string rev(string s)
{
  reverse(all(s));
  for (char& c : s) {
    c = (c == 'L' ? 'R' : 'L');
  }
  return s;
}

void prepare()
{
  repi(i, 1, L) dr[i] = dr[i-1] + 'L' + rev(dr[i-1]);
  rep(i, L) rdr[i] = rev(dr[i]);
}

int n, len; string s;

void input()
{
  cin >> n >> s;
  len = s.length();
}

void solve()
{
  for (int lv = min(n, L) - 1; lv >= 0; --lv) {
    const int r = (1 << lv) - 1;
    for (int i = max(len - r - 1, 0); i <= min(r, len - 1); ++i) {
      if (s[i] == 'L') {
        if (dr[lv].substr(dr[lv].length() - i, i) == s.substr(0, i) and
            rdr[lv].substr(0, len - i - 1) == s.substr(i + 1, len - i - 1)) {
          cout << "Yes" << endl;
          return;
        }
      }
      if (s[i] == 'R' and lv != n - 1) {
        if (dr[lv].substr(dr[lv].length() - i, i) == s.substr(0, i) and
            rdr[lv].substr(0, len - i - 1) == s.substr(i + 1, len - i - 1)) {
          cout << "Yes" << endl;
          return;
        }
      }
    }
  }
  cout << "No" << endl;
}

int main()
{
  prepare();
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case " << i << ": ";
    input();
    solve();
  }
}
