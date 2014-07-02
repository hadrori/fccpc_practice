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

const int N = 1000;
const int M = 1000010;

int a[N], dp[M] = {}, dp1[M] = {};

void prepare()
{
    rep(i, N) a[i] = 1;
    rep(i, N - 1) a[i + 1] += a[i];
    rep(i, N - 1) a[i + 1] += a[i];
    rep(i, N - 1) a[i + 1] += a[i];

    repi(i, 1, M) dp[i] = dp1[i] = M;

    rep(i, N) {
        if (a[i] >= M) break;
        for (int j = a[i]; j < M; ++j) {
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
            if (a[i] & 1) dp1[j] = min(dp1[j], dp1[j - a[i]] + 1);
        }
    }
}

int main()
{
    prepare();

    int n;
    while (cin >> n and n) {
        cout << dp[n] << ' ' << dp1[n] << endl;
    }

    return 0;
}
