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

const int N = 10000000;

char c[N] = {};
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

typedef ll Int;

ll mmul(ll a, ll b, ll mod)
{
    ll ret = 0;
    do {
        if (b & 1) {
            ret += a;
            if (ret >= mod) ret -= mod;
        }
        a += a;
        if (a >= mod) a -= mod;
    } while (b >>= 1);
    return ret;
}

ll powMod(ll a, ll b, ll mod)
{
    ll ret = 1;
    do {
        if (b & 1) ret = mmul(ret, a, mod);
        a = mmul(a, a, mod);
    } while (b >>= 1);
    return ret;
}

bool suspect(Int a, int s, Int d, Int n) {
    Int x = powMod(a, d, n);
    if (x == 1) return true;
    for (int r = 0; r < s; ++r) {
        if (x == n - 1) return true;
        x = mmul(x, x, n);
    }
    return false;
}
// {2,7,61,-1}                 is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)
bool isPrime(Int n) {
    if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
    int test[] = {2,3,5,7,11,13,17,19,23,-1};
    Int d = n - 1, s = 0;
    while (d % 2 == 0) ++s, d /= 2;
    for (int i = 0; test[i] < n && test[i] != -1; ++i)
        if (!suspect(test[i], s, d, n)) return false;
    return true;
}

ll solve(ll n)
{
    n /= (n & -n);

    if (isPrime(n)) return 6;

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
