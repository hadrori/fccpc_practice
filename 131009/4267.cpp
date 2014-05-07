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
int loop;
int n, root;
int main(){
    cin >> loop;
    rep(_, loop) {
	cin >> n >> root;
	vector<int> w(n);
	vector<vector<int> > child(n);
	vector<int> parent(n);
	rep(i, n) parent[i] = -1;
	rep(i, n) {
	    int cnum;
	    cin >> w[i] >> cnum;
	    child[i].resize(cnum);
	    rep(j, cnum) {
		cin >> child[i][j];
		parent[child[i][j]] = i;
	    }
	}
	vector<int> weight(n);
	vector<bool> done(n);
	queue<int> q;
	rep(i, n) if(child[i].size() == 0) q.push(i);
	while(!q.empty()) {
	    int now = q.front(); q.pop();
	    if(done[now]) continue;
	    done[now] = true;
//	    cout << now << endl;
	    weight[now] = w[now];
	    rep(i, child[now].size()) weight[now] += weight[child[now][i]];
	    int par = parent[now];
	    bool flag = true;
	    if(par >= 0) {
		rep(i, child[par].size()) if(!done[child[par][i]]) flag = false; 
	    }else flag = false;
	    if(flag) q.push(par);
	}


	int now = root;
	int ans = w[root];
	vector<int> v;
	v.pb(root);
	while(child[now].size()) {
	    int mw = 0;
	    int mi = -1;
	    rep(i, child[now].size()) {
		if(weight[child[now][i]] >= mw) {
		    mw = weight[child[now][i]];
		    mi = i;
		}
	    }
	    ans += w[child[now][mi]];
	    v.pb(child[now][mi]);
	    now = child[now][mi];
	}
	cout << ans << endl;
	rep(i, v.size()) cout << v[i] << ((i==v.size()-1||i%10==9)?"\n":" ");
	  
    }
    return 0;
}
