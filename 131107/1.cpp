#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i,a,b) for(int i = (a);i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

char trump;
char lead;
struct card {
  int id;
  int num;
  char mark;
  bool operator<(const card &o) const {
    if(mark == trump) {
      if(o.mark == trump) return num < o.num;
      return false;
    } 
    if(o.mark == trump) return true;
    if(mark != lead && o.mark == lead) return true;
    if(mark == lead && o.mark != lead) return false;
    return num < o.num;
  }
};

int main(){
  map<char, int> tbl;
  tbl['A'] = 14;
  tbl['2'] = 2;
  tbl['3'] = 3;
  tbl['4'] = 4;
  tbl['5'] = 5;
  tbl['6'] = 6;
  tbl['7'] = 7;
  tbl['8'] = 8;
  tbl['9'] = 9;
  tbl['T'] = 10;
  tbl['J'] = 11;
  tbl['Q'] = 12;
  tbl['K'] = 13;

  while(cin >> trump, trump != '#') {
    vector<vector<card> > cards(13);
    rep(i, 13) cards[i].resize(4);
    rep(j, 4) rep(i, 13) {
      string ts;
      cin >> ts;
      cards[i][j] = (card){j, tbl[ts[0]], ts[1]};
    }
    
    int leader = 0;
    int ew = 0;
    int ns = 0;
    rep(i, 13) {
      vector<card> v;
      lead = cards[i][leader].mark;
      rep(j, 4) v.pb(cards[i][j]);
      sort(all(v));
      if(v[3].id == 0 || v[3].id == 2) {
	ns++;
      } else {
	ew++;
      }
      //      cout << v[3].id<< " ";
      leader = v[3].id;
    }
    if(ns > ew) cout << "NS ";
    else {
      swap(ns, ew);
      cout << "EW ";
    }

    cout << ns - 6 << endl;
  }
  
  return 0;
}
