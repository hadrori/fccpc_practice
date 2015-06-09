#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(int)(b);++i)
#define all(u) begin(u),end(u)

const string name = "";
ifstream in(name + "filter.in");
ofstream out(name + "filter.out");
#define cin in
#define cout out

const string num = "0123456789abcdef";
int m, f, n, q, a[128], u[1024], v[1024][128];
bool x[1024][1024];
string s;

void convert(int i)
{
  rep(j,s.size()) {
    int y = num.find(s[j]);
    rep(k,4) {
      x[i][j*4+k] = y&1;
      y >>= 1;
    }
  }
}

void input()
{
  cin >> m >> f;
  rep(i,f) cin >> a[i];
  cin >> n;
  rep(i,n) {
    cin >> s;
    convert(i);
  }
  cin >> q;
  rep(i,q) cin >> u[i];
}

void solve()
{
  vector<int> ans;
  rep(i,n) rep(j,f) v[i][j] = 1LL*a[j]*u[i]%m;
  rep(i,n) {
    rep(j,q) {
      bool ok = 1;
      rep(k,f) {
        if(!x[i][v[j][k]]) {
          ok = 0;
          break;
        }
      }
      if(ok) {
        ans.push_back(i);
        break;
      }
    }
  }
  cout << ans.size();
  for(int &e: ans) cout << ' ' << e;
  cout << endl;
}

int main()
{
  input();
  solve();
}
