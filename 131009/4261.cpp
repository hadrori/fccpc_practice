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

struct node
{
    ll p; int stops, prev, v;
    node(ll p = (ll) INF, int stops = (int) INF, int prev = -1, int v = 0)
	: p(p), stops(stops), prev(prev), v(v) {}
    bool operator <(const node &t) const {
	return p > t.p || p == t.p &&
	    (stops > t.stops || stops == t.stops && prev > t.prev);
    }
};

int n, a[1024], b[1024] = {0};

void input()
{
    fill(b, b + 1024, 0);
    rep(i, n)
	cin >> a[i];
    rep(i, n)
	b[i + 1] = b[i] + a[i];
}

inline ll sq(ll n) { return n * n; }

void solve()
{
    node mem[1024];
    priority_queue<node> q;
    q.push(node(0, 0, -1, n));
    while (!q.empty()) {
	node cur = q.top();
	q.pop();
	if (!(mem[cur.v] < cur))
	    continue;
	mem[cur.v] = cur;
	if (cur.v == 0) {
	    cout << "p=" << cur.p << endl;
	    vector<int> route;
	    int tmp = cur.v;
	    while (tmp >= 0) {
		route.pb(tmp);
		tmp = mem[tmp].prev;
	    }
	    rep(i, route.size())
		cout << " " << route[i] << (i % 30 == 29 ? "\n" : "");
	    if (route.size() % 30 != 0)
		cout << endl;
	    return;
	}
	for (int i = 0; i <= n; ++i) {
	    if (i == cur.v)
		continue;
	    ll np = cur.p + sq(abs(b[i] - b[cur.v]) - 100);
	    int ns = cur.stops + 1;
	    q.push(node(np, ns, cur.v, i));
	}
    }
}

int main()
{
    cin >> n;
    while (true) {
	input();
	solve();

	if (!(cin >> n && n))
	    break;
	cout << endl;
    }

    return 0;
}
