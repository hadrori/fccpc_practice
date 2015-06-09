#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<int(b);++i)

const int N = 1024;

int n, a[N];

void input()
{
  cin >> n;
  rep(i, n) cin >> a[i];
}

struct tpl {
  int l, r;
  tpl(int l, int r) : l(l), r(r) {}
  bool operator<(const tpl &o) const {
    if(l != o.l) return l < o.l;
    return r < o.r;
  }
};

string ans;
set<tpl> done;
bool dfs(int l, int r, int d) {
  for(int i = 1<<13; i > 0; i >>= 1) {
    if((r&i) or (l&i)) {
      if(r&i and l&i) {
        l ^= i; r ^= i;
        l ^= (i<<1);
      }
      break;
    }
  }
  if(l == 0 and __builtin_popcount(r) == 1) swap(l, r);
  if(d == n) return __builtin_popcount(l) + __builtin_popcount(r) == 1;
  if(done.find(tpl(l, r)) != done.end())
    return false;
  done.insert(tpl(l, r));
  
  if(r == 0 or (r&-r) >= a[d]) {
    ans += 'r';
    if(dfs(l, r+a[d], d+1)) {
      return true;
    } else {
      ans.pop_back();
    }
  }
  if(l == 0 or (l&-l) >= a[d]) {
    ans += 'l';
    if(dfs(l+a[d], r, d+1)) {
      return true;
    } else {
      ans.pop_back();
    }
  }
  
  return false;
}

void solve()
{
  ans = "";
  dfs(0, 0, 0);
  //  reverse(begin(ans), end(ans));
  if(ans != "") cout << ans << endl;
  else cout << "no" << endl;
}

int main()
{
  int t;
  for (cin >> t; t--; ) {
    input();
    solve();
  }
}
