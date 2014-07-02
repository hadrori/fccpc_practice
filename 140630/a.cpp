#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) repi(i,0,n)

int n;

void solve()
{
  vector<int> v;
  rep(i, n) {
    int s; cin >> s;
    v.push_back(s);
  }
  sort(v.begin(), v.end());

  int sum = 0;
  repi(i, 1, n - 1) sum += v[i];
  cout << sum / (n - 2) << endl;
}

int main()
{
  while (cin >> n and n) {
    solve();
  }

  return 0;
}
