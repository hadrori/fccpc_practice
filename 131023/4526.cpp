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


#define repi(i,a,b) for(int i = (a); i < (b); i++)
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

const int M = 1024;

int N, p[M], n[M], d[M];

void input()
{
    cin >> N;
    rep(i, N)
	cin >> p[i] >> n[i] >> d[i];
    p[N] = n[N] = d[N] = 0;
}

int dp[M][128];

int solve()
{
    rep(i, M) rep(j, 128)
	dp[i][j] = (int) INF;
    dp[0][0] = 0;

    rep(i, N) rep(j, d[i] + 1) rep(nj, d[i + 1] + 1)
	if (d[i] - j + nj <= n[i])
	    dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + p[i] * (nj + d[i] - j));
    return dp[N][0];
}

int main()
{
    int T; cin >> T;
    while (T--) {
	input();
	cout << solve() << endl;
    }

    return 0;
}
