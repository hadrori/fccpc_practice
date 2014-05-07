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

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

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

const int N = 100;

int n, t, m, d[N];

void input()
{
    cin >> n >> t >> m;
    rep(i, n) cin >> d[i];
}

const int mod = 1000000009;

int dp[N + 1][10001] = {1};

void solve()
{
    rep(i, n) {
        for (int j = i + 1; j > 0; --j) {
            repi(k, d[i], t + 1) {
                dp[j][k] += dp[j - 1][k - d[i]];
                if (dp[j][k] >= mod) dp[j][k] -= mod;
            }
        }
    }

    int ans = 0;
    repi(i, m, n + 1) rep(j, t + 1) {
        ans += dp[i][j];
        if (ans >= mod) ans -= mod;
    }

    cout << ans << endl;
}

int main()
{
    input();
    solve();

    return 0;
}
