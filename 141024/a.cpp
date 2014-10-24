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

const int N = 314;

int n, s[N], t[N];

void input()
{
    cin >> n;
    rep(i, n) cin >> s[i] >> t[i];
}

int dp[610][610];

void solve()
{
    int m = -1;
    {
        vector<int> unzip;
        rep(i, n) {
            unzip.pb(s[i]);
            unzip.pb(t[i]);
            sort(all(unzip));
            uniq(unzip);
        }
        m = unzip.size();
        map<int, int> zip;
        rep(i, unzip.size()) zip[unzip[i]] = i;
        rep(i, n) {
            s[i] = zip[s[i]];
            t[i] = zip[t[i]];
        }
    }
    memset(dp, 0, sizeof(dp));
    repi(gap, 1, m + 1) {
        rep(i, m - gap) {
            repi(j, i + 1, i + gap) {
                dp[i][i + gap] = max(dp[i][i + gap], dp[i][j] + dp[j][i + gap]);
            }
            rep(j, n) {
                if (s[j] == i and t[j] == i + gap) {
                    ++dp[i][i + gap];
                }
            }
        }
    }
    int ans = 0;
    rep(i, m + 1) repi(j, i + 1, m + 1) {
        ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }

    return 0;
}
