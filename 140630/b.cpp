#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>


using namespace std;

#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) repi(i,0,n)
#define mp make_pair
#define pb push_back

struct term {
  int ts, te, n, m;
};
int main()
{
  int N, M;
  while(cin >> N >> M, N||M) {
    int r;
    cin >> r;
    map<pair<int, int>, int> table;
    vector<term> v;
    rep(i, r) {
      int t, n, m, s;
      cin >> t >> n >> m >> s;
      m--; n--;
      if(s == 1) table[mp(n, m)] = t;
      else {
	v.pb((term){table[mp(n, m)], t, n, m});
      }
    }
    //    cout << "term" << endl;
    rep(i, v.size()) {
      //      cout << v[i].ts << " " << v[i].te << " " << v[i].n << " " << v[i].m << endl;
    }
    int q;
    cin >> q;
    //    cout << endl;
    rep(i, q) {
      int l, r, m;
      cin >> l >> r >> m;
      m--;
      int ans = 0;
      vector<int> s(1261);
      rep(j, v.size()) if(v[j].m == m){
	s[v[j].ts] += 1;
	s[v[j].te] -= 1;
      }
      rep(j, 1260) s[j+1] += s[j];
      repi(j, l, r) if(s[j]) ans++;
      cout << ans << endl;
    }

  }
  return 0;
}
