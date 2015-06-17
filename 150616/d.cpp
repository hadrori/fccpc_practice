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

char s[10][10];

bool solve()
{
  rep(i, 9) repi(j, i+1, 9) rep(k, 9) {
    if (s[k][i] == s[k][j]) return false;
    if (s[i][k] == s[j][k]) return false;
    int ii = k / 3 * 3;
    int jj = k % 3 * 3;
    if (s[ii + i/3][jj + i%3] == s[ii + j/3][jj + j%3]) return false;
  }
  return true;
}

int main()
{
  int t;
  for (cin >> t; t--; ) {
    rep(i, 9) cin >> s[i];
    cout << (solve() ? "Valid" : "Invalid") << endl;
  }
    return 0;
}
