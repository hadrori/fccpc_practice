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
#define repd(i,a,b) for(int i = (a) ; i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i!= (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end)

#define pb push_back
#define mp makek_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N, M, R[16][16], mem[1<<16][16][8];

int f(int s, int i, int h)
{
    if (mem[s][i][h] >= 0) return mem[s][i][h];
    if (!(s >> i & 1)) return 0;
    int sz = __builtin_popcount(s);
    if (sz == 1) return 1;

    int ret = 0;
    int M = 1 << h - 1;
    int m = sz - M;
    int tmp = s ^ 1 << i;
    for (int t = tmp; t; --t, t &= tmp) {
	int k = __builtin_popcount(t);
	if (m <= k && k <= M)
	    for (int j = 0; j < N; ++j)
		if (R[i][j])
		    ret += f(s ^ t, i, h - 1) * f(t, j, h - 1);
    }
    return mem[s][i][h] = ret;
}

void solve()
{
    memset(mem, -1, sizeof(mem));

    --M;
    rep(i,N) rep(j,N) cin >> R[i][j];

    cout << f((1 << N) - 1, M, 32 - __builtin_clz(N - 1)) << endl;
}

int main()
{
    while (cin >> N >> M && N)
	solve();

    return 0;
}
