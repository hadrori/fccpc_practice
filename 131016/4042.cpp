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

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define printv(v) repit(i,v){ cout << *i << endl;}

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

const int MAX_V = 32;

struct edge{int to, cap, rev;};

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap)
{
    G[from].pb((edge){to, cap, G[to].size()});
    G[to].pb((edge){from, 0, G[from].size()-1});
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    used[v] = true;
    rep(i,G[v].size()){
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

int max_flow(int s, int t)
{
    int flow = 0;
    while(1){
	memset(used, 0, sizeof(used));
	int f = dfs(s, t, INF);
	if(f == 0) return flow;
	flow += f;
    }
}
int n, m, cases;
int f[32][32];
int main()
{
    cin >> cases;
    rep(_, cases) {
	cin >> n >> m;
	rep(i, n) rep(j, n) cin >> f[i][j];

	V = n;
	rep(i, n) rep(j, n) if(i != j) {
	    if(f[i][j] >= 0) add_edge(i, j, f[i][j]);
	    else { 
		//?
	    }
	}
	
	int sum = 0;
	rep(i, n) repi(j, i+1, n) sum += f[i][j];

	int mf = -INF;
	repi(i, 1, n) {
	    mf = max(mf, max_flow(0, i));
	}

	cout << 2*(sum - 2 * mf) << endl;
    }
    return 0;
}


