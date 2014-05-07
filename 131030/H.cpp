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

#define repi(i,a,b) for(int i=(a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a); i>=(b); i--)
#define repit(i,a) for(typeof((a).begin()) i=(a).begin(); i != (a).end(); i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)), (u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int M = 250010;

int N, T, G[M], S[M];

void input()
{
    scanf("%d%d", &N, &T);
    rep(i, N)
	scanf("%d%d", G + i, S + i);
}

int BIT[M];

inline void init() { memset(BIT, 0, sizeof(BIT)); }

int query(int k)
{
    int ret = 0;
    do {
	ret += BIT[k];
    } while (k &= k - 1);
    return ret;
}

void add(int k, int d)
{
    do {
	BIT[k] += d;
    } while (k += k & -k, k < M);
}

ll find(int t)
{
    vector<int> E(N);
    rep(i, N)
	E[i] = G[i] + S[i] * t;
    map<int, int> zip;
    {
	vector<int> tmp(E);
	sort(all(tmp));
	rep(i, N)
	    zip[tmp[i]] = i + 1;
    }
    init();
    ll ret = 0;
    rep(i, N) {
	int j = zip[E[i]];
	ret += i - query(j - 1);
	add(j, 1);
    }
    return ret;
}

struct q
{
    int num, den;
    q(int num, int den) : num(num), den(den) {}
    bool operator <(const q &t) const {
	return num * t.den < t.num * den;
    }
};

struct event
{
    int a, b;
    event(int a, int b) : a(a), b(b) {}
    q collide() const {
	return q(G[a] - G[b], S[b] - S[a]);
    }
    bool operator <(const event &t) const {
	return collide() < t.collide();
    }
};

struct node
{
    int e, id;
    node(int e, int id) : e(e), id(id) {}
    bool operator <(const node &t) const {
	return e < t.e;
    }
};

ll F;

void enumerate(int t)
{
    vector<event> ans;
    set<node> s;
    rep(i, N) {
	node cur = node(G[i] + S[i] * t, i);
	set<node>::iterator begin = s.lower_bound(cur);
	for (set<node>::iterator it = begin; it != s.end(); ++it)
	    ans.pb(event(it->id, i));
	s.insert(cur);
    }
    sort(all(ans));
    cout << F % 1000 << endl;
    rep(i, (int) min(10000LL, F))
	cout << ans[i].a + 1 << ' ' << ans[i].b + 1 << endl;
}

void solve()
{
    F = find(T);
    if (F <= 10000)
	enumerate(T);
    else {
	int l = 0, r = T;
	while (l + 1 < r) {
	    int m = (l + r) / 2;
	    if (find(m) >= 10000)
		r = m;
	    else
		l = m;
	}
	enumerate(r);
    }
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_--) {
	input();
	solve();
    }

    return 0;
}
