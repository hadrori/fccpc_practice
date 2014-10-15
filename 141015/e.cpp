#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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

using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i = (int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i = (int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it = (u).begin(); it!=(u).end(); ++it)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;

double win_deuce(double p) { return p * p / (2 * p * p - 2 * p + 1); }

double win(int k, double p, double q)
{
    vector<vector<double> > dp(k + 1, vector<double>(k + 1));
    dp[k - 1][k - 1] = q; // win_deuce(p);
    rep(i, k - 1) dp[k][i] = 1.0;
    for (int i = k - 1; i >= 0; --i) {
        for (int j = k - 1; j >= 0; --j) {
            if (i == k - 1 and j == k - 1) continue;
            dp[i][j] = p * dp[i + 1][j] + (1.0 - p) * dp[i][j + 1];
        }
    }
    return dp[0][0];
}

double win_set(double p, double game)
{
    vector<vector<double> > dp(8, vector<double>(8));
    dp[6][6] = win(7, p, win_deuce(p));
    rep(j, 6) dp[7][j] = 1.0;
    for (int i = 6; i >= 0; --i) {
        for (int j = 6; j >= 0; --j) {
            if (i + j == 12) continue;
            if (i >= 6 and j <= i - 2) {
                dp[i][j] = 1.0;
                continue;
            }
            if (j >= 6 and i <= j - 2) {
                dp[i][j] = 0.0;
                continue;
            }
            dp[i][j] = game * dp[i + 1][j] + (1.0 - game) * dp[i][j + 1];
        }
    }
    return dp[0][0];
}

double p;

void solve()
{
    double deu = win_deuce(p);
    double g = win(4, p, deu);
    double s = win_set(p, g);
    double m = s * s + 2 * (1 - s) * s * s;
    printf("%.11f %.11f %.11f\n", g, s, m);
}

int main()
{
    while (cin >> p and p >= 0.0) {
        solve();
    }

    return 0;
}
