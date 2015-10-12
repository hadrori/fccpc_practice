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

int n;

void solve(int n)
{
    vector<pair<int, int>> ans;
    int x = 0, y = 0, mx = 0, my = 0;
    ans.emplace_back(x, y);
    int c = n/3+10;
    if (n==3) {
        cout << 3 << endl;
        cout << "0 0" << endl;
        cout << "0 1" << endl;
        cout << "1 0" << endl;
        return;
    }
    rep(i, (n-1)/3) {
        --c;
        x += 1, y += c;
        ans.emplace_back(x, y);
        mx = min(mx, x), my = min(my, y);
        x += c, y -= 1;
        ans.emplace_back(x, y);
        mx = min(mx, x), my = min(my, y);
        x -= 1, y -= c;
        ans.emplace_back(x, y);
        mx = min(mx, x), my = min(my, y);
    }
    if (n % 3 == 2) {
        x = 0;
        ans.emplace_back(x, y);
        mx = min(mx, x), my = min(my, y);
    }
    if (n % 3 == 0) {
        x = -1;
        ans.emplace_back(x, y);
        mx = min(mx, x), my = min(my, y);
        y = 0;
        ans.emplace_back(x, y);
        mx = min(mx, x), my = min(my, y);
    }
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first-mx << ' ' << p.second-my << endl;
    }
}

int main()
{
    int t;
    for (cin >> t; t--; ) {
        int n;
        cin >> n;
        solve(n);
    }
}
