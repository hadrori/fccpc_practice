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

const int MAX = 256;

struct edge{ int to, cap, rev;};

vector<edge> G[MAX];
int level[MAX], itr[MAX];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, int(G[to].size())});
    G[to].push_back((edge){from, 0, int(G[from].size()-1)});
}

void bfs(int s){
    queue<int> que;
    memset(level, -1, sizeof(level));
    que.push(s);
    level[s] = 0;
    while(que.size()){
        int v = que.front();
        que.pop();
        rep(i,G[v].size()){
            edge &e = G[v][i];
            if(e.cap > 0 and level[e.to] < 0){
                que.push(e.to);
                level[e.to] = level[v] + 1;
            }
        }
    }
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    for(int &i = itr[v]; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap > 0 and level[e.to] > level[v]){
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

int max_flow(int s, int t){
    int flow = 0, f;
    while(1){
        bfs(s);
        if(level[t]<0) return flow;
        memset(itr, 0, sizeof(itr));
        while((f=dfs(s,t,INF)) > 0) flow += f;
    }
}

int n;
int a[MAX];
char f[MAX][MAX];
bool enemy[MAX], adj[MAX];

bool C(int k) {
    int s = n*2, t = s+1;
    int sum = 0;
    rep(i, t+1) G[i].clear();
    rep(i, n) if(!enemy[i]) {
        add_edge(s, i, a[i]);
        if(adj[i]) {
            sum += k;
            add_edge(i+n, t, k);
        } else {
            sum += 1;
            add_edge(i+n, t, 1);
        }
    }
    
    rep(i, n) rep(j, n) if(!enemy[i] && !enemy[j] && f[i][j] == 'Y') {
        add_edge(i, j+n, 100000);
    }

    rep(i, n) if(!enemy[i]) add_edge(i, i+n, 100000);
    int flw = max_flow(s, t);

    return flw == sum;
}

int solve() {
    cin >> n;
    memset(enemy, 0, sizeof(enemy));
    rep(i, n) {
        cin >> a[i];
        if(a[i] == 0) enemy[i] = true;
    }
    
    rep(i, n) rep(j, n) cin >> f[i][j];
    memset(adj, 0, sizeof(adj));
    rep(i, n) rep(j, n) 
        if(f[i][j] == 'Y' && enemy[i]) adj[j] = true;

    int lower = 0;
    int upper = 100000;
    int mid;
    while(upper - lower > 1) {
        mid = (lower + upper)/2;
        if(C(mid)) lower = mid;
        else upper = mid;
    }
    return lower;
}

int main()
{
    int t;
    cin >> t;
    rep(i, t) {
        cout << solve() << endl;
    }
    return 0;
}
