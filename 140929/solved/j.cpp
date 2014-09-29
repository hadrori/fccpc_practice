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

const int N = 500010;

int n, x, a[N];

void input()
{
    cin >> n >> x;
    rep(i, n) cin >> a[i];
}

int solve()
{
    const int inf = 1e9;

    int ans = inf;
    vector<pair<ll, int> > v;
    ll sum = 0;
    rep(i, n) {
        sum += a[i];
        while(v.size() and v.back().first >= sum) v.pop_back();
        vector<pair<ll, int> >::iterator itr = lower_bound(all(v), mp(sum-x, i));
        if(itr != v.begin()) {
            itr--;
            ans = min(i - itr->second, ans);
        }
        v.pb(mp(sum, i));
    }
    if(ans == inf) ans = -1;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        input();
        cout << solve() << endl;
    }

    return 0;
}
