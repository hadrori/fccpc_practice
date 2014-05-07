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

struct edge{
    int to, cap, rev;
    edge(){}
    edge(int to, int cap, int rev):to(to),cap(cap),rev(rev){}
};
vector<edge> G[128];
int level[128], iter[128];
int N, M, P, g;
void add_edge(int from, int to, int cap){
    G[from].pb(edge(to, cap, int(G[to].size())));
    G[to].pb(edge(from, 0, int(G[from].size()-1)));
}

void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> que;
    que.push(s);
    level[s] = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        rep(i, G[v].size()){
            edge &e = G[v][i];
            if(e.cap > 0 and level[e.to] < 0){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    for(int &i = iter[v]; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(level[e.to] > level[v] and e.cap > 0){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int dinic(int s, int t){
    int flow = 0, f;
    while(1){
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        while((f = dfs(s, t, INF)) > 0) flow += f;
    }
}

int main()
{
    cin >> N >> M >> P >> g;
    int s = M, t = 0;
    rep(i,g){
        int l; cin >> l;
        add_edge(s, l, INF);
    }
    rep(i,N){
        int fr, to, ca; cin >> fr >> to >> ca;
        add_edge(fr, to, ca);
    }
    if(dinic(s, t) >= P) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
