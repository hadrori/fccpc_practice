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
    int nv, d;
    edge(int nv, int d) : nv(nv), d(d) {}
};

int s, p;
vector<vector<edge> > G;

void input()
{
    G.assign(26, vector<edge>());

    cin >> s >> p;
    rep(i, p) {
	char a, b; int d;
	cin >> a >> b >> d;
	G[a - 'A'].pb(edge(b - 'A', d));
	G[b - 'A'].pb(edge(a - 'A', d));
    }
}

struct node
{
    int d, len, prev, v;
    node(int d, int len, int prev, int v) : d(d), len(len), prev(prev), v(v) {}
    bool operator <(const node &t) const {
	return d > t.d || d == t.d && len > t.len;
    }
};

void solve1(int a, int b)
{
    vector<node> mem(26, node((int) INF, (int) INF, -1, -1));
    vector<int> prev(26, -1);
    priority_queue<node> q;
    q.push(node(0, 1, -1, a));
    while (!q.empty()) {
	node cur = q.top(); q.pop();
	if (!(mem[cur.v] < cur))
	    continue;
	mem[cur.v] = cur;
	if (cur.v == b) {
	    vector<char> ans;
	    int tmp = cur.v;
	    do {
		ans.pb('A' + tmp);
		tmp = mem[tmp].prev;
	    } while (tmp >= 0);
	    for (int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << (i ? ' ' : '\n');
	    return;
	}
	rep(i, G[cur.v].size()) {
	    int nd = cur.d + G[cur.v][i].d;
	    int nlen = cur.len + 1;
	    int nv = G[cur.v][i].nv;
	    q.push(node(nd, nlen, cur.v, nv));
	}
    }
}

void solve()
{
    int n;
    cin >> n;
    rep(i, n) {
	char a, b;
	cin >> a >> b;
	solve1(a - 'A', b - 'A');
    }
}

int main()
{
    input();
    solve();

    return 0;
}
