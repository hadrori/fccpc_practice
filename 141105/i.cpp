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

int n, m;
vector<int> c;
void input()
{
    cin >> n >> m;
    c.resize(m);
    rep(i, m) cin >> c[i];
    sort(all(c));
}

const int inf = 100000000;
void solve()
{
    int x = -inf, y = inf;
    rep(i, m) {
        x = max(x, (n/m)*i - c[i]);
        y = min(y, (n/m)*i - c[i]);
    }
    cout << (x-y+1)/2 << endl;
}

int main()
{
    int t;
    cin >> t;
    rep(i, t) {
        input();
        cout << "Case #" << i + 1 << ": ";
        solve();
    }

    return 0;
}
