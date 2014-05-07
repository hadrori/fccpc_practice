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

const int N = 128;

int n, r, x[N], y[N];

void input()
{
    cin >> r;
    r *= r;
    rep(i, n)
	cin >> x[i] >> y[i];
}

inline int sq(int n) { return n * n; }
inline int d(int i, int j) { return sq(x[j] - x[i]) + sq(y[j] - y[i]); }

int solve()
{
    int ret = 0;
    rep(i, n) repi(j, i + 1, n) repi(k, j + 1, n)
	ret += (d(i, j) <= r) + (d(j, k) <= r) + (d(k, i) <= r) == 2;
    return ret;
}

int main()
{
    while (cin >> n && n) {
	input();
	cout << solve() << endl;
    }

    return 0;
}
