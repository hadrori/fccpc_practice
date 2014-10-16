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
int n;
const int MAX = 1024;
ll f[MAX][MAX];
const int di[] = {-1, 0, 1, 0};
const int dj[] = { 0, 1, 0,-1};
const int dirs[5][3] = {
    {1, 1, 1},
    {1, 2, 1},
    {1, 1, 2},
    {1, 2, 0},
    {1, 2, 3}
};

void solve() {
    rep(i, n) rep(j, n) cin >> f[i][j];

    ll ans = -100000000000LL;
    rep(i, n) rep(j, n) rep(pid, 5) rep(d, 4) {
        ll sum = f[i][j];
        int ti = i, tj = j;
        bool ok = true;
        rep(turn, 3) {
            int tdir = (dirs[pid][turn] + d)%4;
            ti += di[tdir];
            tj += dj[tdir];
            if(ti < 0 or tj < 0 or ti >= n or tj >= n) {
                ok = false;
                break;
            }
            sum += f[ti][tj];
            if(pid == 3 and turn == 1) {
                ti += di[(1+d)%4];
                tj += dj[(1+d)%4];
            }
                
        }
        if(ok) ans = max(ans, sum);
    }
    cout << ans << endl;
}

int main()
{
    int cnt = 0;
    while(cin >> n, n) {
        cout << ++cnt << ". ";
        solve();
    }
    return 0;
}
