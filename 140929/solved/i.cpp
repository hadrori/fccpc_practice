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

int main()
{
    int n;
    cin >> n;
    const double eps = 1e-6;
    int ans = 0;
    rep(i, n) {
        double l, w, d, g;
        cin >> l >> w >> d >> g;
        if(((l < 56.0 + eps and
           w < 45.0 + eps and
            d < 25.0 + eps) or
            l + w + d < 125.0 + eps) and
           g < 7.0 + eps) {
            cout << "1" << endl;
            ans++;
        } else {
            cout << "0" << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
