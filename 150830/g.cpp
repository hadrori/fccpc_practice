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

const int N = 1024;

int n, k, p[N];

void input() 
{
    cin >> n >> k;
    rep(i, k) cin >> p[i];
    sort(p, p + k);
}

int on[N];

void solve()
{
    const int th = 32;
    vector<int> sp, lp;
    rep(i, k) {
        if(p[i] <= th)
            sp.pb(p[i]);
        else 
            lp.pb(p[i]);
    }

    int ans = 0;
    rep(S, 1<<sp.size()) {
        vector<int> v(n+1, 0);
        rep(i, sp.size()) if((S>>i)&1) {
            for(int a = sp[i]; a <= n; a += sp[i]) {
                v[a] ^= 1;
            }
        }
        
        int tmp = 0;
        rep(i, v.size()) if(v[i]) tmp++;
        
        rep(i, lp.size()) {
            int df = 0;
            for(int a = lp[i]; a <= n; a += lp[i]) {
                if(v[a]) df--;
                else df++;
            }
            if(df > 0)
                tmp += df;
        }
        
        ans = max(ans, tmp);
    }
    cout << ans << endl;
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
