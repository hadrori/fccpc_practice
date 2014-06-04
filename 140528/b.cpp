#include <algorithm>
#include <bitset>
#include <cassert>
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

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;

const ll mod = 0x104c11db7ULL;

int n;
char str[1000001];

ll mul(ll a, ll b)
{
    ll ret = 0;
    do {
        if (a & 1) ret ^= b;
        b = b << 1;
        if (b >> 32) b ^= mod;
    } while (a >>= 1);
    return ret;
}

unsigned int checksum()
{
    ll r = 0;
    rep(i, n) {
        // r = norm(r << 8 | str[i]);
        r = r << 8 | str[i];
        for (int j = 8; j >= 0; --j) {
            if (r >> j + 32) {
                r ^= mod << j;
            }
        }
    }
    return r;
}

void input()
{
    scanf("%d ", &n);
    fgets(str, sizeof(str), stdin);
}

const int N = 8000010;

ll pow2[N] = {1};

void prepare()
{
    rep(i, N - 1) {
        pow2[i + 1] = pow2[i] << 1;
        if (pow2[i + 1] >> 32) pow2[i + 1] ^= mod;
    }
}

void solve()
{
    unsigned int ans = checksum();
    printf("%u\n", ans);

    int ch;
    scanf("%d", &ch);
    rep(i, ch) {
        int p; char c;
        scanf("%d %c", &p, &c);

        ans ^= mul(c ^ str[p - 1], pow2[(n - p) * 8]);

        str[p - 1] = c;

        printf("%u\n", ans);
    }
}

int main()
{
    prepare();

    int t;
    scanf("%d", &t);
    while (t--) {
        input();
        solve();
    }

    return 0;
}
