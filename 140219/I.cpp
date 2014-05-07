#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>ago
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

int n, m;
int T[105][5005], F[105][5005];
int dp[105][5005], sqdp[105][100];
int main()
{
    while(cin >> n >> m, n || m) {
        rep(i, n) rep(j, m) cin >> T[i][j];
        rep(i, n) rep(j, m) cin >> F[i][j];
        int sqm = sqrt(m);

        rep(j, m) dp[0][i] = T[i][j];
        rep(i, n) {
            rep(j, m) {
                
            }
        }

        int ans = s1.query(0, m);
        cout << ans << endl;
    }

    
    return 0;
}
