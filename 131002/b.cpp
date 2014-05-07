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

typedef complex<double> P;

double cross(const P& a, const P& b) {
    return imag(conj(a)*b);
}

double dot(const P& a, const P& b) {
    return real(conj(a)*b);
}

struct L {
    P a, b;
    L(const P &a, const P &b) : a(a), b(b){ }
};

/* 点の進行方向 (a->b->c) */
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // +1 : 反時計回り
    if (cross(b, c) < -EPS)   return -1;       // -1 : 時計回り
    if (dot(b, c) < 0)     return +2;       // +2 : 線上(c--a--b)
    if (norm(b) < norm(c)) return -2;       // -2 : 線上(a--b--c)
    return 0;
}

bool intersectLL(const L &l, const L &m) {
    return abs(cross(l.b-l.a, m.b-m.a)) > EPS || // 平行でない
	abs(cross(l.b-l.a, m.a-l.a)) < EPS;   // 重なってない
}

P crosspointLL(const L &l, const L &m) {
    double A = cross(l.b - l.a, m.b - m.a);
    double B = cross(l.b - l.a, l.b - m.a);
    if (abs(A) < EPS && abs(B) < EPS) return m.a; // 重なっている
    if (abs(A) < EPS) return P(INF, INF); // 交差しない
    return m.a + B / A * (m.b - m.a);
}

int n;
vector<P> p;

bool attempt(P x)
{
    rep(i, n)
	if (ccw(p[i], p[(i + 1) % n], x) == -1)
	    return false;
    return true;
}

int main(){
    while (cin >> n && n) {
	p.clear();
	rep(i, n) {
	    double x, y; cin >> x >> y;
	    p.pb(P(x, y));
	}

	vector<P> cand;
	rep(i, n) {
	    rep(j, n) {
		if (i == j) continue;
		if (intersectLL(L(p[i], p[(i + 1) % n]), L(p[j], p[(j + 1) % n])))
		    cand.pb(crosspointLL(L(p[i], p[(i + 1) % n]), L(p[j], p[(j + 1) % n])));
	    }
	}

	int ans = 0;
	repit(it, cand) {
	    if (attempt(*it)) {
		ans = 1;
		break;
	    }
	}
	cout << ans << endl;
    }

    return 0;
}
