#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int n, m;
ll F[32], C[32];
void input() {
    cin >> n;
    rep(i, n) cin >> F[i] >> C[i];
}

int main()
{
    input();
    cin >> m;
    rep(i, m) {
        cout << "Case " << i+1 << ": ";
        ll V, T;
        cin >> V >> T;
        const ll INF = 1000000000000000LL;
        ll ans = INF;
        rep(S, 1<<n) {
            ll sumCost = 0, sumV = 0;
            rep(j, n) if((S>>j)&1) {
                sumCost += C[j];
                sumV += F[j] * T;
            }
            if(sumV >= V)
                ans = min(sumCost, ans);
        }
        if(ans < INF) cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
