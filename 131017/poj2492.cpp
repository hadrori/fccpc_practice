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
int n, m;

vector<vector<int> > G;

int main()
{
    int x;
    cin >> x;
    rep(_, x) {
	cin >> n >> m;
	G.clear();
	G.resize(n);
	rep(i, m) {
	    int a, b;
	    cin >> a >> b;
	    a--; b--;
	    G[a].pb(b);
	    G[b].pb(a);
	}
	
	bool ans = true;
	vector<int> memo(n);
	rep(i, n) if(!memo[i]){
	    stack<int> stk;
	    stk.push(i);
	    memo[i] = 1;
	    while(!stk.empty()) {
		int now = stk.top();
		int gender = memo[now];
		stk.pop();
		rep(j, G[now].size()) {
		    if(memo[G[now][j]] == gender) ans = false;
		    int ng;
		    if(gender == 1) ng = 2;
		    else ng = 1;
		    if(!memo[G[now][j]]) {
			memo[G[now][j]] = ng;
			stk.push(G[now][j]);
		    }
		}
	    }
	}
	cout << "Scenario #" << _+1 << ":\n";
	if(ans) cout << "No suspicious bugs found!" << endl;
	else cout << "Suspicious bugs found!" << endl;
	if(_ != x-1) cout << endl;
    }
    return 0;
}
