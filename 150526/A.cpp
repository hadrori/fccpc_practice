#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
#define mp make_pair
#define all(u) (u).begin(),(u).end()

int p, a, b, c, d, n;

double calc(int k)
{
  return p*(sin(a*k+b)+cos(c*k+d)+2);
}

double solve()
{
  double ans = n>1? calc(1)-calc(2): 0, mx = calc(1);
  repi(i,2,n+1) {
    double val = calc(i);
    mx = max(mx, val);
    ans = max(ans, mx-val);
  }
  return ans;
}

void input()
{
  cin >> p >> a >> b >> c >> d >> n;
}

int main()
{
  input();
  cout << fixed << setprecision(12);
  cout << solve() << endl; 
  return 0;
}
