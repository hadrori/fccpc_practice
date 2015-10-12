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

const int N = 200010;

string s;
int n, r[N];

int main()
{
    cin >> s;
    n = s.length();
    for (int i = n-1, t = n; i >= 0; --i) {
        r[i] = t;
        if (s[i] == '1') t = i;
    }
    int shift = n-1;
    rep(i, n) {
        int a = i, b = (n - r[i]);
        if (a > b) swap(a, b);
        shift = min(shift, 2*a + b);
    }
    int ans = shift * 7 + count(all(s),'1') * 4;
    cout << ans << endl;
    return 0;
}
