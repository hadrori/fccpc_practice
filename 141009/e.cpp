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

//
const ll mod = 9999991;
const int MAX = 128;
ll C[MAX][MAX];
void gen() {
    C[0][0] = 1;
    rep(i, MAX-1) rep(j, i+2) {
        ll a = (j==0?0:C[i][j-1]);
        ll b = (j==i+1?0:C[i][j]);
        C[i+1][j] = (a + b)%mod;
    }
}

int n;
int a[MAX];
void input()
{
    cin >> n;
    rep(i, n) cin >> a[i];
}
int l[MAX], r[MAX], num[MAX];
ll dp[MAX];
void solve()
{
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    memset(num, 0, sizeof(num));
    int root = -1;
    rep(i, n) {
        int now = root;
        if(now == -1) {
            root = a[i];
            continue;
        }
        while(true) {
            if(now < a[i]) {
                if(l[now] == -1) {l[now] = a[i]; break; }
                else now = l[now];
            } else if(now > a[i]) {
                if(r[now] == -1) {r[now] = a[i]; break; }
                else now = r[now];
            }
        }
    }

    memset(dp, 0, sizeof(dp));
    for(int i = n-1; i >= 0; i--) {
        int now = a[i];
        ll dpl, dpr;
        int numl, numr;
        if(l[now] == -1) dpl = 1, numl = 0;
        else dpl = dp[l[now]], numl = num[l[now]];
        if(r[now] == -1) dpr = 1, numr = 0;
        else dpr = dp[r[now]], numr = num[r[now]];
        num[now] = numl + numr + 1;
        dp[now] = ((dpl * dpr)%mod * C[numl+numr][numl])%mod;
    }
    //rep(i, n) cout << a[i] << " " << num[a[i]] << endl;
    cout << dp[root] << endl;
}

int main()
{
    gen();
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
