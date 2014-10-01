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

int V;
const int MAX_V = 128;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

inline void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, int(G[to].size())});
    G[to].push_back((edge){from, 0, -cost, int(G[from].size() - 1)});
}

int min_cost_flow(int s, int t, int f){
    int res = 0;
    fill(h, h + V, 0);
    while(f > 0){
        priority_queue<pii, vector<pii>, greater<pii> > que;
        fill(dist, dist + V, inf);
        dist[s] = 0;
        que.push(pii(0, s));
        while(!que.empty()){
            pii p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            rep(i,G[v].size()){
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(pii(dist[e.to], e.to));
                }
            }
        }
        if(dist[t] == inf) return -1;
        rep(v,V) h[v] += dist[v];
        int d = f;
        for(int v = t; v != s; v = prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d * h[t];
        for(int v = t; v != s; v = prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

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

    vector<pair<int, int> > sums;
    rep(sum, n*m+1) if(sum%n == 0 and sum%m == 0) sums.pb(mp(abs(sum-one_cnt), sum));
    sort(all(sums));
    rep(idx, sums.size()) {
        int sum = sums[idx].second;
        if(abs(sum-one_cnt) >= ans) break;
        int tmp;
        int s = n+m+1, t = s+1;
        V = t+1;
        rep(i, V) G[i].clear();
        rep(i, n) rep(j, m) if(f[i][j] == '1') add_edge(i, n+j, 1, 0);
        rep(i, n) rep(j, m) if(f[i][j] == '0') add_edge(i, n+j, 1, 1);
        rep(i, n) add_edge(s, i, sum/n, 0);
        rep(j, m) add_edge(n+j, t, sum/m, 0);
        tmp = one_cnt - sum + min_cost_flow(s, t, sum)*2;
        
        /*
        int tmp = one_cnt;
        vector<int> sumn(n, sum/n);
        vector<int> summ(m, sum/m);
        rep(i, n) rep(j, m) if(f[i][j] == '1' and sumn[i] and summ[j]) {
            sumn[i]--; summ[j]--;
            tmp--;
        }
        int tt = tmp;
        rep(i, n) rep(j, m) if(f[i][j] == '0' and sumn[i] and summ[j]) {
            sumn[i]--; summ[j]--;
            tmp++;
        }
        */
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
        

int main()
{
    int T;
    cin >> T;
    rep(i, T) {
        cout << "Case " << i+1 << ": ";
        //if(i%1000 == 0) cerr << i << endl;
        solve();
    }
    return 0;
}
