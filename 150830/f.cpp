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

void solve()
{
    int n;
    cin >> n;
    set<int> as;
    vector<int> av;
    vector<tuple<int, int, int>> cbas;
    rep(_, n) {
        int a, b, c;
        cin >> a >> b >> c;
        as.insert(a);
        av.push_back(a);
        cbas.emplace_back(c, b, a);
    }
    sort(all(av));
    uniq(av);
    sort(all(cbas));
    int ans = as.size(), last = -1;
    for (auto cba : cbas) {
        int c, b, a;
        tie(c, b, a) = cba;
        int k = upper_bound(all(av), c) - lower_bound(all(av), b) - (b <= a and a <= c);
        if (k >= 1) continue;
        if (b <= last and last <= c) continue;
        ++ans, last = c;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
