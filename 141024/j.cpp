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

ll T[100] = {1, 1};

void prepare()
{
    repi(i, 2, 100) T[i] = T[i - 1] + T[i - 2];
}

ll n;

void solve()
{
    const ll nn = n;

    vector<ll> ind, ans;
    repd(i, 90, 1) {
        if (n >= T[i]) {
            ind.pb(i);
            ans.pb(T[i]);
            n -= T[i];
        }
    }
    const int m = ind.size();

    cout << nn << endl;
    rep(i, m) {
        // if (i) cout << ' ';
        cout << ind[i] << ' ';
    }
    cout << endl;
    rep(i, m) {
        // if (i) cout << ' ';
        cout << ans[i] << ' ';
    }
    cout << endl << endl;
}

int main()
{
    prepare();

    int t = 0;
    while (cin >> n and n) {
        solve();
        ++t;
    }

    return 0;
}
