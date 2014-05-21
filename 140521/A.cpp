#include <algorithm>
#include <bitset>
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

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double eps = 1e-8;

int a, b;
double w;

bool check(int n, double l)
{
    vector<pair<double, int> > v;
    rep(i, n) {
        double x;
        cin >> x;
        v.pb(mp(x - w, 1));
        v.pb(mp(x + w, -1));
    }
    sort(all(v));

    int nest = 0;
    rep(i, int(v.size())) {
        nest += v[i].second;
        if (nest == 0 and 0 < v[i].first and v[i].first < l) {
            return false;
        }
    }

    return true;
}

void solve()
{
    w = w / 2 + eps;

    bool ret = check(a, 75.0);
    ret &= check(b, 100.0);

    cout << (ret ? "YES" : "NO") << endl;
}

int main()
{
    while (cin >> a >> b >> w and a) {
        solve();
    }

    return 0;
}
