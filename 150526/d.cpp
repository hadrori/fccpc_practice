#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
#define mp make_pair
#define all(u) (u).begin(),(u).end()

const int MAX = 100008;
int n, s;
double r[MAX], z[MAX];

double sphere(double tr) {
  return (4.0 * M_PI * tr * tr * tr)/3.0;
}

double hole(double ri, double zi, double z0) {
  if(zi + ri < z0) return sphere(ri);
  if(zi - ri > z0) return 0.0;
  double A = ri * ri * (z0 - zi + ri);
  double B = (z0 - zi) * (z0 - zi) * (z0 - zi) + ri*ri*ri;
  return M_PI * (A - B/3.0);
}

double area(double z0) {
  double V = 100.0 * 100.0 * z0;
  rep(i, n) V -= hole(r[i], z[i], z0);
  return V;
}

double solve(double V) {
  double lower = 0;
  double upper = 100.0;
  //cout << V << endl;
  rep(_, 100) {
    double mid = (upper + lower) / 2.0;
    //cout << mid << " " << area(mid) << " " << V << endl;
    if(area(mid) > V) upper = mid;
    else lower = mid;
  }
  return upper;
}

int main()
{
  cin >> n >> s;
  
  rep(i, n) {
    double dummy;
    cin >> r[i] >> dummy >> dummy >> z[i];
    r[i] /= 1000.0;
    z[i] /= 1000.0;
  }

  double sumV = 100.0 * 100.0 * 100.0;
  rep(i, n) sumV -= sphere(r[i]);

  vector<double> tmp(s);
  rep(i, s) {
    tmp[i] = solve(sumV * (i+1) / s);
  }
  
  double bf = 0;
  rep(i, s) {
    double ans = tmp[i] - bf;
    printf("%.9f\n", ans);
    bf = tmp[i];
  }
  
  
  return 0;
}
