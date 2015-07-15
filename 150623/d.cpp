#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 2015;

int n, m, a, b;
double dp[N][N];

void solve()
{
    double t = 1./n/n;
    rep(i, a+1) rep(j, b+1) if (i+j >= 1) {
        double loop = 1.0 - (n-i)*(n-j)*t;
        dp[i][j] = 1.0;
        if (i>=1 and j>=1) dp[i][j] += i*j*t * dp[i-1][j-1];
        if (i>=1) dp[i][j] += i*(n-j)*t * dp[i-1][j];
        if (j>=1) dp[i][j] += (n-i)*j*t * dp[i][j-1];
        dp[i][j] /= loop;
    }
    printf("%.10f\n", dp[a][b]);
}

int main()
{
    scanf("%d%d", &n, &m);
    vector<int> xs, ys;
    rep(_, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        xs.push_back(x);
        ys.push_back(y);
    }
    sort(all(xs));
    sort(all(ys));
    uniq(xs);
    uniq(ys);
    a = n - xs.size();
    b = n - ys.size();
    solve();
    
    return 0;
}
