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
typedef pair<int,int> pii;

const int MAX_V = 1024;

int D, N, E, A, B;

struct edge { int to, cap, rev; };
vector<edge> G[MAX_V];
vector<pii> E2[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int from, int to, int cap) {
    G[from].pb((edge){to, cap, G[to].size()});
    G[to].pb((edge){from, 0, G[from].size()-1});
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        rep(i, G[v].size()) {
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if(v == t) return f;
    for(int &i = iter[v]; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while(true) {
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0) flow += f;
    }
}

int dist[MAX_V];

double solve(){
    int m = max_flow(A, B);
    priority_queue<pii> que;
    que.push(pii(1e9,A));
    while(!que.empty()){
        int d = que.top().first;
        int pos = que.top().second;
        que.pop();
        if(dist[pos] >= 0) continue;
        dist[pos] = d;
        for(int i = 0; i < E2[pos].size(); i++)
            que.push(pii(min(d,E2[pos][i].second), E2[pos][i].first));
    }
    return 1.*m / dist[B];
}

void init(){
    memset(dist, -1, sizeof(dist));
    for(int i = 0; i < MAX_V; i++){
        G[i].clear();
        E2[i].clear();
    }
}

void input(){
    cin >> D >> N >> E >> A >> B;
    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a,b,c);
        E2[a].push_back(pii(b,c));
    }
}

int main()
{
    int P; cin >> P;
    while(P--){
        init();
        input();
        printf("%d %.3f\n", D, solve());
    }
    return 0;
}
