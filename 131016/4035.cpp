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
int cases, n, m;
vector<int> x, y;
vector<vector<int> > G;
vector<bool> done;
bool dfs(int now, int t) {
    if(done[now]) return 0;
    done[now] = true;
    if(now == t) return true;
    bool ret = false;
    rep(i, G[now].size()) {
	ret |= dfs(G[now][i], t);
    }
    return ret;
}

bool C(int d) {
    int s = x.size();
    int t = x.size()+1;
    G.clear();
    G.resize(t+1);
    done.clear();
    done.resize(t+1);
    rep(i, x.size()) {
	if(x[i] <= d || n - y[i] - 1 <= d) {
	    G[s].pb(i);
	    G[i].pb(s);
	}
	if(n - x[i] - 1 <= d || y[i] <= d) {
	    G[t].pb(i);
	    G[i].pb(t);
	}
    }
    rep(i, x.size()) rep(j, x.size()) if(i != j) {
	if(abs(x[i]-x[j]) + abs(y[i]-y[j]) <= 2 * d) G[i].pb(j);
    }
    return dfs(s, t);
}

int main()
{
    cin >> cases;
    rep(_, cases) {
	cin >> n >> m;
	vector<int> d(m);
	vector<double> p(m);
	rep(i, m) cin >> d[i] >> p[i];
	x.clear(); y.clear();
	int tx, ty;
	while(cin >> tx, tx >= 0) {
	    cin >> ty;
	    x.pb(tx); y.pb(ty);
	}
	
	int lower = 0;
	int upper = 20001;
	int mid;
	while(upper - lower > 1) {
	    mid = (upper + lower) / 2;
	    if(C(mid)) upper = mid;
	    else lower = mid;
	}
	int ad = upper - 1;
	double ans = 0;
	rep(i, m) if(d[i] <= ad) ans += p[i];
	printf("%.10f\n", ans);
    }
    return 0;
}


