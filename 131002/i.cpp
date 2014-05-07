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

#define repi(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) repi(i, 0, a)
#define repd(i, a, b) for(int i = (a); i >= (b); i--)
#define repit(i, a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

#define all(u) (u).begin(), (u).end()
#define rall(u) (u).rbegin(), (u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)), (u).end())

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
    int y, d;
    edge(int y, int d) : y(y), d(d) {}
};

int n, m, k, a, b;
vector<edge> G[64];

struct node
{
    int dist, v;
    ll ved;
    string hist;
    node(int dist, int v, ll ved, string hist)
	: dist(dist), v(v), ved(ved), hist(hist) {}
    bool operator <(const node &t) const {
	return dist > t.dist || dist == t.dist && hist > t.hist;
    }
};

const int offset = 32;

void dump(string s)
{
    repit(it, s) {
	if (it != s.begin())
	    cout << '-';
	cout << (int) *it - offset;
    }
    cout << endl;
}

vector<node> ks[64];

int main(){
    while (cin >> n >> m >> k >> a >> b && n) {
	rep(i, 64) {
	    G[i].clear();
	    ks[i].clear();
	}
	rep(i, m) {
	    int x, y, d; cin >> x >> y >> d;
	    G[x].pb(edge(y, d));
	}

	priority_queue<node> q;
	q.push(node(0, a, 1LL << a, string(1, (char) (a + offset))));
	while (!q.empty()) {
	    node cur = q.top(); q.pop();
	    if (ks[cur.v].size() >= k && ks[cur.v].back().dist < cur.dist)
		continue;
	    ks[cur.v].pb(cur);
	    repit(it, G[cur.v]) {
		if (!(cur.ved >> it->y & 1)) {
		    string nhist(cur.hist);
		    nhist.pb((char) (it->y + offset));
		    q.push(node(cur.dist + it->d, it->y, cur.ved | 1LL << it->y, nhist));
		}
	    }
	}

	sort(rall(ks[b]));
	if (ks[b].size() >= k)
	    dump(ks[b][k - 1].hist);
	else
	    cout << "None" << endl;
    }

    return 0;
}

