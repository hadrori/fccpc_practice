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

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int mr, Mr, md, Md, s;
int r, d, h;
double hole;

ll f(double s)
{
    ll row = ll(s / h);
    if (row == 0) return 0;
    ll ret = 2 * row;
    double rest = (s - row * h) * (h + h);
    rest += ret * hole;
    ret += f(rest / (h + h));
    return ret;
}

int main()
{
    while (cin >> mr >> Mr >> md >> Md >> s and mr) {
        ll ans = 0;
        for (r = mr; r <= Mr; ++r) {
            for (d = md; d <= Md; ++d) {
                h = 2 * (d + r);
                hole = r * r * acos(-1.0);
                ans += f(s);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
