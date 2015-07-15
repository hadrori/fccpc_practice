#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define all(c) begin(c),end(c)
#ifndef DEBUG
const string name = "business"; // input filename here!!
ifstream fin(name + ".in");
ofstream fout(name + ".out");
#define cin fin
#define cout fout
#endif

int n, m;
const long inf = 10000000000LL;
long solve(long u, long d) {
    long lower = 0;
    long upper = n;
    while(upper - lower > 1) {
        long mid = (upper + lower) / 2;
        if(u * mid - d * (n-mid) <= 0) lower = mid;
        else upper = mid;
    }
    return u*upper - d*(n-upper);
}

void solve()
{
    cin >> n >> m;
    long ans = inf;
    rep(i, m) {
        long u, d;
        cin >> u >> d;
        ans = min(ans, solve(u, d));
    }
    cout << ans << endl;
}

int main()
{
    solve();
}
