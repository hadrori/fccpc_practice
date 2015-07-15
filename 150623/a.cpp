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

int main()
{
    int n;
    cin >> n;
    const int MAX = 128;
    vector<int> a(MAX), b(MAX);
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        if(i != 0) {
            b[l]++;
            b[r]--;
        } else {
            a[l]++;
            a[r]--;
        }
    }
    rep(i, MAX-1) a[i+1] += a[i];
    rep(i, MAX-1) b[i+1] += b[i];
    int ans = 0;
    rep(i, MAX) if(a[i] and !b[i]) ans++;
    cout << ans << endl;
    
    return 0;
}
