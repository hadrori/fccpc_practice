#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 100000000
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
int w, h;
const int dx[] = { 0, 1, 0,-1};
const int dy[] = {-1, 0, 1, 0};
int wall[31][31][4];
struct node{
  int x, y, step;
  bool operator<(const node &o) const{
    return step > o.step;
  }
};
int main(){
  while(cin >> w >> h, w||h){
    int a;
    memset(wall, 0, sizeof(wall));
    rep(x, w-1){
      cin >> a;
      if(a) wall[x][0][1] = wall[x][0][3] = true;
    }
    rep(y, h-1){
      rep(x, w){
	cin >> a;
	if(a) wall[x][y][2] = wall[x][y+1][0] = true;
      }
      rep(x, w-1){
	cin >> a;
	if(a) wall[x][y+1][1] = wall[x+1][y+1][3] = true;
      }
    }
    int ans = -1;
    priority_queue<node> pq;
    pq.push((node){0, 0, 0});
    bool done[31][31] = {0};
    while(!pq.empty()){
      int x = pq.top().x;
      int y = pq.top().y;
      int step = pq.top().step;
      pq.pop();
      if(done[x][y]) continue;
      done[x][y] = true;
      //cout << x << " " << y << " " << step << endl;
      if(x == w-1 && y == h-1){
	ans = step;
	break;
      }
      rep(d, 4){
	int nx = x + dx[d];
	int ny = y + dy[d];
	if(!wall[x][y][d] && nx >= 0 && ny >= 0 && nx < w && ny < h){
	  pq.push((node){nx, ny, step+1});
	}
      }
    }
    cout << ans + 1 << endl;
  }
}


