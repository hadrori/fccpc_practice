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

set<string> S, T;

void dfs(char (*p)[6], int i, set<string>& S, string& cur)
{
    if (i == 5) {
        S.insert(cur);
        return;
    }
    rep(j, 6) {
        cur.pb(p[j][i]);
        dfs(p, i + 1, S, cur);
        cur.pop_back();
    }
}

void solve()
{
    S.clear();
    T.clear();

    string tmp;
    dfs(s, 0, S, tmp);
    dfs(t, 0, T, tmp);

    set<string> u;
    set_intersection(S.begin(), S.end(), T.begin(), T.end(), inserter(u, u.begin()));
    if ((int) u.size() < k) {
        cout << "NO" << endl;
    } else {
        auto it = u.begin();
        while (--k) ++it;
        cout << *it << endl;
    }
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
