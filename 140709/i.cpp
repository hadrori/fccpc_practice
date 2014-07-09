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

const int inf = 1e9;
const int MAX = 20010;
struct edge{int to, cap, rev;};
vector<edge> G[MAX];
int level[MAX], itr[MAX];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, int(G[to].size())});
    G[to].push_back((edge){from, 0, int(G[from].size()-1)});
}

void bfs(int s, int t){
    memset(level, -1, sizeof(level));
    queue<int> que; que.push(s);
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
        while((f = dfs(s, t, inf)) > 0) flow += f;
    }
}

int solve() {
    int n;
    cin >> n;
    vector<int> in(n), out(n);
    vector<vector<int> > E(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        in[a]++; out[b]++;
        E[b].pb(a);
    }

    int s = n, t = n+1;
    rep(i,n+2) G[i].clear();
    int in_cnt = 0, out_cnt = 0;
    rep(i, n) if(in[i] == 0) {
        in_cnt++;
        add_edge(s, i, 1);
    }
    rep(i, n) if(out[i] == 0) {
        out_cnt++;
        add_edge(i, t, 1);
    }

    rep(i, n) {
        rep(j, E[i].size()) {
            add_edge(i, E[i][j], n);
            add_edge(E[i][j], i, n);
        }
    }
    
    
    int mf = max_flow(s, t);
    return in_cnt + out_cnt - mf;
}

int main()
{
    int T;
    cin >> T;
    rep(i, T) {
        cout << "Case " << i+1 << ": ";
        cout << solve() << endl;
    }
    return 0;
}
