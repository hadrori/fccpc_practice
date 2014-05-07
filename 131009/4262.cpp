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

struct edge
{
    int src, dst;
    edge(int src, int dst) : src(src), dst(dst) {};
};

void visit(const vector<vector<edge> > &g, int v, vector<vector<int> > &scc,
	   stack<int> &S, vector<bool> &inS, vector<int> &low, vector<int> &num, int &time)
{
    low[v] = num[v] = ++time;
    S.push(v); inS[v] = true;
    for (__typeof(g[v].begin()) i = g[v].begin(); i != g[v].end(); ++i) {
	int w = i->dst;
	if (num[w] == 0) {
	    visit(g, w, scc, S, inS, low, num, time);
	    low[v] = min(low[v], low[w]);
	} else if (inS[w])
	    low[v] = min(low[v], low[w]);
    }
    if (low[v] == num[v]) {
	scc.pb(vector<int>());
	while (true) {
	    int w = S.top(); S.pop(); inS[w] = false;
	    scc.back().pb(w);
	    if (v == w)
		break;
	}
    }
}

void stronglyConnectedComponents(const vector<vector<edge> > &g, vector<vector<int> > &scc)
{
    const int n = g.size();
    vector<int> num(n), low(n);
    stack<int> S;
    vector<bool> inS(n);
    int time = 0;
    for (int u = 0; u < n; ++u)
	if (num[u] == 0)
	    visit(g, u, scc, S, inS, low, num, time);
}

int N, M;
vector<vector<edge> > G;

void input()
{
    cin >> N >> M;
    G.assign(N, vector<edge>());
    rep(i, M) {
	int s, t;
	cin >> s >> t;
	--s, --t;
	G[s].pb(edge(s, t));
    }
    int tmp;
    cin >> tmp;
}

void solve()
{
    input();

    vector<vector<int> > scc;
    stronglyConnectedComponents(G, scc);
    cout << scc.size() << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T --> 0)
	solve();

    return 0;
}
