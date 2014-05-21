#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
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

typedef vector<ll> vec;

vec in()
{
    ll x, y, z;
    cin >> x >> y >> z;

    vec ret;
    ret.pb(x);
    ret.pb(y);
    ret.pb(z);
    return ret;
}

ll sum(vec v)
{
    ll ret = 0;
    rep(i, 3) ret += abs(v[i]);
    return ret;
}

ll dot(vec u, vec v)
{
    ll ret = 0;
    rep(i, 3) ret += u[i] * v[i];
    return ret;
}

vec cross(const vec& u, const vec& v)
{
    vec ret;
    ret.pb(u[1] * v[2] - u[2] * v[1]);
    ret.pb(u[2] * v[0] - u[0] * v[2]);
    ret.pb(u[0] * v[1] - u[1] * v[0]);
    return ret;
}

vec operator -(const vec& u, const vec& v)
{
    vec ret;
    rep(i, 3) ret.pb(u[i] - v[i]);
    return ret;
}

vec a, b, c, d;

bool solve()
{
    if (a == b and b == c) {
        return a == d;
    }

    if (sum(cross(b - a, c - a)) == 0) {
        if (sum(cross(b - a, d - a)) != 0) return false;

        ll p = dot(a - d, b - d);
        ll q = dot(b - d, c - d);
        ll r = dot(c - d, a - d);

        if (p >= 0 and q >= 0 and r >= 0) return false;

        return true;
    }

    vec u = cross(b - a, d - a);
    vec v = cross(c - b, d - b);
    vec w = cross(a - c, d - c);

    ll p = dot(u, v);
    ll q = dot(v, w);
    ll r = dot(w, u);

    return p > 0 and q > 0 and r > 0;
}

int main()
{
    for (;;) {
        a = in();
        if (sum(a) == 0) break;
        b = in();
        c = in();
        d = in();

        cout << (solve() ? "YES" : "NO") << endl;
    }

    return 0;
}
