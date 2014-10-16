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

const int N = 30;

int len;
char line[N];

void input()
{
    cin >> line;
    len = strlen(line);
}

int n;
vector<pair<char, int> > v;

int dp[N][N];

int recur(int a, int b)
{
    int& ret = dp[a][b];
    if (ret >= 0) return ret;
    if (a == b) return ret = 1;
    if (a + 1 == b) {
        return ret = v[a].second >= 2;
    }

    repi(m, a + 1, b) {
        int tmp = recur(a, m) & recur(m, b);
        if (tmp) return ret = 1;
    }
    if (v[a].first != v[b - 1].first) {
        return ret = 0;
    }
    return ret = recur(a + 1, b - 1);
}

void solve()
{
    v.clear();
    int cnt = 0;
    rep(i, len) {
        ++cnt;
        if (i == len - 1 or line[i] != line[i + 1]) {
            v.eb(line[i], cnt);
            // cerr << line[i] << ' ' << cnt << endl;
            cnt = 0;
        }
    }
    n = v.size();
    assert(n < N);
    memset(dp, -1, sizeof(dp));
    cout << recur(0, n) << endl;
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
