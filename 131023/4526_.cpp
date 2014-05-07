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

typedef pair<int,int> pii;
const int MAX_V = 100000;

struct edge{int to, cap, cost, rev;};

int V;
vector<edge> G[MAX_V];
int h[MAX_V], dist[MAX_V], prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost){
    G[from].pb((edge){to,cap,cost,G[to].size()});
    G[to].pb((edge){from,0,-cost,G[from].size()-1});
}

int min_cost_flow(int s, int t, int f){
    int res = 0;
    fill(h,h + V, 0);
    while(f > 0){
	priority_queue<pii, vector<pii>, greater<pii> > que;
	fill(dist, dist + V, INF);
	dist[s] = 0;
	que.push(pii(0,s));
	while(!que.empty()){
	    pii p = que.top(); que.pop();
	    int v = p.second;
	    if(dist[v] < p.first) continue;
	    rep(i,G[v].size()){
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
	rep(v, V) h[v] += dist[v];
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
    }
    return res;
}

int main()
{
    return 0;
}
