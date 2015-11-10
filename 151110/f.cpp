#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define pb push_back
#define all(u) begin(u),end(u)
#define mp make_pair
#define long int64_t

int n;
const int MAX = 64;
const int MAX_SCORE = 10000;
const double inf = 1e9;
const double eps = 1e-6;

double dp[MAX][MAX_SCORE];
double x[MAX], y[MAX];
int sc[MAX];
double dst[MAX][MAX];

void input() {
    rep(i, n) cin >> x[i+1] >> y[i+1] >> sc[i+1];
    n++;

    x[0] = y[0] = x[n] = y[n] = 0;
    sc[0] = sc[n] = 0;
}

double sq(double x) { return x*x; }

void calcDist() {
    rep(i, n+1) rep(j, n+1)
        dst[i][j] = sqrt(sq(x[i] - x[j]) + sq(y[i] - y[j]));
}

void solve() {
    calcDist();
    string name;
    int d_tmp;
    while (cin >> name >> d_tmp, name != "#" or d_tmp != 0) {
        double d = d_tmp;
        rep(i, n+1) rep(j, MAX_SCORE) dp[i][j] = inf;
        dp[0][0] = 0;
        rep(i, n) rep(j, MAX_SCORE) {
            repi(k, 1, n-i+1) {
                if (j+sc[i+k] < MAX_SCORE)
                    dp[i+k][j+sc[i+k]] = min(dp[i+k][j+sc[i+k]], dp[i][j] + dst[i][i+k]);
            }
        }

        int ans = 0;
        rep(i, MAX_SCORE) if (dp[n][i]-eps < d) ans = i;
        cout << name << ": " << ans << endl;
    }    
}

int main() {
    cin.tie(0);

    int cnt = 1;
    while(cin >> n, n) {
        cout << "Race " << cnt++ << endl;
        input();
        solve();
    }
    return 0;
}
