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

ll n, u[N] = {}, v[N] = {};

int main()
{
    cin >> n;
    repi(i, 1, n + 1) cin >> u[i], v[i] = u[i];
    sort(u, u + n + 1);
    rep(i, n) {
        u[i + 1] += u[i];
        v[i + 1] += v[i];
    }

    int m;
    cin >> m;
    rep(i, m) {
        int type, l, r;
        cin >> type >> l >> r;
        ll ans = 0;
        if (type == 1) {
            ans = v[r] - v[l - 1];
        } else {
            ans = u[r] - u[l - 1];
        }
        cout << ans << endl;
    }

    return 0;
}
