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
ll n, l, r;

int main()
{
    int t; cin >> t;
    while(t--) {
        cin >> n >> l >> r;
        ll x = (n-1)/r+1;
        if(l*x <= n and n <= x*r) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
