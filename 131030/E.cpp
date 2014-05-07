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
int n;
ll p[1024][1024];
int s, g;
bool C(ll lim) {
    stack<int> stk;
    stk.push(s);
    vector<bool> done(n);
    while(!stk.empty()) {
	int now = stk.top(); stk.pop();
	if(done[now]) continue;
	done[now] = true;
	if(now == g) return true;
	rep(i, n) if(p[now][i] <= lim) stk.push(i);
    }
    return false;
}

int main()
{
    while(cin >> n, n) {
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	rep(i, n) rep(j, n) {
	    p[i][j] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
	}
	cin >> s >> g;
	s--; g--;
	ll lower = 0;
	ll upper = 1LL<<32;
	ll mid;
	while(upper - lower > 1) {
	    mid = (lower + upper) / 2;
	    if(C(mid)) upper = mid;
	    else lower = mid;
	}
	cout << upper << endl;
    }
    return 0;
}
