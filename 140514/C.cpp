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

const int MAX = 1010;
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
        while((f = dfs(s, t, INF)) > 0) flow += f;
    }
}


int solve() {
    int c, d, v;
    cin >> c >> d >> v;
    vector<int> cat(v), dog(v);
    vector<bool> cat_lover(v);

    int s = v+1, t = s+1;
    rep(i, t+1) G[i].clear();
    
    rep(i, v) {
        char tmp1, tmp2;
        cin >> tmp1 >> cat[i] >> tmp2 >> dog[i];
        if(tmp1 == 'C') cat_lover[i] = true;
        else {
            cat_lover[i] = false;
            swap(cat[i], dog[i]);
        }
    }

    rep(i, v) if(cat_lover[i]) add_edge(s, i, 1);
    else add_edge(i, t, 1);
        
    rep(i, v) repi(j, i+1, v) {
        if(cat[i] == cat[j] || dog[i] == dog[j]) {
            if(cat_lover[i] != cat_lover[j]) {
                if(cat_lover[i]) add_edge(i, j, 1);
                else add_edge(j, i, 1);
            }
        }
    }

    int flow = max_flow(s, t);
    return v - flow;
}


int main() {
    int t;
    cin >> t;
    rep(i, t) {
        cout << solve() << endl;
    } 
}
