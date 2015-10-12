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

ll a, m, done[100010];

bool solve() {
    while(1) {
        if(done[a%m]) return 0;
        done[a%m] = 1;
        if(a%m == 0) return 1;
        a += a%m;
    }
}

int main()
{
    cin >> a >> m;
    puts(solve()? "Yes": "No");
    return 0;
}
