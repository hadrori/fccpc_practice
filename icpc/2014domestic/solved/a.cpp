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
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)

#define pb push_back
#define mp make_pair

using namespace std;

int x, y, s;

void solve()
{
    int ans = 0;
    repi(a, 1, s) repi(b, 1, s) {
        int aa = a * (100 + x) / 100;
        int bb = b * (100 + x) / 100;
        if (aa + bb != s) continue;
        int c = a * (100 + y) / 100;
        int d = b * (100 + y) / 100;
        ans = max(ans, c + d);
    }
    cout << ans << endl;
}

int main()
{
    while (cin >> x >> y >> s and x) {
        solve();
    }

    return 0;
}
