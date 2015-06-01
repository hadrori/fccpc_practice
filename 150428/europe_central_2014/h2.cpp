#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<int(b);++i)

int a[8][8];
set<int> cand;

void dfs(int i, int j, int now) {
  if(now > 999) return;
  if(i > 3 or j > 2) return;
  if(a[i][j] == -1) return;
  cand.insert(now);
  if(now != 0 or a[i][j] != 0) 
    dfs(i, j, now*10 + a[i][j]);
  dfs(i+1, j, now);
  dfs(i, j+1, now);
}

void gen() {
  rep(i, 9) a[i/3][i%3] = i+1;
  a[3][1] = 0;
  a[3][2] = a[3][0] = -1;
  dfs(0, 0, 0);
}
int main()
{
  gen();
  //for(int v : cand) cout << v << endl;
  
  int n;
  cin >> n;
  rep(i, n) {
    int k;
    cin >> k;
    int ans = 0;
    for(int v : cand) {
      if(abs(v-k) <= abs(ans-k)) ans = v;
    }
    cout << ans << endl;
  }

}
