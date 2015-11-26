#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
#define long int64_t

struct BIT {
  int n;
  vector<int> dat;
  BIT(){}
  BIT(int n) :n(n) { dat.assign(n,0); }
  int sum(int i) {
    int ret = 0;
    for(--i; i>=0; i=(i&(i+1))-1) ret += dat[i];
    return ret;
  }
  int sum(int i, int j){ return sum(j) - sum(i);}
  void add(int i, int x) { for(;i<n;i|=i+1) dat[i] += x;}
  
};

int n;
string s;
BIT ls, rs;

int search1(int i, int x) {
  int l = i+1, m;
  int lb = l, ub = n;
  while(ub-lb > 1) {
    m = (lb+ub)/2;
    if(rs.sum(l,m) >= x) ub = m;
    else lb = m;
  }
  return ub;
}

int search2(int i, int x) {
  int r = i, m;
  int lb = 0, ub = r;
  while(ub-lb > 1) {
    m = (lb+ub)/2;
    if(ls.sum(m,r) >= x) lb = m;
    else ub = m;
  }
  return lb;
}

int solve() {
  ls = BIT(n);
  rs = BIT(n);
  rep(i,n) {
    if(s[i] == '<') rs.add(i,1);
    else ls.add(i,1);
  }
  
  int ans = 0;
  rep(i,n) {
    int ln = ls.sum(0,i+1), rn = rs.sum(i,n);
    if(ln < rn) ans = max(ans, search1(i,ln));
    else if(ln > rn) ans = max(ans, n-search2(i,rn));
    else if(s[i] == '>') ans = max(ans, search1(i,ln));
    else ans = max(ans, n-search2(i,rn));
  }
  return ans;
}

void input() {
  cin >> n;
  cin >> s;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  input();
  cout << solve() << endl;
  return 0;
}
