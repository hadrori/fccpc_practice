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

int main()
{
    int n;
    cin >> n;
    const ll inf = 1e10;
    ll minx = inf, miny = inf, maxx = -inf, maxy = -inf;
    
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        minx = min(minx, x);
        miny = min(miny, y);

        maxx = max(maxx, x);
        maxy = max(maxy, y);
    }

    ll a = max(maxx - minx, maxy - miny);
    cout << a*a << endl;
    
    return 0;
}
