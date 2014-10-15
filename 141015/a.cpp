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

const int N = 360000;

int s, p, a[2 * N];

bool input()
{
    cin >> s >> p;
    if (s == -1) return false;
    memset(a, 0, sizeof(a));
    rep(i, p) {
        int tmp;
        cin >> tmp;
        a[tmp] = 1;
    }
    rep(i, N) a[i + N] = a[i];
    return true;
}

ll hs[2 * N + 1], powp[N + 1] = {1};

void prepare()
{
    repi(i, 1, N + 1) powp[i] = powp[i - 1] * 9973;
}

inline ll ha(int a, int b) { return hs[b] - hs[a] * powp[b - a]; }

bool attempt(int d)
{
    return ha(0, N) == ha(d, d + N);
}

const ll mod = 100000007;

ll mod_pow(ll a, ll b)
{
    ll ret = 1;
    do {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
    } while (b >>= 1);
    return ret;
}

ll mod_inv(ll k)
{
    return k == 1 ? 1 : mod_inv(mod % k) * (mod - mod / k) % mod;
}

void solve()
{
    hs[0] = 0;
    rep(i, 2 * N) {
        hs[i + 1] = hs[i] * 9973 + a[i];
    }

    int gamma = 0;
    ll ans = 0;
    rep(i, N) {
        if (attempt(i)) {
            int tmp = N / __gcd(i, N);
            ++gamma;
            ans = (ans + mod_pow(s, p / tmp)) % mod;
        }
    }
    ans = ans * mod_inv(gamma) % mod;
    cout << ans << endl;
}

int main()
{
    prepare();
    while (input()) solve();
}
