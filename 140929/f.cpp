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
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;

const int mod = 10007;

int n, w, a[101];

void input()
{
    cin >> n >> w;
    rep(i, n) cin >> a[i];
    sort(a, a + n, greater<int>());
}

int fact[101] = {1};

void prepare()
{
    repi(i, 1, 101) {
        fact[i] = fact[i - 1] * i % mod;
    }
}

int dp[2][101][1001][102];

void solve()
{
    
    cout << ans << endl;
}

int main()
{
    prepare();

    int t;
    cin >> t;
    rep(i, t) {
        input();
        cout << "Case " << i + 1 << ": ";
        solve();
    }

    return 0;
}
