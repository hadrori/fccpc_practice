#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define rep(i,a) for(int i = 0;i < a; i++)
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0,-1, 0, 1};
int field[30][30];
int h, w;
int ans;
int sx, sy, gx, gy;
bool inrange(int x, int y){
  return x >= 0 && y >= 0 && x < w && y < h;
}

void rec(int x, int y, int cnt){
  if(cnt > 10) return;
  /*  cout << x << " " << y << endl;
  rep(i, h){
    rep(j, w){
      cout << field[j][i] << " ";
    }
    cout << endl;
    }*/
  rep(i, 4){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(inrange(nx, ny) && field[nx][ny] != 1){
      int tx = nx, ty = ny;
      while(inrange(tx, ty) && field[tx][ty] != 1){
	if(tx == gx && ty == gy){
	  ans = min(ans, cnt);
	  return;
	}
	tx += dx[i]; ty += dy[i];
      }
      if(!inrange(tx, ty)) continue;
      field[tx][ty] = 0;
      tx -= dx[i]; ty -= dy[i];
      rec(tx, ty, cnt+1);
      field[tx+dx[i]][ty+dy[i]] = 1;
    }
  }
}
int main(){
  while(cin >> w >> h, w||h){
    rep(i, h){
      rep(j, w){
	cin >> field[j][i];
	if(field[j][i] == 2){
	  sx = j; sy = i;
	  field[j][i] = 0;
	}else if(field[j][i] == 3){
	  gx = j; gy = i;
	  field[j][i] = 0;
	}
      }
    }
    ans = 12;
    rec(sx, sy, 1);
    cout << (ans==12?-1:ans) << endl;
  }
  return 0;
}
