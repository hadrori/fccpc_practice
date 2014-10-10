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
int n;
vector<point> p;
double r;

point rotate(point a, double th) {
    return a * polar(1.0, th);
}

point rec(vector<point> ps, double len, int d) {
    double sum = 0.0;
    if(d < 0) {
        point dir = ps[n-1] - ps[0];
        dir /= abs(dir);
        return ps[0] + dir * len;
    }
    
    rep(i, ps.size()-1) {
        sum += abs(ps[i+1]-ps[i]) * pow(r, d);
        if(sum > len) {
            vector<point> nps = p;
            point vec = ps[i+1] - ps[i];
            double th = arg(vec);
            rep(j, nps.size()) {
                nps[j] *= abs(vec) / abs(p[n-1] - p[0]);
                nps[j] = rotate(nps[j], th);
                nps[j] += ps[i];
            }
            return rec(nps, len-sum+abs(ps[i+1]-ps[i])*pow(r, d), d-1);
        }
    }
    return ps[n-1];
}

void solve() {
    vector<point> tp;
    cin >> n;
    rep(i, n) {
        double x, y;
        cin >> x >> y;
        tp.pb(point(x, y));
    }

    int d;
    double f;
    cin >> d >> f;
    double sum = 0;
    rep(i, n-1) sum += abs(tp[i+1] - tp[i]);
    
    double len = abs(tp[n-1] - tp[0]);
    r = sum / len;
    double th = arg(tp[n-1] - tp[0]);

    p.clear();
    rep(i, n) {
        point tmp = tp[i] - tp[0];
        tmp = rotate(tmp, -th);
        tmp /= len;
        p.pb(tmp);
    }
    d--;
    point ans = rec(tp, f * sum * pow(r, d), d);
    printf("(%.9f,%.9f)\n", ans.real(), ans.imag());
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
