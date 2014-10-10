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
const int MAX = 128;
int n;
int d;
double f;
vector<point> p;
double len[MAX];
double slen[MAX];
point sp;
double sth;

point rotate(point a, double th) {
    return point(a.real() * cos(th) - a.imag() * sin(th),
                 a.real() * sin(th) + a.imag() * cos(th));
}

point rec(int depth, double obj) {
    if(depth == d) return point(obj, 0);
    cout << "obj " << obj << endl;
    rep(i, n-1) {
        if(slen[i] > obj) {
            cout << i << " " << obj << " " << slen[i] << endl;
            return p[i] + rotate(rec(depth+1, (len[i]/slen[n-2]) * (obj - (i?slen[i-1]:0))),
                              arg(p[i+1] - p[i]));
        }
    }
    return point(0, 0);
}

void solve() {
    cin >> n;
    p.clear();
    rep(i, n) {
        double x, y;
        cin >> x >> y;
        p.pb(point(x, y));
    }
    // convert
    double sx = p[0].real(), sy = p[0].imag();
    sp = point(sx, sy);
    rep(i, n) p[i] = point(p[i].real()-sx, p[i].imag()-sy);
    sth = arg(p[n-1]);
    rep(i, n) p[i] = rotate(p[i], -sth);
    
    rep(i, n-1) len[i] = abs(p[i+1]-p[i]);
    slen[0] = len[0];
    rep(i, n-2) slen[i+1] = slen[i] + len[i+1];
    
    cin >> d >> f;
    point ans = rec(0, f * slen[n-2]);
    ans = rotate(ans, sth);
    cout << ans.real() + sx << " " << ans.imag() + sy << endl;
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
