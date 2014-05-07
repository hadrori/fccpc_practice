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

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
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
int n, m, k;
int t;
int main() {
    cin >> t;
    //t = 1;
    rep(loop, t){
	cin >> n >> m >> k;
	k--;
	vector<pair<int, int> > yoko(m);
	rep(i, m){
	    cin >> yoko[i].first >> yoko[i].second;
	}
	sort(rall(yoko));
	vector<vector<int> > E(n);
	vector<int> cur(n);
	rep(i, n) cur[i] = i;
	rep(i, m){
	    int a = yoko[i].second-1;
	    int b = a+1;
	    int c = a-1;
	    int d = b+1;
	    E[cur[a]].pb(cur[b]);
	    E[cur[b]].pb(cur[a]);
	    swap(cur[a], cur[b]);
	}
	rep(i, n-1) {
	    E[i].pb(i+1);
	    E[i+1].pb(i);
	}
	rep(i, n){
	    sort(all(E[i]));
	    UNIQUE(E[i]);
	}
	queue<pair<int, int> > q;
	q.push(mp(0, cur[k]));
	map<int, int> memo;
	while(!q.empty()){
	    int cst = q.front().first;
	    int now = q.front().second;
	    q.pop();
	    if(memo.find(now) != memo.end()) continue;
	    memo[now] = cst;
	    rep(i, E[now].size()){
		q.push(mp(cst+1, E[now][i]));
	    }
	}
	rep(i, n) cout << memo[i] << endl;
    }
    return 0;
}
