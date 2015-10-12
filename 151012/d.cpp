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
const int K = 50;

int n, a[N], mem[K];

void solve()
{
    int ans = 0;
    set<int> s;
    rep(i, n) {
        if (ans >= a[i] - 1) break;
        if (a[i] < K) {
            ans = max(ans, mem[a[i]]);
        } else {
            for (int t = 0; t < a[0]; ) {
                t += a[i];
                auto it = s.upper_bound(-t);
                if (it != end(s)) {
                    int tmp = a[i] - t - *it;
                    if (tmp < a[i]) ans = max(ans, tmp);
                }
            }
        }
        repi(j, 2, K) {
            mem[j] = max(mem[j], a[i] % j);
        }
        s.insert(-a[i]);
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d", &n);
    rep(i, n) scanf("%d", a + i);
    sort(a, a + n, greater<int>());
    n = unique(a, a + n) - a;
    solve();
    return 0;
}
