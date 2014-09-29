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

typedef unsigned long long ll;

ll n, X;
const int MAX = 100000;
ll hst[MAX];
vector<ll> p;
bool isprime[MAX];
void gen() {
    rep(i, MAX) isprime[i] = true;
    isprime[0] = isprime[1] = false;
    rep(i, MAX) if(isprime[i]) {
        for(int j = i*2; j < MAX; j+= i) isprime[j] = false;
    }
    rep(i, MAX) if(isprime[i]) p.pb(i);
}

ll f(ll x) {
    ll ret = 1;
    rep(i, p.size()) ret *= (hst[i]/x + 1);
    return ret;
}

void solve() {
    memset(hst, 0, sizeof(hst));
    repi(i, 1, n+1) {
        ll tmp = i;
        rep(j, p.size()) {
            if(tmp < p[j]) break;
            while(tmp%p[j] == 0) {
                hst[j]++;
                tmp /= p[j];
            }
        }
    }

    ll lim = 0;
    rep(i, n) lim = max(lim, hst[i]);
    
    ll ans = 0;
    repi(y, X, lim+1) {
        ll d = f(y) - f(y+1);
        ans += d * (d-1)/ 2;
    }
    cout << ans << endl;         
}

int main()
{
    gen();
    while(cin >> n >> X, n or X) solve();

    return 0;
}
