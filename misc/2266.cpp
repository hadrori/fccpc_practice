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
#define lb lower_bound
#define ub upper_bound
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;

struct edge { int to, cap, cost, rev;};

const int MAX_V = 1000000;
const int MAX_N = 1000000;
int V;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];
int N, K;
int a[MAX_N], b[MAX_N], w[MAX_N];
vi wb, ab;


void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f, bool negative){
    int res = 0;
    fill(h, h + V, 0);

    if(negative){
	vector<int> dist2(N, INF);
	dist2[s] = 0;
     
	bool update = true;
     
	while(update){
	    update = false;
	    for(int v = 0; v < N; v++){
		if(dist[v] == INF) continue;
		for(int i = 0; i < (int)G[v].size(); i++){
		    edge &e = G[v][i];
		    if(e.cap > 0 && dist2[e.to] > dist2[v] + e.cost){
			dist2[e.to] = dist2[v] + e.cost;
			prevv[e.to] = v;
			preve[e.to] = i;
			update = true;
		    }
		}
	    }
	}
 
	for(int i = 0; i < N; i++)
	    h[i] = dist2[i];
    }

    while(f > 0){
        priority_queue<pii, vector<pii>, greater<pii> > que;
        fill(dist, dist + V, INF);
        dist[s] = 0;
        que.push(pii(0, s));
        while(!que.empty()){
            pii p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(int i = 0; i < G[v].size(); i++){
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(pii(dist[e.to], e.to));
                }
            }
        }
        if(dist[t] == INF) return -1;
        for(int v = 0; v < V; v++) h[v] += dist[v];
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
	//cerr << f << endl;
    }
    return res;
}

void solve(){
    vi x;
    rep(i, N){
	x.pb(a[i]);
	x.pb(b[i]);
    }
    sort(all(x));
    UNIQUE(x);
    N = x.size();
    int m = x.size();
    int s = m, t = s + 1;
    V = t + 1;
    int res = 0;
    add_edge(s, 0, INF, 0);
    add_edge(max(0, m - 1), t, INF, 0);

    rep(i,N){
	int u = find(all(x), a[i]) - x.begin();
	int v = find(all(x), b[i]) - x.begin();
/*
	add_edge(v, u, 1, w[i]);
	add_edge(s, v, 1, 0);
	add_edge(u, t, 1, 0);
*/
	//res -= w[i];

//a	add_edge(v, u, 1, -w[i]);
    }
    for(int i = 0; i + 1 < m; i++){
	add_edge(i, i + 1, INF, 0);
    }
    cerr << res << endl;
    res += min_cost_flow(s, t, K + N, 1);
    cerr << res << endl;
    rep(i,ab.size()) res += wb[ab[i]];
    cout << res << endl;
}

int tmp[MAX_N];

void input(){
    int m, n, k;
    cin >> m >> n >> k;
    rep(i,n){
	int t;
	cin >> t;
	wb.pb(t);
    }
    rep(i,k){
	int t;
	cin >> t;
	t--;
	ab.pb(t);
    }
    memset(tmp, -1, sizeof(tmp));
    int cnt = 0;
    rep(i,k){
	if(tmp[ab[i]] != -1){
	    a[cnt] = tmp[ab[i]] + 1;
	    b[cnt] = i;
	    w[cnt] = wb[ab[i]];
	    cnt++;
	}
	tmp[ab[i]] = i;
    }
    N = cnt;
    K = m - 1;
/*
    rep(i,cnt){
	cout << a[i] << ' ' << b[i] << ' ' << w[i] << endl;
    }
*/
}

int main() {
    input();
    solve();
    return 0;
}
