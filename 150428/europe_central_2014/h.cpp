#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<int(b);++i)

vector<int> cand;

int solve(int n)
{
  int ans = 1e9;
  for(int v: cand) {
    if(abs(n-v) < abs(n-ans)) {
      ans = v;
    }
  }
  return ans;
}

bool ok(int v)
{
  string s = to_string(v);
  int pv = -2;
  for(char &c: s) {
    int k = c-'0'-1;
    if((k == -1 and pv%3 < 2) or pv == -2 or (k/3 >= pv/3 and k%3 >= pv%3)) {
      pv = k;
      continue;
    }
    return 0;
  }
  return 1;
}

void generate()
{
  cand.clear();
  for(int i = 1; i < 201; i++) if(ok(i)) cand.push_back(i);
}

int main()
{
  int t, n; scanf("%d", &t);
  generate();
  while(t--) {
    scanf("%d", &n);
    printf("%d\n", solve(n));
  }
}
