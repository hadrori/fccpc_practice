#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 1000010;

int n, a[N];

void input()
{
    scanf("%d", &n);
    rep(i, n) scanf("%d", a + i);
}

const ll inf = 1e16;

ll dp[N];

void solve()
{
    pair<ll, ll> mn = {-inf, inf}, mx = {-inf, -inf};
    rep(i, n) {
        dp[i] = dp[i-1];
        if (a[i] > mn.second) {
            dp[i] = max(dp[i], mn.first + a[i]);
        }
        if (a[i] < mx.second) {
            dp[i] = max(dp[i], mx.first - a[i]);
        }
        ll opt = dp[i-1], val = a[i];
        mn = max(mn, make_pair(opt - val, val));
        mx = max(mx, make_pair(opt + val, val));
    }
    cout << dp[n-1] << endl;
}

int main()
{
    input();
    solve();
    return 0;
}
