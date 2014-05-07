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
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const ll INF = 1000000000000LL;
int n, m, K, s, g;
ll sd[30005], gd[30005];
ll x[30005];
ll f[30005];
ll fee(ll dst) {
    int idx = upper_bound(x, x+K+1, dst) - x;
    if(idx == 0) return 0;
    return f[idx-1];
}

int main()
{
    cin >> n >> m >> K;
    cin >> s >> g;
    memset(sd, -1, sizeof(sd));
    memset(gd, -1, sizeof(gd));
    vector<vector<pair<int, ll> > > v(n);
    rep(i, m) {
        int a, b;
        ll dst;
        cin >> a >> b >> dst;
        v[a].pb(mp(b, dst));
        v[b].pb(mp(a, dst));
    }

    priority_queue<pair<pair<ll, int>, int> > pq;
    pq.push(mp(mp(0, s), 0));
    pq.push(mp(mp(0, g), 1));
    while(pq.size()) {
        int dst = -pq.top().first.first;
        int now = pq.top().first.second;
        int sg = pq.top().second;
        pq.pop();
        if(sg == 0) {
            if(sd[now] != -1) continue;
            sd[now] = dst;
        } else {
            if(gd[now] != -1) continue;
            gd[now] = dst;
        }
        rep(i, v[now].size()) {
            pq.push(mp(mp(-(dst + v[now][i].second), v[now][i].first), sg));
        }
    }
    
    rep(i, K) cin >> x[i] >> f[i];
    x[K] = f[K] = INF;
    ll ans = INF;
    rep(i, n) {
        if(sd[i] != -1 && gd[i] != -1) ans = min(ans, fee(sd[i]) + fee(gd[i]));
    }
    cout << ans << endl;
    return 0;
}
