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

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)
#define MAX 2000
using namespace std;

typedef long long ll;
typedef vector<int> vi;
struct edge{ int to, cap, rev; };
vector<edge> G[MAX];
bool used[MAX];

void add_edge(int from, int to, int cap){
    G[from].pb((edge){to, cap, G[to].size()});
    G[to].pb((edge){from, 0, G[from].size() - 1});
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    used[v] = true;
    rep(i, G[v].size()){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
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
    int flow = 0;
    while(1){
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0) return flow;
        flow += f;
    }
}
int N, K;
int main() {
    while(cin >> N >> K, N||K){
        vector<int> b(N), r(K);
        rep(i, N) cin >> b[i];
        rep(i, K) cin >> r[i];
        rep(i, MAX) G[i].clear();
        int s = N+K, t = s+1;
        rep(i, N) add_edge(s, i, 1);
        rep(i, K) add_edge(N+i, t, 1);
        rep(i, N) rep(j, K) if(__gcd(b[i], r[j]) > 1) add_edge(i, N+j, 1);
        cout << max_flow(s, t) << endl;
    }
    return 0;
}
