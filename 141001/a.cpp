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
#include <numeric>

using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
const int inf = 100000000;
struct edge{ int to, cap, cost, rev;};

const int MAX = 64;
char f[MAX][MAX];
void solve() {
    int n, m;
    cin >> n >> m;
    rep(i, n) rep(j, m) cin >> f[i][j];
    int one_cnt = 0;
    rep(i, n) rep(j, m) if(f[i][j] == '1') one_cnt++;
    const int inf = 100000000;
    int ans = inf;
    vector<pair<int, int> > onen(n), onem(m);
    rep(i, n) onen[i].second = i;
    rep(j, m) onem[j].second = j;
    
    rep(i, n) rep(j, m) onen[i].first++, onem[j].first++;
    //sort(rall(onen)); sort(rall(onem));
    srand(time(0));
    rep(_, 30) {
        random_shuffle(all(onen)); random_shuffle(all(onem));
        rep(sum, n*m+1) if(sum%n == 0 and sum%m == 0) {
            int tmp = one_cnt;
            vector<int> sumn(n, sum/n);
            vector<int> summ(m, sum/m);
            rep(ti, n) rep(tj, m) {
                int i = onen[ti].second, j = onem[tj].second;
                if(f[i][j] == '1' and sumn[i] and summ[j]) {
                    sumn[i]--; summ[j]--;
                    tmp--;
                }
            }
            rep(ti, n) rep(tj, m) {
                int i = onen[ti].second, j = onem[tj].second;
                if(f[i][j] == '0' and sumn[i] and summ[j]) {
                    sumn[i]--; summ[j]--;
                    tmp++;
                }
            }

            if( (accumulate(all(sumn), 0) != 0) or
                (accumulate(all(summ), 0) != 0)) continue;
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}
        

int main()
{
    int T;
    cin >> T;
    rep(i, T) {
        cout << "Case " << i+1 << ": ";
        solve();
    }
    return 0;
}
