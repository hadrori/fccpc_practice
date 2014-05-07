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

#define repi(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) repi(i, 0, a)
#define repd(i, a, b) for(int i = (a); i >= (b); i--)
#define repit(i, a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

#define all(u) (u).begin(), (u).end()
#define rall(u) (u).rbegin(), (u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)), (u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

struct point
{
    double x, y, z;
    point(double x, double y, double z) : x(x), y(y), z(z) {}
    double abs() {
	return sqrt(x * x + y * y + z * z);
    }
    double theta(point t) {
	double d = x * t.x + y * t.y + z * t.z;
	return acos(d / abs() / t.abs());
    }
};

int n, m;
vector<point> s, t;
vector<double> psi;

int solve()
{
    int ret = 0;
    rep(i, n) {
	rep(j, m) {
	    if (s[i].theta(t[j]) < psi[j] + EPS) {
		++ret;
		break;
	    }
	}
    }
    return ret;
}

int main()
{
    while (cin >> n && n) {
	s.clear();
	t.clear();
	psi.clear();

	rep(i, n) {
	    double x, y, z;
	    cin >> x >> y >> z;
	    s.pb(point(x, y, z));
	}
	cin >> m;
	rep(i, m) {
	    double x, y, z, d;
	    cin >> x >> y >> z >> d;
	    t.pb(point(x, y, z));
	    psi.pb(d);
	}

	cout << solve() << endl;
    }

    return 0;
}
