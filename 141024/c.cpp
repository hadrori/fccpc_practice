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
#define double long double

int main()
{
    double r;
    int cnt = 1;
    while(cin >> r, r >= 0.0) {
        vector<double> v(3);
        rep(i, 3) cin >> v[i];
        
        double ans = 0.0;
        rep(i, 3) {
            double x = (r + v[i]) / (r - v[i]) * r - (r + v[i]);
            double y = sqrt((r + v[i] + x) * (r + v[i] + x) - r * r);
            ans += r * y;
        }
        cout << "Case " << cnt++ << ": ";
        printf("%.2Lf\n", ans);
    }
    return 0;
}
