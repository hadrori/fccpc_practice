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

#define repi(i,a,b) for(int i=(a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a); i>=(b); i--)
#define repit(i,a) for(typeof((a).begin()) i=(a).begin(); i != (a).end(); i++)

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

int dp[11][21][21][21][21][8];

const int dxa[] = {0, 0, 1, 0, 0, 0,-1, 0};
const int dxb[] = {0, 1, 0, 1, 0,-1, 0,-1};
const int dya[] = {1, 0, 0, 0,-1, 0, 0, 0};
const int dyb[] = {0, 1, 0,-1, 0,-1, 0, 1};
double r2;

inline bool in(int x) {
    return x >= 0 && x < 21;
}

bool inrange(int xa, int xb, int ya, int yb) {
    return in(xa) && in(xb) && in(ya) && in(yb);
}

inline double f(double a, double b) {
    return 100.0*a + 50*r2*b;
}

int main() {
    r2 = sqrt(2.0);
    int n, m;
    int x1, y1, x2, y2;
    
    rep(i, 11) rep(xa, 21) rep(xb, 21) rep(ya, 21) rep(yb, 21) rep(k, 8) dp[i][xa][xb][ya][yb][k] = INF;
    dp[0][10][10][10][10][0] = 0;
    rep(i, 10) rep(xa, 21) rep(xb, 21) rep(ya, 21) rep(yb, 21) rep(k, 8) {
	int nxa = xa + dxa[k];
	int nxb = xb + dxb[k];
	int nya = ya + dya[k];
	int nyb = yb + dyb[k];
	if(inrange(nxa, nxb, nya, nyb)) 
	    rep(dir, 8)
		dp[i+1][nxa][nxb][nya][nyb][k]
		= min(dp[i+1][nxa][nxb][nya][nyb][k],  dp[i][xa][xb][ya][yb][dir] + min(abs(dir-k), 8-abs(dir-k)));
    }
    cin >> m;
    while(m--) {
	cin >> n;
	cin >> x1 >> y1 >> x2 >> y2;
	int ans = INF;
	rep(xa_, 21) rep(xb_, 21) rep(ya_, 21) rep(yb_, 21) {
	    double xa = xa_ - 10;
	    double ya = ya_ - 10;
	    double xb = xb_ - 10;
	    double yb = yb_ - 10;
	    if(x1+10 < f(xa, xb)+EPS && f(xa, xb) < x2-10+EPS && y1+10 < f(ya, yb)+EPS && f(ya, yb) < y2-10+EPS) {
		rep(k, 8) ans = min(dp[n][xa_][xb_][ya_][yb_][k], ans);
	    }
	}
	if(ans < INF) cout << ans << endl;
	else cout << -1 << endl;
    }
    return 0;
}
