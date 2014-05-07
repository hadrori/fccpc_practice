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

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

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

typedef complex<double> point;

int N, D;

point solve()
{
    point x(0.0, 0.0);
    double t = 0.0;
    rep(i,N) {
	double ls, rs, time;
	cin >> ls >> rs >> time;
	time *= PI / 180;
	if (ls == rs) {
	    x += polar(time * ls, t + PI / 2);
	} else {
	    point dx = polar((double) D, t);
	    point l = x - dx;
	    point r = x + dx;
	    if (ls == 0) {
		t += time * rs / D / 2;
		x = l + polar((double) D, t);
	    } else if (rs == 0) {
		t -= time * ls / D / 2;
		x = r - polar((double) D, t);
	    } else {
		point o = (ls * r - rs * l) / (ls - rs);
		double dt = time * rs / abs(r - o);
		if ((ls < rs && rs < 0) || (0 < rs && rs < ls))
		    dt = -dt;
		x = o + polar(abs(x - o), arg(x - o) + dt);
		t += dt;
	    }
	}
    }
    return x;
}

int main()
{
    while (cin >> N >> D && N) {
	point ans = solve();
	printf("%.5f\n%.5f\n", ans.real(), ans.imag());
    }
    
    return 0;
}
