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

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
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

int N;
vector<pair<int,int> > V;

int dp[1024][1024];

int solve()
{
    rep(i,1024) rep(j,1024) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,N) {
	int A = V[i].second;
	int B = V[i].first;
	rep(j,i+1) {
	    dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
	    if (dp[i][j] + A <= B)
		dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + A);
	}
    }
    for (int i = N; i >= 0; --i)
	if (dp[N][i] < INF)
	    return i;
    return 0;
}

int main() {
    cin >> N;
    rep(i,N) {
	int A, B;
	cin >> A >> B;
	V.pb(mp(B, A));
    }
    sort(all(V));

    cout << solve() << endl;
    
    return 0;
}
