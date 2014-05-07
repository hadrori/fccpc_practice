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
int n;
int ans;
vector<int> c;
vector<pair<int, int> > primes;
bool isprime(int x) {
    if(x <= 1) return false;
    for(int i = 2; i * i <= x; i++) if(x%i == 0) return false;
    return true;
}
set<pair<pair<int, int> , int> > done;
void dfs(int snum, int now, int mx, int S) {
    if(ans) return;
//    if(done.find(mp(mp(snum, now), S)) != done.end()) return;
//    done.insert(mp(mp(snum, now), S));
    if(__builtin_popcount(S) == n-1) {
	bool ok = false;
	rep(i, n) if(!((S>>i)&1)) {
	    if(c[i] == snum) {
		ok = true;
		break;
	    } 
	}
	if(ok) ans = max(ans, mx);
	return;
    }
    if(now == primes.size()) return;
//    cout << snum << " " << now << " " << mx << endl;
    if((S&primes[now].second) == 0) 
	dfs(snum+1, now+1, max(primes[now].first, mx), S|primes[now].second);
    dfs(snum, now+1, mx, S);
}


int main()
{
    int t = 1;
    while(cin >> n, n >= 0) {
	done.clear();
	c.resize(n);
	rep(i, n) cin >> c[i];
	ans = 0;
	//prime
	primes.clear();
	rep(S, 1<<n) {
	    int sum = 0;
	    rep(i, n) if((S>>i)&1) sum += c[i];
	    if(isprime(sum)) primes.pb(mp(sum, S));
	}
	sort(rall(primes));
	dfs(0, 0, 0, 0);
	cout << "Case " << t << ": ";
	if(ans) cout << ans << endl;
	else cout << "not a valid clue\n";
	t++;
    }
    return 0;
}
