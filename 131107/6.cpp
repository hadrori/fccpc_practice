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
#define EPS 1e-8
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
int n, l;
vector<double> s, t, u;

bool C3(double v, double start) {
  double volume = start;
  double before = 0;
  rep(i, n) {
    volume += (s[i] - before) * v;
    if(volume > l) volume = l;

    double d = v - u[i];
    volume += d * (t[i] - s[i]);
    if(volume > l) volume = l;
    else if(volume < -EPS) return false;
    before = t[i];
  }
  return true;
}

bool C2(double v, double start) {
  double volume = start;
  double before = 0;
  rep(i, n) {
    volume += (s[i] - before) * v;
    if(volume > l) volume = l;

    double d = v - u[i];
    volume += d * (t[i] - s[i]);
    if(volume > l) volume = l;
    //    else if(volume < -EPS) return false;
    before = t[i];
  }
  volume += (86400-before) * v;
  return volume > start - EPS;
}

bool C(double v) {
  double lower = 0;
  double upper = l;
  double mid;
  double tl;
  while(upper - lower > EPS) {
    mid = (lower + upper) / 2.0;
    if(C3(v, mid)) upper = mid;
    else lower = mid;
    //    cout << mid << endl;
  }
  //    cout << v << " " << lower << " " << upper << endl;
  if(l == upper) return false;
  tl = lower;
  upper = l;
  while(upper - lower > EPS) {
    mid = (lower + upper) / 2.0;
    if(C2(v, mid)) lower = mid;
    else upper = mid;
  }

  return upper > tl + EPS * 10.0;
}

int main(){
  while(cin >> n >> l, n||l) {
    s.resize(n);
    t.resize(n);
    u.resize(n);
    rep(i, n) cin >> s[i] >> t[i] >> u[i];
    double lower = 0;
    double upper = INF;
    double mid;
    while(upper - lower > EPS) {
      mid = (lower + upper) / 2.0;
      if(C(mid)) upper = mid;
      else lower = mid;
    }
    printf("%.6f\n", upper);
    
  }
  return 0;
}
