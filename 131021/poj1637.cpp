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
typedef pair<int,int> pii;

vector<vector<pii> > path;
bool used[1024];
int m, s;

bool dfs(int pos, int cnt){
    if(cnt == s) {
	if(pos == 0) return true;
	else return false;
    }
    rep(i,path[pos].size())
	if(!used[path[pos][i].second]){
	    used[path[pos][i].second] = true;
	    bool ret = dfs(path[pos][i].first, cnt+1);
	    used[path[pos][i].second] = false;
	    if(ret) return true;
	}
    return false;
}

int main()
{
    int Q; cin >> Q;
    while(Q--){
	cin >> m >> s;
	path.clear();
	path.resize(m);
	memset(used,0,sizeof(used));
	rep(i,s){
	    int x, y, d;
	    cin >> x >> y >> d;
	    x--; y--;
	    path[x].pb(pii(y,i));
	    if(!d) path[y].pb(pii(x,i));
	}
	if(dfs(0,0)) cout << "possible\n";
	else cout << "impossible\n";
    }
    return 0;
}
