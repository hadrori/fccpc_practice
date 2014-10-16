#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(u) begin(u),end(u)
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define ll long
#define long int64_t
#define mp make_pair
#define pb push_back
#define eb emplace_back

int k;
char s[6][6], t[6][6];

void input()
{
    cin >> k;
    rep(i, 6) cin >> s[i];
    rep(i, 6) cin >> t[i];
}

int s_bit[5], t_bit[5], rest[6];

void solve()
{
    memset(s_bit, 0, sizeof(s_bit));
    memset(t_bit, 0, sizeof(t_bit));
    memset(rest, 0, sizeof(rest));
    rep(i, 5) rep(j, 6) {
        s_bit[i] |= 1 << (s[j][i] - 'A');
        t_bit[i] |= 1 << (t[j][i] - 'A');
    }
    rep(i, 5) s_bit[i] &= t_bit[i];
    rest[5] = 1;
    for (int i = 4; i >= 0; --i) {
        rest[i] = rest[i + 1] * __builtin_popcount(s_bit[i]);
    }
    if (rest[0] < k) {
        cout << "NO" << endl;
        return;
    }
    --k;
    rep(i, 5) {
        const int c = k / rest[i + 1];
        int tmp = 0;
        rep(j, 26) if (s_bit[i] >> j & 1) {
            if (tmp == c) {
                cout << char('A' + j);
                break;
            }
            ++tmp;
        }
        k -= c * rest[i + 1];
    }
    cout << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }

    return 0;
}
