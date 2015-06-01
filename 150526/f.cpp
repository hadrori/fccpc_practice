#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
#define mp make_pair
#define all(u) (u).begin(),(u).end()

const int MAX = 64;

int r, c;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
string s;

int toi[MAX][MAX][4];
int toj[MAX][MAX][4];
char f[MAX][MAX];
bool inrange(int i, int j) {
  return i >= 0 and j >= 0 and i < r and j < c;
}

struct node {
  int i, j, pos, cst;
  node(int i, int j, int pos, int cst) : i(i), j(j), pos(pos), cst(cst) {}
};
vector<bool> done[MAX][MAX];
int main() {
  cin >> r >> c;
  rep(i, r) rep(j, c) cin >> f[i][j];
  string s;
  cin >> s;
  s += '*';
  int n = s.size();
  
  rep(i, r) rep(j, c) {
    char ch = f[i][j];
    rep(k ,4) {
      int ti = i, tj = j;      
      while(inrange(ti, tj) and f[ti][tj] == ch) {
        ti += di[k];
        tj += dj[k];
      }
      toi[i][j][k] = ti;
      toj[i][j][k] = tj;
    }
  }
  
  rep(i, r) rep(j, c) done[i][j].assign(n, false);
  queue<node> q;
  q.push(node(0, 0, 0, 0));
  while(q.size()) {
    int ni = q.front().i;
    int nj = q.front().j;
    int pos = q.front().pos;
    int cst = q.front().cst;
    q.pop();
    if(done[ni][nj][pos]) continue;
    done[ni][nj][pos] = true;
    //cout << ni << " " << nj << " " << pos << " " << cst << endl;
    if(pos == n) {
      cout << cst << endl;
      break;
    }
    
    if(f[ni][nj] == s[pos])
      q.push(node(ni, nj, pos+1, cst+1));
    rep(k, 4) {
      int ti = toi[ni][nj][k];
      int tj = toj[ni][nj][k];
      if(inrange(ti, tj))
        q.push(node(ti, tj, pos, cst+1));
    }
  }
  
  return 0;
}
