#include <bits/stdc++.h>
#define repi(i, a, b) for(int i = (a); (i) < (b); i++)
#define rep(i, n) for(int i = 0; (i) < (n); i++)
using namespace std;

void solve() {
  int n = 4;
  vector<long> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  long maxx = x[0], maxy = y[0];
  long minx = x[0], miny = y[0];

  vector<long> pos(n);
  rep(i, n) {
    if(x[i] > maxx) {
      maxx = x[i];
      pos[0] = i;
    }
    if(x[i] < minx) {
      minx = x[i];
      pos[1] = i;
    }
    if(y[i] > maxy) {
      maxy = y[i];
      pos[2] = i;      
    }
    if(y[i] < miny) {
      miny = y[i];
      pos[3] = i;
    }
  }
  //  cout << maxx << " " << minx << " " << maxy << " " << miny << endl;
  bool ok = true;
  rep(i, n) {
    if(x[i] == maxx and pos[0] != i) ok =false;
    if(x[i] == minx and pos[1] != i) ok =false;
    if(y[i] == maxy and pos[2] != i) ok =false;
    if(y[i] == miny and pos[3] != i) ok =false;
  }

  if(maxx - minx != maxy - miny) ok = false;

  if(ok) {
    cout << 10 + maxy - miny << ".00" << endl;
  } else {
    cout << "no solution" << endl;
  }
}

int main() {
  int T;
  cin >> T;
  rep(t, T) {
    cout << "Case " << t+1 << ": ";
    solve();
  }
  
  return 0;
}
