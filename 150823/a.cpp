#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

int n, m, l;
vector<pair<int, int>> links;

void input()
{
    cin >> n >> m >> l;
    links.clear();
    rep(_, m) {
        int i, k;
        cin >> i >> k;
        links.emplace_back(-k, i);
    }
    sort(all(links));
}

void solve()
{
    vector<int> ans(n);
    iota(all(ans), 0);
    for (const auto& p : links) {
        swap(ans[p.second], ans[p.second + 1]);
    }
    for (int i : ans) {
        cout << i << endl;
    }
    cout << endl;
}

int main()
{
    int t;
    for (cin >> t; t--; ) {
        input();
        solve();
    }
    return 0;
}
