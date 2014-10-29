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

const int N = 100010;

ll n, m, s[N], p[N], q[N];

void input()
{
    scanf("%lld%lld", &n, &m);
    rep(i, n) scanf("%lld%lld", s+i, p+i);
    rep(i, m) scanf("%lld", q+i);
}

ll mn[N];

void solve()
{
    rep(i, n) mn[i] = s[i] * p[i];
    for (int i = n - 2; i >= 0; --i) {
        mn[i] = min(mn[i], mn[i + 1]);
    }

    rep(i, m) {
        int pos = upper_bound(s, s + n, q[i]) - s - 1;
        ll ans = q[i] * p[pos];
        if (pos < n - 1) ans = min(ans, mn[pos + 1]);
        printf("%lld\n", ans);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        input();
        solve();
    }

    return 0;
}
