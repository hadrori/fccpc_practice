#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define all(u) begin(u),end(u)

int n, m;
ofstream ofs("alter.out");
void input()
{
  ifstream ifs("alter.in");
  ifs >> n >> m;
}

void put(int a, int b, int c, int d)
{
  ofs << a+1 << ' ' << b+1 << ' ' << c+1 << ' ' << d+1 << endl;
}

void solve()
{

  ofs << n/2 + m/2 << endl;
  for (int i = 1; i < n; i += 2) {
    put(i, 0, i, m-1);
  }
  for (int j = 1; j < m; j += 2) {
    put(0, j, n-1, j);
  }
  ofs.close();
}

int main()
{
  input();
  solve();
}
