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

#define repi(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i =(a); i >= (b); i--)
#define repit(i,a) for(__typedef((a).begin()) i =(a); i != (a).end(); i++)

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

const int M = 100010;
const int MOD = 1000000007;

int N, Q, p[M] = {};

void input()
{
    cin >> N >> Q;
    repi(i, 1, N + 1)
	cin >> p[i];
}

ll block, mod_inv[100] = {0, 1}, a[M] = {};
ll la[M], lb[500];

inline ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

void gen()
{
    block = (int) sqrt(N);
    repi(i, 2, 100)
	mod_inv[i] = (ll) mod_inv[MOD % i] * (MOD - MOD / i) % MOD;

    fill(a + 1, a + M, -1);
    fill(lb, lb + 500, 1);
    repi(i, 1, N + 1) {
	if (a[i] >= 0)
	    continue;
	ll cur = i, len = 0, sum = 0;
	do {
	    ++len, sum += cur, cur = p[cur];
	} while (cur != i);
	do {
	    a[cur] = (ll) sum * mod_inv[len] % MOD;
	    la[cur] = len;
	    lb[cur / block] = lcm(lb[cur / block], len);
	} while (cur != i);
    }
    repi(i, 1, N + 1) {
	a[i] += a[i - 1];
	if (a[i] >= MOD)
	    a[i] -= MOD;
    }
}

#define dump(x) cerr<<#x<<" = "<<x<<endl;

ll query(int l, int r)
{
    ll ret = 1;
    int _l = l / block;
    int _r = r / block;
    if (_l == _r) {
	repi(i, l, r + 1)
	    ret = lcm(ret, la[i]);
    } else {
	repi(i, l, (_l + 1) * block)
	    ret = lcm(ret, la[i]);
	repi(i, _l + 1, _r)
	    ret = lcm(ret, lb[i]);
	repi(i, _r * block, r + 1)
	    ret = lcm(ret, la[i]);
    }
    return ret;
}

ll solve(int l, int r)
{
    return (a[r] - a[l - 1] + MOD) % MOD * (query(l, r) % MOD) % MOD;
}

int main()
{
    input();
    gen();
    rep(i, Q) {
	int l, r;
	cin >> l >> r;
	cout << solve(l, r) << endl;
    }

    return 0;
}
