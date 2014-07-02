#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) repi(i,0,n)
#define mp make_pair
#define pb push_back

int w, h;
struct node {
  int cst, state, x, y;
  bool operator<(const node &o) const {
    return cst > o.cst;
  }
};

const int MAX = 64;
int f[MAX][MAX];
bool inrange(int x, int y) {
  return x >= 0 && y >= 0 && x < w && y < h;
}
int main()
{
  while(cin >> w >> h, w||h) {
    rep(i, h) rep(j, w) {
      char c;
      cin >> c;
      if(c == 'X') f[j][i] = -1;
      else if(c == 'S' || c == 'T') f[j][i] = 0;
      else f[j][i] = c-'0';
    }
    
    priority_queue<node> pq;
    rep(j, w) if(f[j][h-1] == 0) {
      pq.push((node){0, 1, j, h-1});
      pq.push((node){0, -1, j, h-1});
    }
    set<pair<pair<int, int>, int> > done;
    int ans = -1;
    while(pq.size()) {
      int cst = pq.top().cst;
      int state = pq.top().state;
      int x = pq.top().x;
      int y = pq.top().y;
      pq.pop();
      pair<pair<int, int>, int> key = mp(mp(x, y), state);
      if(done.find(key) != done.end()) continue;
      done.insert(key);
      //      cout << x << " " << y << " " << cst << " " << state << endl;
      if(f[x][y] == 0 && y == 0) {
	ans = cst;
	break;
      }
      repi(i, 1, 4) repi(j,-2, 3) {
	int nx = x+state * i, ny = y+j;
	if(inrange(nx, ny) && f[nx][ny] != -1 && abs(x-nx) + abs(y-ny) <= 3) pq.push((node){cst+f[nx][ny], -state, nx, ny});
      }
      
    }
    cout << ans << endl;
  }
  
  return 0;
}
