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
typedef pair<int,int> pii;

int n;

void solve()
{
    vector<pii> vs;
    vs.pb(mp(0,0));
    if(n == 3) {
        vs.pb(mp(1,0));
        vs.pb(mp(1,1));
    }
    else if(n == 5) {
        vs.pb(mp(2,0));
        vs.pb(mp(2,2));
        vs.pb(mp(1,2));
        vs.pb(mp(0,1));
    }
    else {
        int x = n-2-n%2, y = x;
        vs.pb(mp(x,0));
        while(x or y) {
            vs.pb(mp(x,y));
            if(x == y) x -= 2;
            else y -= 2;
        }
        if(n%2) {
            vs.pop_back();
            vs.pop_back();
            vs.pb(mp(2,3));
            vs.pb(mp(1,2));
            vs.pb(mp(0,2));
        }
    }
    int ans = n/2+2;
    if(n == 3) ans = 1;
    else if(n == 5) ans = 3;
    cout << ans << endl;
    for(auto &p: vs) cout << p.first << ' ' << p.second << endl;
}

int main()
{
    int t; cin >> t;
    while(t--) {
        cin >> n;
        solve();
    }
    return 0;
}
