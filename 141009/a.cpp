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
int n;
const int MAX = 5005;
int a[MAX];
void input()
{
    cin >> n;
    rep(i, n) cin >> a[i];
}

int dat[MAX];
void add(int k, int x) {
    while(k < MAX) {
        dat[k] += x;
        k += k&-k;
    }
}

int query(int k) {
    int ret = 0;
    while(k) {
        ret += dat[k];
        k -= k&-k;
    }
    return ret;
}

void solve()
{
    memset(dat, 0, sizeof(dat));
    int ans = 0;
    rep(i, n) {
        ans += query(a[i]);
        add(a[i], 1);
    }
    cout << ans << endl;
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
