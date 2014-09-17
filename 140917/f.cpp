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

struct edge{int to, cap, rev; bool isrev; };
const int MAX = 1024;
const int INF = 100;
vector<edge> G[MAX];
int level[MAX], itr[MAX];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, int(G[to].size()), false});
    G[to].push_back((edge){from, 0, int(G[from].size()-1), true});
}

void bfs(int s, int t){
    memset(level, -1, sizeof(level));
    queue<int> que;
    que.push(s);
    level[s] = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        if(v == t) return;
        for(int i = 0; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap <= 0 or level[e.to] != -1) continue;
            que.push(e.to);
            level[e.to] = level[v]+1;
        }
    }
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    for(int &i = itr[v] ; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(level[e.to] <= level[v] or e.cap <= 0) continue;
        int d = dfs(e.to, t, min(f, e.cap));
        if(d > 0){
            e.cap -= d;
            G[e.to][e.rev].cap += d;
            return d;
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0, f;
    while(1){
        bfs(s, t);
        if(level[t] == -1) return flow;
        memset(itr, 0, sizeof(itr));
        while((f = dfs(s, t, INF)) > 0) flow += f;
    }
}

int N, M, S, T;
bool done[MAX];
vector<edge*> changed;
bool mydfs(int s, int t) {
    if(s == t) return true;
    if(done[s]) return false;
    done[s] = true;
    rep(i, G[s].size()) {
        edge &e = G[s][i];
        if(e.cap <= 0) continue;
        if(mydfs(e.to, t)) {
            e.cap -= 1;
            G[e.to][e.rev].cap += 1;
            changed.pb(&e);
            return true;
        }
    }
    return false;
}

bool check(int a, int b) {
    changed.clear();
    memset(done, 0, sizeof(done));
    bool ret = mydfs(S, T);
    rep(i, changed.size()) {
        changed[i]->cap += 1;
        G[changed[i]->to][changed[i]->rev].cap -= 1;
    }
    return ret;
}

void solve() {
    rep(i, N) G[i].clear();
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        add_edge(a, b, 1);
    }
    int flw = max_flow(S, T);
    int ans = 0;
    rep(i, N) rep(j, G[i].size()) if(!G[i][j].isrev and G[i][j].cap == 1) {
        edge &e = G[i][j];
        e.cap = 0;
        G[e.to][e.rev].cap = 1;
        if(check(i, G[i][j].to)) ans++;
        e.cap = 1;
        G[e.to][e.rev].cap = 0;
    }
    
    if(ans > 0) {
        cout << flw+1 << " " << ans << endl;
    } else {
        cout << flw << " " << 0 << endl;
    }
    
    
}

int main()
{
    while(cin >> N >> M >> S >> T, N or M or S or T) {
        S--; T--;
        solve();
    }
    
    return 0;
}
