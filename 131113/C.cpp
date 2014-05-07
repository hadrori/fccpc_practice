#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>

#define repi(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a); i >= (b); i--)
#define repit(i,a) for(__typedef((a).begin()) i = (a).begin(); i = (a).end(); i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)), (u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int dp[1005][10][10];

int dst(int x, int y) { return min(abs(x - y), 10 - abs(x - y)); }
int cst(int x) { return min(x, 10 - x); }

int rotate(int k, int x, int y) {
  return (k + y - x + 10)%10;
}

int main(){
  string sa, sb;
  while(cin >> sa >> sb) {
    vector<int> a, b;
    rep(i, sa.size()) a.pb(sa[i] - '0');
    rep(i, sb.size()) b.pb(sb[i] - '0');
    a.pb(0); a.pb(0);

    // init
    int n = sb.size();
    rep(i, n+1) rep(j, 10) rep(k, 10) dp[i][j][k] = INF;
    dp[0][a[0]][a[1]] = 0;

    // renew
    rep(i, n) rep(j, 10) rep(k, 10) if(dp[i][j][k] < INF){
      rep(p, 10) rep(q, 10) {
	int r = (b[i] - (j + p + q)%10 + 10) % 10;
	dp[i+1][(k+q+r)%10][(a[i+2]+r)%10] 
	  = min(dp[i+1][(k+q+r)%10][(a[i+2]+r)%10], dp[i][j][k] + cst(p) + cst(q) + cst(r));
	//if(i == 0) cout << p << " " << q << " " << r << " " << cst(p) << " " << cst(q) << " " << cst(r)<< endl;
      }
    }

    // goal
    int ans = INF;
    rep(j, 10) rep(k, 10) ans = min(ans, dp[n][j][k]);
    cout << ans << endl;
  }
  return 0;
}
