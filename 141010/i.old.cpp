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
typedef complex<double> point;

point o;

struct cmp
{
    bool operator()(const pair<point, int>& p, const pair<point, int>& q) {
        point a = p.first, b = q.first;
        return arg(a - o) < arg(b - o);
    }
};

struct cmp1
{
    bool operator()(const pair<point, int>& p, const pair<point, int>& q) {
        point a = p.first, b = q.first;
        return abs(a - o) < abs(b - o);
    }
};

struct cmp2
{
    bool operator()(const pair<point, int>& p, const pair<point, int>& q) {
        point a = p.first, b = q.first;
        return abs(a - o) > abs(b - o);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<point> v;
    rep(i, n) {
        double x, y;
        cin >> x >> y;
        v.pb(point(x, y));
    }
    o = v[0];
    vector<pair<point, int> > u;
    repi(i, 1, n) {
        u.pb(mp(v[i], i));
    }
    sort(all(u), cmp());
    int tmp = 0;
    const double eps = 1e-8;
    while (tmp < n - 2 and abs(arg(u[tmp].first) - arg(u[tmp+1].first)) < eps) {
        ++tmp;
    }
    sort(u.begin(), u.begin() + tmp + 1, cmp1());
    tmp = n - 2;
    while (tmp >= 1 and abs(arg(u[tmp].first) - arg(u[tmp-1].first)) < eps) {
        --tmp;
    }
    sort(u.begin() + tmp, u.end(), cmp2());
    rep(i, n - 1) cout << u[i].second << ' ';
    cout << 0 << endl;
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
