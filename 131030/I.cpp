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

int n, k, m;
vector<vector<pair<int, int> > > G;
vector<int> t;
int dst[233][233];
vector<pair<double, double> > range[8006][233];
double lng[8006];
int edge;

void dfs(int now, int hotel, double left) {
    
}

bool C(double lim) {
    memset(range, 0, sizeof(range));
    rep(i, n) repi(j, n, n+k) {
	dfs(j, i, lim);
    }

    for(int i = 0; i < edge; i+=2) {
	double r1
	rep(j, n) {
	    rep(kk, range[i].size()) {
		if(range[i][])
	    }
	}
    }

} 

int main() {
    while(cin >> n>> k >> m, n||k||m) {
	G.resize(n+k);
	t.resize(n);
	rep(i, n+k) rep(j, n+k) dst[i][j] = INF;
	int id = 0;
	rep(i, m) {
	    int a, b, l;
	    cin >> a >> b >> l;
	    a--; b--;
	    lng[id] = l;
	    G[a].pb(mp(b, id));
	    G[b].pb(mp(a, id++));
	    dst[a][b] = min(dst[a][b], l);
	}
	edge = id;
	rep(i, n) cin >> t[i];
	rep(kk, n+k) rep(i, n+k) rep(j, n+k) dst[i][j] = min(dst[i][j], dst[i][kk] + dst[kk][j]);
	
	double lower = 0;
	double upper = INF;
	double mid;
	while(upper - lower > EPS) {
	    mid = (lower + upper) / 2;
	    if(C(mid)) upper = mid;
	    else lower = mid;
	}
	printf("%.3f\n", upper);

    }
    return 0;
}
