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
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int n, m, s, g1, g2;
int E[101][101];
int dp[101][101];
int main(){
  while(cin >> n >> m >> s >> g1 >> g2, n){
    s--; g1--; g2--;
    rep(i, n) rep(j, n) E[i][j] = INF;
    rep(i, m){
      int b1, b2, c;
      cin >> b1 >> b2 >> c;
      b1--; b2--;
      E[b1][b2] = c;
    }
    //rep(i, n) rep(j, n) dp[i][j] = INF;
    rep(i, n) rep(j, n) dp[i][j] = E[i][j];
    rep(i, n) dp[i][i] = 0;
    bool changed = true;
    while(changed){
      changed = false;
      rep(k, n){      
	rep(i, n){
	  rep(j, n){
	    if(dp[i][j] > dp[i][k] + dp[k][j]){
	      dp[i][j] = dp[i][k] + dp[k][j];
	      changed = true;
	    }
	  }
	}
      }
    }
    int ans = INF;
    rep(br, n){
      ans = min(ans, dp[s][br] + dp[br][g1] + dp[br][g2]);
    }
    cout << ans << endl;
  }
}


