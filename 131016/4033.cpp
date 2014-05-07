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

int m, a, b, c, d, e, f, g, h, i, j, k;

void input()
{
    cin >> m >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k;
}

int solve()
{
    int total = 0;
    for (int x = 1; ; ++x) {
	int w = ((j * x + k) % 3 + 3) % 3;
	if (w == 0)
	    total += a * x * x + b * x + c;
	else if (w == 1)
	    total += d * x * x + e * x + f;
	else
	    total += g * x * x + h * x + i;
	if (total >= m)
	    return x;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
	input();
	cout << solve() << endl;
    }

    return 0;
}


