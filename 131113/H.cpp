#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>

#define repi(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a); i >= (b); i--)
#define repit(i,a) for(__typedef((a).begin()) i = (a).begin(); i = (a).end(); i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)), (u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define double long double

double P, Q;
ll x, y, p, q;

void input() {
  cin >> x >> y >> P >> Q;

  p = ll(100.0 * P + 0.5);
  q = ll(100.0 * Q + 0.5);
}

void solve() {
  ll tiger = q * (p * x + p * y) + 100 * (100 - q) * x;
  ll wolf = (100 - q) * (p * x + p * y) + 100 * q * y;
  if (tiger > wolf)
    printf("tiger %lld.%04lld\n", tiger / 10000, tiger % 10000);
  else
    printf("wolf %lld.%04lld\n", wolf / 10000, wolf % 10000);
}

int main()
{
  int T;
  cin >> T;
  while (T--) {
    input();
    solve();
  }
    
  return 0;
}
