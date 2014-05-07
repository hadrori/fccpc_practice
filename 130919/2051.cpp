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
#define mp make_pair
#define INF 1e9
#define EPS 1e-6
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef complex<double> P;
typedef vector<P> G;
int n;

namespace std{
    bool operator<(const P &a, const P &b) {
	return abs(real(a)-real(b)) > EPS ? real(a) < real(b): imag(a) < imag(b);
    }
}

struct cmp
{
    bool operator ()(const double &a, const double &b) {
	return a + EPS < b;
    }
};

P rotate(const P &a, double th) { return a*polar(1.0, th); }
double angle(const P &a, const P &b) { return arg(conj(a)*b); }

P centerG(const G &g) {
    P p = P(0, 0);
    rep(i, n) p += g[i];
    p /= n;
    return p;
}

int main(){
    while(cin >> n, n) {
	G g1(n), g2(n);
	rep(i, n) cin >> g1[i].real() >> g1[i].imag();
	rep(i, n) cin >> g2[i].real() >> g2[i].imag();
	P c1 = centerG(g1), c2 = centerG(g2);
	rep(i, n) {
	    g1[i] -= c1;
	    g2[i] -= c2;
	}
	//cout <<"c " << c1 << " " << c2 << endl;
	G tg = g2;
	double ans = INF;
	sort(all(g1));
	rep(i, n) {
	    g2 = tg;
	    double th = angle(g2[i], g1[0]); 
	    rep(j, n) g2[j] = rotate(g2[j], th);
	    bool flag = true;
	    
	    sort(all(g2));
	    rep(j, n) if(abs(g1[j] - g2[j]) > EPS) flag = false;
	    
	    //cout << "a "<< i << endl;
	    //rep(j, n) cout << g1[j] << g2[j] << endl;
	    
	    if(flag) {
		if(th < 0) th = -th;
		if(th > PI) th = 2*PI - th;
		ans = min(ans, th);
	    }
	}
	printf("%.11f\n", ans);
    }
    return 0;
}
