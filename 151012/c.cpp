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

ll solve(ll a, ll b)
{
    ll c = a^b, d = 1LL<<(63-__builtin_clzll(c));
    return a | (d-1);
}

int main()
{
    int t;
    for (cin >> t; t--; ) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b+1) << endl;
    }
    return 0;
}
