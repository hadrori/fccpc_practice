#include <bits/stdc++.h>
using namespace std;

#define repi(i,a,b) for(int i = (int)(a); i<(int)(b); ++i)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;
const int L = 4, a[] = {0,4,8,11};
const int inf = 1e9;

inline void chmin(int &x, int y) { x=min(x,y); }
int N, K, E, p[1024], dp[1024][16][64][4];

int solve()
{
    rep(i,N+1) rep(j,K+1) rep(k,E+1) rep(l,L) dp[i][j][k][l] = inf;
    dp[0][0][0][0] = 0;
    rep(i,N) rep(j,K+1) rep(k,E+1) rep(l,L) rep(m,L) {
        int nj = j+(m!=l), nk = k+m;
        if(nj > K) continue;
        if(nk > E) chmin(dp[i+1][nj][E][0], dp[i][j][k][l]+p[i]);
        else chmin(dp[i+1][nj][nk][m], dp[i][j][k][l]+max(0,p[i]-a[m]));
    }
    int ans = inf;
    rep(j,K+1) rep(k,E+1) rep(l,L) chmin(ans, dp[N][j][k][l]);
    return ans;
}

void input()
{
    cin >> N >> K >> E;
    rep(i,N) cin >> p[i];
}

int main()
{
    int t; cin >> t;
    repi(i,1,t+1) {
        input();
        cout << "Case #" << i << ": ";
        cout << solve() << endl;
    }
    return 0;
}
