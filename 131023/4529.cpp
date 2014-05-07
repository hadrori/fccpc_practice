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
int a[20][20];
int rem[20][1<<16];
int rem2[20];
int mask;
int ans;

void dfs(int pos, int S1, int S2, int S3, int sum) {
    if(pos == -1){
	ans = max(ans, sum);
	return;
    }
    //if(sum + rem2[pos] <= ans) return;
    if(pos && sum + rem[pos][S1] <= ans) {
//	cout << pos << " :" << sum << " + " << rem[pos][S1] << " <= " << ans << endl; 
	return;
    }
    repd(i, n-1, 0) 
	if(!((S1|S2|S3)&(1<<i))) 
	    dfs(pos-1, S1|(1<<i), ((S2|(1<<i))>>1), mask&((S3|(1<<i))<<1), sum + a[pos][i]);
}

int main()
{
    int t;
    cin >> t;
    while( t --> 0 ) {
	cin >> n;
	rep(i, n) rep(j, n) cin >> a[j][i];
	mask = (1<<n)-1;
	rem2[0] = a[0][n-1];
	rep(i, n-1) rem2[i+1] = rem2[i] + a[i+1][n-1];
	
	repi(i, 1, n) rep(S, 1<<n) if(__builtin_popcount(S) == n-(i+1)){
	    int tS = (1<<n) - 1 - S;
	    rem[i][S] = 0;
	    rep(j, i + 1) {
		int pos = 0;
		int ttS = tS;
//		cout << i << " " << S << " " << tS << endl;
		while(!(ttS&1)) {
		    pos++;
		    ttS >>= 1;
		}
//		bitset<16> tmp(S);
//		cout << i << " " << tmp << " " << rem[i][S] << " " << a[j][pos] << endl;
		rem[i][S] += a[j][pos];
		tS -= tS&-tS;
	    }
	
	}

	ans = 0;
	dfs(n-1, 0, 0, 0, 0);
	cout << ans << endl;
    }
    return 0;
}
