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

const int N = 300010;
const int M = 1000010;

int n, a[N], s[N], ord[M], two[N][2];
vector<int> appear[N];
int sum[N];

int main()
{
    cin >> n;
    rep(i, n) cin >> a[i];
    copy(a, a+n, s);
    sort(s, s+n);
    memset(ord, -1, sizeof(ord));
    int t = 0;
    rep(i, n) {
        if (i >= 1 and s[i-1] < s[i]) ++t;
        ord[s[i]] = t;
    }
    ++t;
    int ans = 1;
    rep(i, n) {
        const int k = ord[a[i]];
        if (k >= 1) {
            two[k-1][1] = max(two[k-1][1], two[k-1][0]) + 1;
            ans = max(ans, two[k-1][1]);
        }
        ans = max(ans, ++two[k][0]);
        appear[ord[a[i]]].push_back(i);
    }
    rep(i, t) sum[i+1] = sum[i] + appear[i].size();
    for (int a = 0, b = 0; ; ) {
        int tmp = sum[b+1] - sum[a];
        if (a >= 1) tmp += lower_bound(all(appear[a-1]), appear[a][0]) - begin(appear[a-1]);
        if (b < t-1) tmp += end(appear[b+1]) - upper_bound(all(appear[b+1]), appear[b].back());
        ans = max(ans, tmp);
        ++b;
        if (b >= t) break;
        if (appear[b][0] <= appear[b-1].back()) a = b;
    }
    cout << n - ans << endl;
    
    return 0;
}
