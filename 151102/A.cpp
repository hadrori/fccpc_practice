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

int n, m, w[10010], sum[10010];

void solve() {
    rep(i,n+1) sum[i+1] = sum[i]+w[i];
    int ans = 0, v = 1e9;
    rep(i,n+1) {
        int k = m*i, x = k-sum[i]+sum[n+1]-sum[i];
        if(x < v) {
            ans = i;
            v = x;
        }
    }
    cout << ans << ' ' << ans+1 << endl;
}

void input() {
    cin >> n >> m;
    rep(i,m) {
        char c;
        rep(j,n) {
            cin >> c;
            if(c == 'W') w[j]++;
        }
    }
}

int main()
{
    input();
    solve();
    return 0;
}
