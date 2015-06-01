#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(u) begin(u),end(u)

string s, t;

void input()
{
  cin >> s >> t;
}
typedef long long i64;
const i64 mod = 21092013;
inline void add(i64 &x, i64 y) { x=(x+y)%mod; }

// l = 0, r = 1
i64 lr[100010], l, r, d;

i64 solve()
{
  memset(lr,-1,sizeof(lr));
  d = 0;
  for(char &c: s) {
    if (c == 'U' and d) d--;
    else if(c == 'L') lr[++d] = 0;
    else if(c == 'R') lr[++d] = 1;
  }
  l = r = 1;
  i64 ans = 1;
  for(char &c: t) {
    if(c == 'U' and d) {
      add(ans, 1);
      if(lr[d--]) add(l,1);
      else add(r,1);
    }
    else if(c == 'L') {
      add(ans,l);
      add(r,l);
    }
    else if(c == 'R') {
      add(ans,r);
      add(l,r);
    }
  }
  return ans;
}

int main()
{
  int t; cin >> t;
  rep(i,t) {
    input();
    cout << "Case " << i+1 << ": ";
    cout << solve() << endl;
  }
}
