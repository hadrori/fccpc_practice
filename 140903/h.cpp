#include <bits/stdc++.h>
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

const int N = 300010;
const ll p = 86028121;

char s[N], t[N];
int len_s, len_t;

ll powp[N] = {1};
ll hash_s[N] = {};
ll hash_t[N] = {};

void prepare()
{
    len_s = strlen(s);
    len_t = strlen(t);

    rep(i, N - 1) powp[i + 1] = powp[i] * p;
    rep(i, len_s) hash_s[i + 1] = hash_s[i] * p + s[i];
    rep(i, len_t) hash_t[i + 1] = hash_t[i] * p + t[i];
}

ll ha(ll *h, int a, int b)
{
    return h[b] - h[a] * powp[b - a];
}

bool coincide(int a, int b, int c, int d)
{
    if (b > len_s or d > len_t) return false;

    return ha(hash_s, a, b) == ha(hash_t, c, d);
}

int attempt(int pos)
{
    int l = 0, r = len_t + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (coincide(pos, pos + m, 0, m)) l = m;
        else r = m;
    }

    if (l == len_t) return 0;

    int ll = 0, rr = len_t - l;
    while (rr - ll > 1) {
        int m = (ll + rr) / 2;
        if (coincide(pos + l + 1, pos + l + 1 + m,
                     l + 1, l + 1 + m)) ll = m;
        else rr = m;
    }

    return l + 1 + ll == len_t;
}

void solve()
{
    prepare();

    int ans = 0;
    rep(i, len_s - len_t + 1) {
        ans += attempt(i);
    }
    cout << ans << endl;
}

int main()
{
    cin >> s >> t;

    solve();

    return 0;
}
