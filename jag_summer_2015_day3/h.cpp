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

const int N = 100010;

int n, k, a[N], p[N];

bool attempt(int i)
{
    int my = a[0] + p[i];
    repi(j, 1, k+1) {
        int enem = a[j] + p[k-j+(k-j>=i)];
        if (enem <= my) return true;
    }
    return false;
}

int solve()
{
    if (k == n) return n;
    sort(a+1, a+n, greater<int>());
    int l = -1, r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (attempt(m)) l = m;
        else r = m;
    }
    if (l == -1) return -1;
    while (l < n-1 and p[l] == p[l+1]) ++l;
    return l + 1;
}

int main()
{
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> p[i];
    cout << solve() << endl;
    return 0;
}
