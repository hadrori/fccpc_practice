#include <algorithm>
#include <bitset>
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

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int n;
vector<ll> a;

ll attempt() {
    ll ret = 0;
    int cnt = 0;
    for (int j = 0; j < n - 2; ++j) {
	if (a[j] < a[j + 1] + a[j + 2]) {
	    ret += a[j] + a[j + 1] + a[j + 2];
	    if (++cnt == 2)
		return ret;
	    j += 2;
	}
    }
    return 0;
}

inline int next(int s) { int foo = s & -s, bar = s + foo; return bar | (s & ~bar) / foo >> 1; }

bool chk(int i, int s)
{
    ll tmp = 0;
    int cnt = 0;
    rep(j,6) {
	if (s >> j & 1) {
	    if (cnt++)
		tmp += a[i + j];
	    else
		tmp -= a[i + j];
	}
    }
    return tmp > 0;
}

ll attempt1(int i) {
    for (int s = 7; s < 1<<6; s = next(s)) {
	if (chk(i, s) && chk(i, 63 ^ s)) {
	    ll ret = 0;
	    rep(j,6)
		ret += a[i + j];
	    return ret;
	}
    }
    return 0;
}

int main() {
    cin >> n;
    rep(i,n){
	ll t;
	cin >> t;
	a.pb(t);
    }
    sort(rall(a));

    ll ans = 0;
    ans = max(ans, attempt());
    rep(i,n-5)
	ans = max(ans, attempt1(i));
    cout << ans << endl;

    return 0;
}
