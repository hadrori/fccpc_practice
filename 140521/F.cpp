#include <algorithm>
#include <bitset>
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

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAX = 22;
int n, m;
int to[MAX];
void solve() {
    queue<pair<pair<int, int> , pair<int, int> > > q;
    q.push(mp(mp((1<<n)-1,-1), mp(0,-1)));
    vector<int> memo(1<<n), from(1<<n), htv(1<<n);
    rep(i, 1<<n) {
        memo[i] = 100000000;
        from[i] = -1;
        htv[i] = -1;
    }
    while(q.size()) {
        int S = q.front().first.first;
        int frm = q.front().first.second;
        int cnt = q.front().second.first;
        int hit = q.front().second.second;
        q.pop();
        if(memo[S] <= cnt) continue;
        memo[S] = cnt;
        from[S] = frm;
        htv[S] = hit;
        
        rep(i, n) {
            int nS = 0;
            rep(j, n) if(i != j && ((S>>j)&1) == 1)
                nS |= to[j];
            q.push(mp(mp(nS, S), mp(cnt+1, i)));
        }
    }
    
    if(htv[0] != -1) {
        int now = 0;
        vector<int> ans;
        while(htv[now] != -1) {
            ans.pb(htv[now]);
            now = from[now];
        }
        reverse(all(ans));
        cout << memo[0] << ":";
        rep(i, ans.size()) cout << " " << ans[i];
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }
    
}

int main()
{
    while(cin >> n >> m, n||m) {
        memset(to, 0, sizeof(to));
        rep(i, m) {
            int a, b;
            cin >> a >> b;
            to[a] |= 1<<b;
            to[b] |= 1<<a;
        }
        solve();
    }
    
    return 0;
}
