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
#define INF 1e10
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int H, W;
vector<string> board;


#define dump(x) cerr<<#x<<" = "<<(x)<<endl;
bool solve()
{
  cin >> H >> W;
  board.clear();
  board.resize(H);
  for (int i = 0; i < H; ++i)
    cin >> board[i];

  map<char,int> mx, my, Mx, My;
  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      char c = board[y][x];
      if (c != '.') {
	if (mx.find(c) != mx.end())
	  mx[c] = min(mx[c], x);
	else
	  mx[c] = x;
	if (my.find(c) != my.end())
	  my[c] = min(my[c], y);
	else
	  my[c] = y;
	Mx[c] = max(Mx[c], x);
	My[c] = max(My[c], y);
      }
    }
  }

  while (true) {
    bool exists = false;
    repit(it,mx) {
      char c = it->first;

      //dump(c)dump(mx[c])dump(Mx[c])dump(my[c])dump(My[c])

      for (int y = my[c]; y <= My[c]; ++y)
	for (int x = mx[c]; x <= Mx[c]; ++x)
	  if (board[y][x] != c && board[y][x] != '?')
	    goto fail;
      for (int y = my[c]; y <= My[c]; ++y)
	for (int x = mx[c]; x <= Mx[c]; ++x)
	  board[y][x] = '?';
      mx.erase(mx.find(c));
      my.erase(my.find(c));
      Mx.erase(Mx.find(c));
      My.erase(My.find(c));
      exists = true;
      goto outer;
    fail:;
    }

    //    rep(y,H)cerr<<board[y]<<endl;
    //    cerr<<endl;

  outer:;
    if (!exists) break;
  }

  for (int y = 0; y < H; ++y)
    for (int x = 0; x < W; ++x)
      if (board[y][x] != '.' && board[y][x] != '?')
	return false;

  return true;
}

int main() {
  int T; cin >> T;
  while (T --> 0)
    cout << (solve() ? "SAFE" : "SUSPICIOUS") << endl;

  return 0;
}


