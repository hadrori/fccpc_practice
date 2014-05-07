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
int n, m, a;
struct node{
  int h;
  int p;
  int q;
  bool operator<(const node &o) const{
    return h < o.h;
  }
};
int main(){
  while(cin >> n >> m >> a, n||m||a){
    int h, p, q;
    priority_queue<node> pq;
    rep(i, m){
      cin >> h >> p >> q;
      pq.push((node){h, p, q});
    }
    while(!pq.empty()){
      int p = pq.top().p;
      int q = pq.top().q;
      pq.pop();
      if(p == a){
	a = q;
      }else if(q == a){
	a = p;
      }
    }
    cout << a << endl;
  }
}


