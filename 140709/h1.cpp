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

int main()
{
    while (cin >> mr >> Mr >> md >> Md >> s and mr) {
        ll ans = 0;
        for (int r = mr; r <= Mr; ++r) {
            for (int d = md; d <= Md; ++d) {
                int w = 4 * (d + r);
                double area = (double) s * w;
                ll tmp = ll(area / (r * r * acos(-1.0)));
                ans += tmp;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
