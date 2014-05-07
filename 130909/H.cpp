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

int N, M;

struct edge
{
    int v, d, c;
    edge(int v, int d, int c) : v(v), d(d), c(c) {}
    bool operator<(const edge &o) const{
	return c > o.c;
    }
};

vector<vector<edge> > G;

void input()
{
    G.assign(N, vector<edge>());
    rep(i,M) {
	int u, v, d, c;
	cin >> u >> v >> d >> c;
	--u, --v;
	G[u].pb(edge(v, d, c));
	G[v].pb(edge(u, d, c));
    }
}

ll mind[10005];
struct node{
    int now;
    int cst;
    bool operator<(const node &o) const{
	return cst > o.cst;
    }
};
struct node2 {
    int pos;
    int cst;
    bool operator<(const node2 &o) const{
	return cst > o.cst;
    }
};
struct node3 {
    int now;
    int cst;
    int a;
    int b;
};

bool done[10005];
vector<bool> usable[10005];
void solve()
{
    rep(i, N) mind[i] = INF;
    priority_queue<node> pq;
    pq.push((node){0, 0});
    while(!pq.empty()) {
	int now = pq.top().now;
	ll cst = pq.top().cst;
	pq.pop();
	if(mind[now] < INF) continue;
	mind[now] = cst;
	rep(i, G[now].size()) {
	    pq.push((node){G[now][i].v, cst + G[now][i].d});
	}
    }
    //rep(i, N) cout << mind[i] << endl;
    queue<node3> q;
    rep(i, N) {
	usable[i].clear();
	usable[i].resize(G[i].size());
    }
    q.push((node3){0, 0, -1, -1});
    while(!q.empty()) {
	int now = q.front().now;
	ll cst = q.front().cst;
	int a = q.front().a;
	int b = q.front().b;
	q.pop();
	if(mind[now] < cst) continue;
	if(a >= 0) {
	    usable[a][b] = true;	
//	    cout << "b " << a << " " << b << endl;
	}
	rep(i, G[now].size()) {
	    q.push((node3){G[now][i].v, cst+G[now][i].d, now, i});
	}
    }
    priority_queue<edge> pq2;
    memset(done, 0, sizeof(done));
    ll ans = 0;
    done[0] = true;
    /*rep(i, G[0].size()) {
	if(usable[0][i]) {
	    pq2.push((node2){G[0][i].v, G[0][i].c});		
	}
	}*/
    rep(i, N) rep(j, G[i].size()) if(usable[i][j]) pq2.push(G[i][j]);
    while(!pq2.empty()) {
	edge e = pq2.top();
	pq2.pop();
	if(done[e.v]) continue;
	done[e.v] = true;
	ans += e.c;
    }
    //  rep(i, N) if(!done[i]) cout <<"a " << i << endl;
    cout << ans << endl;
}

int main()
{
    while (cin >> N >> M && N) {
	input();
	solve();
	
    }

    return 0;
}
