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
#define repd(i,a,b) for(int i = (a) ; i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i!= (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end)

#define pb push_back
#define mp makek_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int n, x[1024], y[1024];
double vw, vc;

const int N = 4000;

double mem[N];

struct edge
{
    int v; double c;
    edge(int v, double c) : v(v), c(c) {}
};

struct node
{
    int v; double c;
    node(int v, double c) : v(v), c(c) {}
    bool operator <(const node& t) const {
	return c > t.c;
    }
};

vector<vector<edge> > E;

int main(){
    while (cin >> n && n) {
	cin >> vw >> vc;
	vw = 1.0 / vw;
	vc = 1.0 / vc;
	rep(i, n)
	    cin >> x[i] >> y[i];

	E.assign(n, vector<edge>());
	rep(i, n - 1)
	    E[i].pb(edge(i + 1, vw * hypot((double) (x[i + 1] - x[i]),
					   (double) (y[i + 1] - y[i]))));

	stack<int> stk;
	rep(i, n - 1) {
	    if (y[i] < y[i + 1])
		stk.push(i);
	    else if (y[i] == y[i + 1]) {
		//
	    } else {
		while (!stk.empty() && y[stk.top()] >= y[i + 1]) {
		    int it = stk.top();
		    stk.pop();
		    if (y[it] == y[i + 1]) {
			E[it].pb(edge(i + 1, vc * (x[i + 1] - x[it])));
			continue;
		    }
		    double p = (double) (y[it] - y[i]) / (y[i + 1] - y[i]);
		    double cx = p * x[i + 1] + (1 - p) * x[i];
		    double cy = p * y[i + 1] + (1 - p) * y[i];

		    int nv = E.size();
		    E.pb(vector<edge>());
		    E[it].pb(edge(nv, vc * (cx - x[it])));
		    E[i].pb(edge(nv, vw * hypot((double) (cx - x[i]),
						(double) (cy - y[i]))));
		    E[nv].pb(edge(i + 1, vw * hypot((double) (cx - x[i + 1]),
						    (double) (cy - y[i + 1]))));
		}
	    }
	}

	stk = stack<int>();
	for (int i = n - 2; i >= 0; --i) {
	    if (y[i] > y[i + 1])
		stk.push(i + 1);
	    else if (y[i] == y[i + 1]) {
		//
	    } else {
		while (!stk.empty() && y[stk.top()] >= y[i]) {
		    int it = stk.top();
		    stk.pop();
		    if (y[it] == y[i]) {
			E[i].pb(edge(it, vc * (x[it] - x[i])));
			continue;
		    }
		    double p = (double) (y[it] - y[i]) / (y[i + 1] - y[i]);
		    double cx = p * x[i + 1] + (1 - p) * x[i];
		    double cy = p * y[i + 1] + (1 - p) * y[i];

		    int nv = E.size();
		    E.pb(vector<edge>());
		    E[nv].pb(edge(it, vc * (x[it] - cx)));
		    E[i].pb(edge(nv, vw * hypot((double) (cx - x[i]),
						(double) (cy - y[i]))));
		    E[nv].pb(edge(i + 1, vw * hypot((double) (cx - x[i + 1]),
						    (double) (cy - y[i + 1]))));
		}
	    }
	}

	fill(mem, mem + N, INF);

	priority_queue<node> q;
	q.push(node(0, 0.0));
	while (!q.empty()) {
	    node tmp = q.top();
	    int v = tmp.v;
	    double c = tmp.c;
	    q.pop();

	    if (v == n - 1) {
		printf("%.6f\n", c);
		break;
	    }
	    if (mem[v] <= c)
		continue;
	    mem[v] = c;

	    rep(i, E[v].size())
		q.push(node(E[v][i].v, c + E[v][i].c));
	}
    }

    return 0;
}
