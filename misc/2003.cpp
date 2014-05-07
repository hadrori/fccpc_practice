#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e10
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef complex<double> P;
typedef vector<P> G;

double cross(const P& a, const P& b){
  return imag(conj(a)*b);
}

double dot(const P& a, const P& b){
  return real(conj(a)*b);
}

struct L : public vector<P>{
  L(const P &a, const P &b){
    pb(a); pb(b);
  }
};

int ccw(P a, P b, P c){
  b -= a; c -= a;
  if(cross(b, c) > 0) return +1;
  if(cross(b, c) < 0) return -1;
  if(dot(b, c) < 0) return +2;
  if(norm(b) < norm(c)) return +-2;
  return 0;
  
}

bool intersectSS(const L &s, const L &t){
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 && ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}

P crosspointLL(const L &l, const L &m){
  double A = cross(l[1] -l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if(abs(A) < EPS && abs(B) < EPS) return m[0];
  if(abs(A) < EPS) return P(INF,INF);
  return m[0] + B / A * (m[1] - m[0]);
}

int main(){
  int z;
  cin >> z;
  while(z--){
    P a, b;
    cin >> a.real() >> a.imag() >> b.real() >> b.imag();
    L ab(a,b);
    int n;
    cin >> n;
    vector<pair<double,int> > cr;
    while(n--){
      P s, t;
      int o, l;
      cin >> s.real() >> s.imag() >> t.real() >> t.imag();
      cin >> o >> l;
      L st(s,t);
      if(intersectSS(ab,st)){
	P p = crosspointLL(ab,st);
	double d = sqrt((a.real()-p.real())*(a.real()-p.real()) + (a.imag()-p.imag())*(a.imag()-p.imag()));
	if(!o) l = (l)? 0: 1;
	cr.pb(mp(d,l));
      }
    }
    if(cr.size()>0){
      sort(all(cr));
      int l = cr[0].second;
      int ans = 0;
      repi(i,1,cr.size()){
	if(l != cr[i].second){
	  ans++;
	  l = cr[i].second;
	}
      }
      cout << ans << endl;
    }else cout << 0 << endl;
  }
}
