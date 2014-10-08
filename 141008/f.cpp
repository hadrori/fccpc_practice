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

const int N = 1000010;
const int inf = int(1e9) + 10;
const int mod = 1000000007;

int n, x[N], y[N], pow2[N] = {1};

void solve()
{
    int mx = *min_element(x, x + n);
    int Mx = *max_element(x, x + n);
    int my = *min_element(y, y + n);
    int My = *max_element(y, y + n);

    int mxmy = inf, Mxmy = inf;
    int mxMy = -inf, MxMy = -inf;
    int mymx = inf, Mymx = inf;
    int myMx = -inf, MyMx = -inf;
    rep(i, n) {
        if (x[i] == mx) {
            mxmy = min(mxmy, y[i]);
            mxMy = max(mxMy, y[i]);
        }
        if (x[i] == Mx) {
            Mxmy = min(Mxmy, y[i]);
            MxMy = max(MxMy, y[i]);
        }
        if (y[i] == my) {
            mymx = min(mymx, x[i]);
            myMx = max(myMx, x[i]);
        }
        if (y[i] == My) {
            Mymx = min(Mymx, x[i]);
            MyMx = max(MyMx, x[i]);
        }
    }

    int need = 0, edges = 8;
    if (mxmy - my < mymx - mx) need |= 1 << 0;
    if (mxmy - my > mymx - mx) need |= 1 << 4;
    if (My - mxMy < Mymx - mx) need |= 1 << 1;
    if (My - mxMy > Mymx - mx) need |= 1 << 6;
    if (Mxmy - my < Mx - myMx) need |= 1 << 2;
    if (Mxmy - my > Mx - myMx) need |= 1 << 5;
    if (My - MxMy < Mx - MyMx) need |= 1 << 3;
    if (My - MxMy > Mx - MyMx) need |= 1 << 7;
    if (mxmy == mxMy) --edges, need |= 3 << 0;
    if (Mxmy == MxMy) --edges, need |= 3 << 2;
    if (mymx == myMx) --edges, need |= 3 << 4;
    if (Mymx == MyMx) --edges, need |= 3 << 6;
    if (mx == Mx and my == My) edges = 1, need = (1 << 8) - 1;
    else if (mx == Mx or my == My) edges = 2, need = 255;

    int ans = 0;
    rep(i, 1 << 8) {
        if (need & ~i) continue;
        bool flag = true;
        rep(j, 4) {
            flag &= !!(i & 3 << j);
        }
        flag &= !!(i & 17);
        flag &= !!(i & 66);
        flag &= !!(i & 36);
        flag &= !!(i & 136);
        if (!flag) continue;
        ans += pow2[n - edges];
        if (ans >= mod) ans -= mod;
    }
    cout << ans << endl;
}

int main()
{
    repi(i, 1, N) {
        pow2[i] = pow2[i - 1] << 1;
        if (pow2[i] >= mod) pow2[i] -= mod;
    }

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        rep(i, n) cin >> x[i] >> y[i];
        solve();
    }

    return 0;
}
