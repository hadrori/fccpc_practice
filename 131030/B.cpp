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
int n, m, k, p;

struct node {
    int now, cst, cond;
    bool operator<(const node &o) const {
	return cst > o.cst;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--) {
	cin >> n>> m >> k >> p;
	vector<vector<pair<int, int> > > l(n);
	vector<vector<pair<int, int> > > d(n);
	rep(i, m) {
	    int a, b, tl, td;
	    cin >> a >> b >> tl >> td;
	    a--; b--;
	    l[a].pb(mp(b, tl));
	    l[b].pb(mp(a, tl));
	    d[a].pb(mp(b, td));
	    d[b].pb(mp(a, td));
	}
	rep(i, p) {
	    int s, g;
	    cin >> s >> g;
	    s--; g--;
	    vector<vector<bool> > done(k+1);
	    rep(j, done.size()) done[j].resize(n);
	    priority_queue<node> pq;
	    pq.push((node){s, 0, 0});
	    int ans = -1;
	    while(!pq.empty()) {
		int now = pq.top().now;
		int cst = pq.top().cst;
		int cond = pq.top().cond;
		pq.pop();
		if(done[cond][now]) continue;
		done[cond][now] = true;
		if(now == g) {
		    ans = cst;
		    break;
		}
		rep(j, l[now].size()) {
		    if(d[now][j].second != cond) pq.push((node){d[now][j].first, cst+l[now][j].second, d[now][j].second});
		}
	    }
	    if(ans != -1) cout << ans << endl;
	    else cout << "infinity" << endl;
	}
    }
    return 0;
}
