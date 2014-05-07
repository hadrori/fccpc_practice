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
vector<int> d;
vector<int> v;
vector<int> ans;
vector<int> selected;
bool ok;
int n;
void dfs(int pos, int S) {
    if(ok) return;

    bool flag = true;
    vector<int> tv = v;
    sort(all(tv));
    rep(i, tv.size()) if(tv[i] <= i) {flag = false; break;}
    if(!flag) return;
    
    if(pos == n) {
	ok = true;
	ans = selected;
	return;
    }
    rep(i, n) if(!((S>>i)&1)) {
	v.pb(d[i] - pos);
	selected.pb(i+1);
	dfs(pos+1, S|(1<<i));
	v.pop_back();
	selected.pop_back();
    }
}

int main()
{
    while(cin >> n, n) {
	d.resize(n);
	rep(i, n) cin >> d[i];
	v.clear();
	selected.clear();
	
	ok = false;
	dfs(0, 0);
	
	if(!ok) cout << "no solution\n";
	else {
	    vector<pair<int, int> > tv;
	    rep(i, ans.size()) tv.pb(mp(d[ans[i]-1] - i, -ans[i]));
	    sort(rall(tv));
	    rep(i, tv.size()) cout << " p" << -tv[i].second;
	    rep(i, ans.size()) cout << " q" << ans[i];
	    cout << endl;
	}
    }
    return 0;
}
