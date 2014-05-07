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

#define repi(i,a,b) for(int i = (a);i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

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

typedef complex<double> P;

inline bool eq(double a, double b){ return fabs(a-b) < EPS;}
inline bool ps(double a){ return a > EPS;}
inline bool ng(double a){ return ps(-a);}
inline bool gr(double a, double b){ return ps(a-b);}

double cross(P a, P b){return imag(conj(a)*b);}
double dot(P a, P b){return real(conj(a)*b);}

struct L{
  P a, b;
  L(P a, P b) : a(a), b(b){}
};

int ccw(P a, P b, P c){
  b -= a; c -= a;
  if(ps(cross(b, c))) return 1;
  if(ng(cross(b, c))) return -1;
  if(ng(dot(b, c))) return 2;
  if(gr(norm(c), norm(b))) return -2;
  return 0;
}

bool intersectLL(L l, L m){ return !eq(cross(l.b-l.a, m.b-m.a), 0.0) || eq(cross(l.b-l.a,m.a-l.a), 0.0);}
P crosspointLL(L l, L m){
  double A = cross(l.b-l.a,m.b-m.a);
  double B = cross(l.b-l.a,l.b-m.a);
  if(eq(A,0.0) && eq(B, 0.0)) return m.a;
  if(eq(A,0.0)) return P(INF, INF);
  return m.a + B / A * (m.b - m.a);
}

P projection(L l, P p){
  double t = dot(p-l.a,l.a-l.b) / norm(l.a-l.b);
  return l.a + t*(l.a-l.b);
}

double distanceLP(L l, P p){
  return abs(p - projection(l,p));
}

int n; 
double w, h, r;
bool inrange(P p) {
  return p.real() > r - EPS && p.real() < w - r + EPS
    && p.imag() > r - EPS && p.imag() < h - r + EPS;
}
int main(){
  while(cin >> w >> h >> n >> r, w||h||n||r) {
    vector<L> lines;
    vector<int> t(n);
    rep(i, n) {
      P p1, p2;
      cin >> p1.real() >> p1.imag() >> p2.real() >> p2.imag() >> t[i];
      lines.pb(L(p1, p2));
    }

    vector<L> tl;
    tl.pb(L(P(0.0, r), P(w, r)));
    tl.pb(L(P(r, 0.0), P(r, h)));
    tl.pb(L(P(0.0, h-r), P(w, h-r)));
    tl.pb(L(P(w-r, 0.0), P(w-r, h)));
    rep(i, n) {
      P dir = (lines[i].b - lines[i].a) * P(0.0, 1.0);
      dir = (t[i]+r) * dir/abs(dir);
      tl.pb(L(lines[i].a + dir, lines[i].b + dir));
      tl.pb(L(lines[i].a - dir, lines[i].b - dir));
    }
	
    bool ans = false;
    rep(i, tl.size()) repi(j, i+1, tl.size()) {
      P cp;
      if(intersectLL(tl[i], tl[j]) && inrange(cp = crosspointLL(tl[i], tl[j]))) {
	bool ok = true;
	rep(k, lines.size()) 
	  if(distanceLP(lines[k], cp) < t[k] + r - EPS) ok = false;
	if(ok) ans = true;
      }
    }
    if(ans) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}
