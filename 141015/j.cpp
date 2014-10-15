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
#define repi(i,a,b) for(int i = (int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i = (int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it = (u).begin(); it!=(u).end(); ++it)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 5000000;

vector<int> primes;
int c[N];

void prepare()
{
    for (int i = 2; i * i < N; ++i) {
        if (not c[i]) {
            for (int j = i * i; j < N; j += i) {
                c[j] = 1;
            }
        }
    }
    repi(i, 2, N) {
        if (not c[i]) primes.pb(i);
    }
}

const ll mod = 1000000007;

ll n;

ll mod_pow(ll a, ll b) {
    ll ret = 1;
    do {
        if (b & 1) (ret *= a) %= mod;
        (a *= a) %= mod;
    } while (b >>= 1);
    return ret;
}

ll div_fact(ll n, ll p) {
    ll ret = 0;
    while (n /= p) ret += n;
    return ret;
}

void solve()
{
    ll ret = 1;
    rep(i, primes.size()) {
        int p = primes[i];
        (ret *= mod_pow(p, div_fact(n, p) & ~1LL)) %= mod;
    }
    cout << ret << endl;
}

int main()
{
    prepare();
    while (cin >> n and n) solve();

    return 0;
}
