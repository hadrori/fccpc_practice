#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define rep(i,a) repi(i,0,a)
#define repi(i,a,b) for(int i=(a);i<(b);i++)

using namespace std;

const int N = 128;

int n, m, s[N], t[N];

void input()
{
    rep(i, n) cin >> s[i];
    rep(j, m) cin >> t[j];
}

const int inf = 1000000;

void solve()
{
    const int S = accumulate(s, s + n, 0);
    const int T = accumulate(t, t + m, 0);

    int mn = inf, a = -1, b = -1;
    rep(i, n) rep(j, m) {
        if (S - s[i] + t[j] == T - t[j] + s[i] and mn > s[i] + t[j]) {
            mn = s[i] + t[j];
            a = s[i], b = t[j];
        }
    }
    if (mn == inf) {
        cout << -1 << endl;
    } else {
        cout << a << ' ' << b << endl;
    }
}

int main()
{
    while (cin >> n >> m and n) {
        input();
        solve();
    }

    return 0;
}
