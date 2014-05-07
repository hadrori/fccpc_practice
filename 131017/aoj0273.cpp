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
typedef complex<double> P;
#define X real()
#define Y imag()
double angle(const P &a, const P &b) { return arg(); }
int c, w;

struct edge {
    int from, to, id;
};

vector<vector<edge> > G;
vector<edge> E;

int main()
{
    while(cin >> c >> w, c || w) {
	vector<P> p(c);
	rep(i, c) cin >> p[i].X >> p[i].Y;
	
	G.clear();
	G.resize(c);
	E.clear();
	int num = 0;
	rep(i, w) {
	    int s, t;
	    cin >> s >> t;
	    s--; t--;
	    G[s].pb((edge){s, t, num++});
	    G[t].pb((edge){t, s, num++});
	    E.pb((edge){s, t, num-2});
	    E.pb((edge){t, s, num-1});
	}
	
	bool done[602] = {0};
	int area = 0;
	rep(i, num) if(!done[E[i].id]) {
	    int start = E[i].from;
	    edge *now = &E[i];
	    while(now->to != start) {
		done[now->id] = true;

		rep(i, G[now->id].size()) {
		    G
		}

	    } while(now->to != start);
	    area++;
	}
    }
	
    return 0;
}
