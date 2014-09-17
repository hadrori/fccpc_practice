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

const int N = 100010;

int n;
double pw, vw[N], pf[N], vf[N], th[N];

double attempt(double w)
{
    double ret = w * pw;
    rep(i, n) {
        const double diff = th[i] - w * vw[i];
        if (diff > 0.0) {
            ret += diff / vf[i] * pf[i];
        }
    }
    return ret;
}

void solve()
{
    double l = 0.0, r = 0.0;
    rep(i, n) if (vw[i] > 0.0) {
        r = max(r, th[i] / vw[i]);
    }

    rep(i, 100) {
        const double m1 = (2.0 * l + r) / 3.0;
        const double m2 = (l + 2.0 * r) / 3.0;

        if (attempt(m1) < attempt(m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }
    printf("%.8f\n", attempt(l));
}

int main()
{
    while (cin >> n and n) {
        cin >> pw;
        rep(i, n) cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
        solve();
    }

    return 0;
}
