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

const int mod = 100000007;
const int N = 200000;

ll dp[N] = {1, 1}, dp1[N] = {1, 1};

void gen()
{
    repi(i,2,N) {
        dp[i] = dp[i - 1] * 2;
        if (i > 5)
            dp[i] -= dp[i - 6];
        dp[i] = (dp[i] % mod + mod) % mod;

        dp1[i] = dp1[i - 1] * 2;
        if (i > 3)
            dp1[i] -= dp1[i - 4];
        dp1[i] = (dp1[i] % mod + mod) % mod;
    }

    repi(i,6,N)
        dp[i] = (dp[i] + dp[i - 5]) % mod;
    repi(i,4,N)
        dp1[i] = (dp1[i] + dp1[i - 3]) % mod;
}

char line[N];

#define dump(x) cerr<<#x<<" = "<<(x)<<endl;

int solve()
{
    int len = strlen(line);
    line[--len] = '\0';

    ll ans = 1;
    for (int i = 0; i < len; ) {
        int next_i = i;
        while (next_i < len && line[next_i] == line[i])
            ++next_i;

        if (line[i] == '8' || line[i] == '0')
            ans = ans * dp1[next_i - i] % mod;
        else
            ans = ans * dp[next_i - i] % mod;
        i = next_i;
    }
    return (int) ans;
}

int main()
{
    gen();

    while (fgets(line, N, stdin), line[0] != '#')
        printf("%d\n", solve());

    return 0;
}
