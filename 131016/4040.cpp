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
#define printv(v) repit(i,v){ cout << *i << endl;}

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

const int M = 128;

int N, a[M], b[M], c[M], d[M], L;
map<int, int> name;

void input()
{
    cin >> N;
    rep(i, N) {
	int tmp;
	cin >> tmp >> a[i] >> b[i] >> c[i] >> d[i];
	name[tmp] = i;
    }
    cin >> L;
}

ll X[M][M], Y[M][M];

void init()
{
    memset(X, 0, sizeof(X));
    memset(Y, 0, sizeof(Y));
    memset(d, 0, sizeof(d));
}

void gen()
{
    rep(i, N) {
	++X[name[a[i]]][i];
	++X[name[b[i]]][i];
	++X[name[c[i]]][i];
    }
}

void mul(ll x[M][M], ll y[M][M])
{
    ll tmp[M][M] = {};
    rep(k, N) rep(i, N) rep(j, N)
	tmp[i][j] += x[i][k] * y[k][j];
    // memcpy(x, tmp, sizeof(x));
    rep(i, N) rep(j, N)
	x[i][j] = tmp[i][j];
}

ll solve()
{
    rep(i, N)
	Y[i][i] = 1;
    rep(i, L)
	mul(Y, X);
    ll ans = 0;
    rep(i, N)
	ans += d[i] * Y[i][0];
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T --> 0) {
	init();
	input();
	gen();
	cout << solve() << endl;
    }

    return 0;
}


