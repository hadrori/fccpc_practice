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
typedef pair<ll, ll> pii;

bool side(pii p, pii q, pii r)
{
    ll a = q.first - p.first;
    ll b = q.second - p.second;
    ll c = r.first - p.first;
    ll d = r.second - p.second;
    return a * d - b * c >= 0;
}

bool side1(pii p, pii q, pii r)
{
    ll a = q.first - p.first;
    ll b = q.second - p.second;
    ll c = r.first - p.first;
    ll d = r.second - p.second;
    return a * d - b * c > 0;
}

int n;
vector<pair<pii, int> > v;

void solve()
{
    cin >> n;
    v.clear();
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(mp(x, y), i));
    }
    sort(all(v));

    vector<int> up, dn;
    repi(i, 1, n - 1) {
        if (side(v[0].first, v.back().first, v[i].first)) {
            up.pb(v[i].second);
        } else {
            dn.pb(v[i].second);
        }
    }
    if ((int) up.size() == n - 2) {
        up.clear(), dn.clear();
    repi(i, 1, n - 1) {
        if (side1(v[0].first, v.back().first, v[i].first)) {
            up.pb(v[i].second);
        } else {
            dn.pb(v[i].second);
        }
    }
    }
    reverse(all(dn));
    rep(i, up.size()) cout << up[i] << ' ';
    cout << v.back().second << ' ';
    rep(i, dn.size()) cout << dn[i] << ' ';
    cout << v[0].second << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
