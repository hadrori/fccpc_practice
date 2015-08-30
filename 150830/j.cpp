#include <bits/stdc++.h>
using namespace std;

#define repi(i,a,b) for(int i = (int)(a); i<(int)(b); ++i)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

const int M = 2000010;

int m, n;
ll l[M], h[M];

void input()
{
    string s;
    cin >> n >> m >> s;
    int t = 0, i = 0;
    for (char c : s) {
        ++i;
        if (c == '/') {
            l[i] = ++t;
            h[i] = ++t;
        } else if (c == '\\') {
            l[i] = --t;
            h[i] = --t;
        } else if (c == '_') {
            l[i] = t;
            h[i] = t;
        }
    }
    partial_sum(l, l + n + 1, l);
}

void solve()
{
    ll ans = 1e18;
    deque<pair<int, int>> deq;
    for (int i = 0; i <= n; ++i) {
        while (not deq.empty() and deq.front().first < i - m) deq.pop_front();
        while (not deq.empty() and deq.back().second >= h[i]) deq.pop_back();
        deq.emplace_back(i, h[i]);
        if (i >= m) {
            const ll mn = deq.front().second;
            const ll tmp = l[i] - l[i - m] - mn * m;
            ans = min(ans, tmp);
        }
    }
    cout << ans / 2 << '.' << ans % 2 * 5  << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        input();
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
