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

const int N = 32;

vector<pair<int, int> > v;

int dp[11];

void solve()
{
    memset(dp, 0, sizeof(dp));

    sort(all(v));
    rep(i, v.size()) {
        const int a = v[i].first;
        const int b = v[i].second;

        int mx = 0;
        rep(j, a + 1) mx = max(mx, dp[j]);
        dp[b] = max(dp[b], mx + 1);
    }
    cout << *max_element(dp, dp + 11) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        v.clear();
        int p, q;
        while (cin >> p >> q and (p or q)) {
            v.pb(mp(p, q));
        }
        solve();
    }

    return 0;
}
