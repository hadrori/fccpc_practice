#include <bits/stdc++.h>
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

ll w, h, v, t, x, y, p, q;

int hit(ll c, ll r)
{
    const ll left = c * w;
    const ll bot = r * h;
    const ll pp = left + (c & 1 ? w - p : p);
    const ll qq = bot  + (r & 1 ? h - q : q);

    if (abs(x - pp) > v * t or abs(y - qq) > v * t) return 0;

    return (x - pp) * (x - pp) + (y - qq) * (y - qq) <= (v * t) * (v * t);
}

const int inf = 1e9;

ll column(ll c)
{
    if (not hit(c, 0)) return hit(c, -1) + hit(c, 1);

    ll top, btm;
    {
        ll t = inf, b = 0;
        while (t - b > 1) {
            ll m = (t + b) / 2;
            if (hit(c, m)) b = m;
            else t = m;
        }
        top = b;

        t = 0, b = -inf;
        while (t - b > 1) {
            ll m = (t + b) / 2;
            if (hit(c, m)) t = m;
            else b = m;
        }
        btm = t;
    }
    return top - btm + 1;
}

void solve()
{

    ll ans = 0;
    repi(i, -1e6, 1e6) {
        ans += column(i);
    }
    cout << ans << endl;
}

int main()
{
    cin >> w >> h >> v >> t >> x >> y >> p >> q;
    solve();


    return 0;
}
