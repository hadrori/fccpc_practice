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
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

ll q;
/*
ll f(ll n, ll m)
{
    ll a = n, b = n + 1;
    if (a % 2 == 0) a >>= 1;
    else b >>= 1;

    ll ret = 0;
    do {
        if (b & 1) (ret += a) %= m;
        (a += a) %= m;
    } while (b >>= 1);
    return ret;
}

int attempt(ll p)
{
    ll diff = (f(p + q, p - q) - 2 * f(p, p - q)) % (p - q);
    if (diff == 0) cerr << p - q << ' ';
    return diff == 0;
}
*/
const int N = 10000000;

bitset<N> c;
int primes[N / 10] = {1, 1}, p_cnt = 0;

void gen()
{
    for (int i = 2; i * i < N; ++i) {
        if (not c[i]) {
            for (int j = i * i; j < N; j += i) {
                c[j] = 1;
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        if (not c[i]) {
            primes[p_cnt++] = i;
        }
    }
}

ll solve(ll n)
{
    n /= (n & -n);

    ll ans = 2;
    rep(i, p_cnt) {
        const int& p = primes[i];
        // if ((ll) p * p > n) break;
        int cnt = 0;
        while (n % p == 0) {
            n /= p, ++cnt;
        }
        if (cnt) ans *= (cnt << 1) + 1;
    }
    if (n > 1) ans *= 3;
    return ans;
}

int main()
{
    gen();

    while (cin >> q and q) {
        cout << solve(q) << endl;
    }

    return 0;
}
