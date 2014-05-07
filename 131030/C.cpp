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

const int N = 256;

int n, p[N], q, r;

void input()
{
    cin >> n;
    rep(i, n)
	cin >> p[i];
    cin >> q >> r;
}

double cur[N], next[N];

double solve()
{
    *cur = 1.0;
    fill(cur + 1, cur + N, 0.0);
    int b = 1;
    repd(i, n - 1, 0) {
	double prob = (double) p[i] / 100.0;
	rep(j, q)
	    next[j] = (1.0 - prob) * cur[j] + prob * cur[((j - b) % q + q) % q];
	b <<= 1;
	if (b >= q)
	    b -= q;
	rep(j, q)
	    cur[j] = next[j];
    }
    return cur[r];
}

int main()
{
    int T; cin >> T;
    while (T--) {
	input();
	printf("%.5f\n", solve());
    }

    return 0;
}
