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

#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);--i)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();++i)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)
#define MAX_D 6
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const ll MOD = 1000000007;

int n;
ll b[201][MAX_D+10][201];
ll c[MAX_D][201];
ll e[201][MAX_D+10][201];
ll fact[201];
ll sum[MAX_D+10];

ll power(int b, int a) {
    ll ret = 1;
    ll tmp = b;

    while(a) {
	if(a&1) {
	    ret *= tmp; 
	    ret %= MOD;
	}
	tmp *= b;
	tmp %= MOD;
	a >>= 1;
    }
    return ret;
}

ll fact_gen() {
    fact[0] = 1;
    rep(i, n) fact[i+1] = (fact[i] * (i+1)) % MOD;
}

ll sum_gen() {
    sum[0] = 1;
    ll tmp = 10;
    rep(i, MAX_D) {
	sum[i+1] = (sum[i] + tmp) % MOD;
	tmp *= 10;
	tmp %= MOD;
    } 
}

int main()
{
    cin >> n;
    fact_gen();
    sum_gen();
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> d(n);
    rep(i, n) {
	int tmp = a[i];
	while(tmp) {
	    d[i]++;
	    tmp/=10;
	}
    }
    memset(b, 0, sizeof(b));
    rep(i, n-1) {
	rep(j, MAX_D) rep(k, n) b[i+1][j+d[i+1]][k+1] += b[i][j][k] % MOD;
	b[i+1][d[i+1]][1]++;
    }
    rep(j, MAX_D) rep(k, n) {
	c[j][k] = b[n-1][j][k];
    }
    rep(i, n) {
	rep(j, MAX_D) rep(k, n) {
	    e[i][j+d[i]][k+1] = (c[j+d[i]][k+1] - (k+1) * e[i][j][k])%MOD;
	    // cout << a[i] << " " << j << " " << k << " " << e[i][j][k] << endl;
	}
    }
    ll ans = 0;
    rep(i, n) ans += a[i];
    rep(i, n) rep(j, MAX_D) rep(k, n){
	ans += (((a[i] * sum[k])%MOD) * ((fact[k] * e[i][j][k])%MOD) % MOD);
	ans = (ans + MOD) % MOD;
	cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
