#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(int)(b);++i)
#define all(u) begin(u),end(u)

#ifndef DEBUG
const string name = "damage";
ifstream in(name + ".in");
ofstream out(name + ".out");
#define cin in
#define cout out
#endif

const double eps = 1e-8;
const double pi = atan(1.0) * 4.0;
inline double sq(double x) { return x * x; }

double d, l, r, t, h;

void input()
{
  cin >> d >> l >> r >> t >> h;
  d /= 100.0;
  l /= 100.0;
  r /= 100.0;
  t /= 100.0;
  h /= 100.0;
}

double integrate1(double y) {
  const double d2 = d / 2.0;
  const double th = asin(y / d2);
  return d2 * d2 * (th + sin(2.0 * th) / 2.0);
}
double integrate2(double y) {
  const double d2 = d / 2.0;
  return pow(d2 * d2 - y * y, 1.5) / -3.0 * 2.0;
}

double solve_straight()
{
  const double d2 = d / 2.0;
  if (abs(t) < eps) return l * (integrate1(h - d2) - integrate1(-d2));
  const double th = asin(t / l);
  const double base1 = d * cos(th);
  const double len = h / cos(th);
  const double len1 = (h - base1) / cos(th);
  cerr << th << ' ' << base1 << ' ' << len << ' ' << len1 << endl;
  if (len1 >= l) return pi * d2 * d2 * l;
  const double A = (len1 - len) / d;
  const double B = (len + len1) / 2.0;
  double ret = pi * d2 * d2 * B;
  if (len > l) {
    const double t = (l - B) / A;
    ret -= A * (integrate2(t) - integrate2(-d2));
    ret -= (B - l) * (integrate1(t) - integrate1(-d2));
  }
  if (len1 < 0.0) {
    const double t = B / A;
    ret -= A * (integrate2(d2) - integrate2(t));
    ret -= B * (integrate1(d2) - integrate1(t));
  }
  return ret;
}

void solve()
{
  cout << fixed << setprecision(10);
  cout << solve_straight() << endl;
}

int main()
{
  input();
  solve();
}
