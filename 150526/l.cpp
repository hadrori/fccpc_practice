#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
#define mp make_pair
#define all(u) (u).begin(),(u).end()
#define ll long long

const int N = 32;
ll binom[N][N];
struct _{_(){
  rep(i, N) {
    binom[i][0] = 1;
    repi(j, 1, i+1) {
      binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
    }
  }
}}_;

const int K = 4;

int n;
double p[K];

double solve()
{
  struct entry {
    double p; ll cnt;
    entry(double p, ll cnt) : p(p), cnt(cnt) {}
    bool operator <(const entry& t) const { return p > t.p; }
  };
  priority_queue<entry> que;
  double pa = 1.0;
  for (int a = 0; a <= n; ++a) {
    double pb = pa;
    for (int b = 0; a + b <= n; ++b) {
      double pc = pb;
      for (int c = 0; a + b + c <= n; ++c) {
        const int d = n - a - b - c;
        const ll t = binom[n][a] * binom[n-a][b] * binom[n-a-b][c];
        que.emplace(pc * pow(p[3], d), t);
        pc *= p[2];
      }
      pb *= p[1];
    }
    pa *= p[0];
  }
  double ans = 0.0;
  while (not que.empty()) {
    auto t = que.top();
    que.pop();
    if (que.empty()) {
      return ans;
    }
    if (t.cnt >= 2) {
      ans += (t.cnt - (t.cnt & 1)) * t.p;
      que.emplace(t.p + t.p, t.cnt / 2);
      if (t.cnt & 1) que.emplace(t.p, 1);
    } else {
      auto u = que.top();
      que.pop();
      ans += t.p + u.p;
      que.emplace(t.p + u.p, 1);
      if (u.cnt >= 2) que.emplace(u.p, u.cnt - 1);
    }
  }
  return ans;
}

int main()
{
  cin >> n;
  rep(i, K) cin >> p[i];
  cout << fixed << setprecision(6) << solve() << endl;
  return 0;
}
