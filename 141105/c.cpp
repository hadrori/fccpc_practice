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
#define int ll

int n;
vector<vector<int> > E;
void input()
{
    cin >> n;
    E.clear();
    E.resize(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b; a--; b--;
        E[a].pb(b);
        E[b].pb(a);
    }
}

int ans;

int dfs(int now, int par) {
    vector<int> v;
    int sum = 0;
    rep(i, E[now].size()) if(E[now][i] != par) {
        int tmp = dfs(E[now][i], now);
        sum += tmp;
        v.pb(tmp);
    }
    v.pb(n-sum-1);

    int val = 0;
    rep(i, v.size()) val += v[i];
    val *= val;
    rep(i, v.size()) val -= v[i] * v[i];
    val /= 2;
    ans = max(ans, val);
    
    return sum+1;
}

void solve()
{
    ans = 0;
    dfs(0, -1);
    cout << ans << endl;
}

signed main()
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
