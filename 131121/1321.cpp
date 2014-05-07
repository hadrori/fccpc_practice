#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>

#define repi(i,a,b) for(int i = int(a); i < int(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = int(a); i >= int(b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);

using namespace std;

typedef long long ll;

/**/
struct edge
{
    int to, cap, rev;
    edge(int to, int cap, int rev)
        : to(to), cap(cap), rev(rev) {}
};

vector<vector<edge> > G;

void add_edge(int from, int to, int cap)
{
    G[from].pb(edge(to, cap, (int) G[to].size()));
    G[to].pb(edge(from, 0, (int) G[from].size() - 1));
}

const int inf = 1e9;

int V;
vector<int> level, iter;

void init(int s)
{
    level.assign(V, inf);
    level[s] = 0;
    queue<int> Q; Q.push(s);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        rep(i, (int) G[v].size()) {
            edge &e = G[v][i];
            if (e.cap && level[e.to] > level[v] + 1)
                level[e.to] = level[v] + 1, Q.push(e.to);
        }
    }

    iter.assign(V, 0);
}

int augment(int v, int t, int f = inf)
{
    if (v == t) return f;

    for (; iter[v] < (int) G[v].size(); ++iter[v]) {
        edge &e = G[v][iter[v]];
        if (!e.cap || level[v] >= level[e.to])
            continue;
        int aug = augment(e.to, t, min(f, e.cap));
        if (aug) {
            e.cap -= aug, G[e.to][e.rev].cap += aug;
            return aug;
        }
    }

    return 0;
}

int block_flow(int s, int t)
{
    init(s);

    int ret = 0, aug;
    while (aug = augment(s, t), aug)
        ret += aug;
    return ret;
}

int max_flow(int s, int t)
{
    int ret = 0, aug;
    while (aug = block_flow(s, t), aug)
        ret += aug;
    return ret;
}
/*/

// verified poj1459
int V;

const int INF = 1000000000;
const int MAX_V = 100000;

struct edge { int to, cap, rev; };
vector<vector<edge> > G;
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
/**/
int h, w;
char f[16][16];
signed main(){
    while(cin >> h >> w, h||w) {
        rep(i, h) rep(j, w) cin >> f[i][j];
        int di[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int dj[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

        vector<int> cnt(w*h);
        rep(i, h) rep(j, w) {
            rep(k, 9) {
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni >= 0 && nj >= 0 && ni < h && nj < w && f[ni][nj] != '.') {
                    cnt[i*w+j]++;
                }
            }
        }
        
        int BASE = h*w;
        int s = 2*BASE+1, t = s+1;
        V = t+1;
        G.assign(V, vector<edge>());
        vector<bool> done(h*w);
        rep(i, h) rep(j, w) if(f[i][j] >='0' && f[i][j] <= '9') {
            int num = f[i][j] - '0';
            add_edge(s, BASE+i*w+j, cnt[i*w+j]-num);
            rep(k, 9) {
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni >= 0 && nj >= 0 && ni < h && nj < w && f[ni][nj] != '.') {
                    add_edge(BASE+i*w + j, ni*w+nj, 1);
                    done[ni*w+nj] = true;
                }
            }
        }
        
        int ans = 0;
        rep(i, h) rep(j, w) if(f[i][j] != '.' && done[i*w+j]) {
            ans++;
            add_edge(i*w+j, t, 1);
        }
                
/*        rep(i,h*w) if(!done[i] && f[i/w][i%w] != '.') {
            add_edge(s, i, 1);
            cout << i/w << " " << i%w << endl;
            }*/

        cout << ans - max_flow(s,t) << endl;
    }
    return 0;
}
