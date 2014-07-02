#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) repi(i,0,n)

#define mp make_pair
#define pb push_back
#define all(u) (u).begin(),(u).end()

struct rect
{
  int t, x, y, w, h;
  rect () {}
  rect(int t, int x, int y, int w, int h)
    : t(t), x(x), y(y), w(w), h(h) {}
  int area() const {
    return w * h;
  }
  bool operator <(const rect& o) const {
    return mp(t, area()) < mp(o.t, o.area());
  }
};

int n, w, h;

pair<rect, rect> cut(int time, rect cake, int pos)
{
  int x = cake.x;
  int y = cake.y;
  int w = cake.w;
  int h = cake.h;
  pos %= w + h + w + h;
  rect a, b;
  if (pos < w) {
    int c = pos;
    a = rect(time, x, y, c, h);
    b = rect(time, x + c, y, w - c, h);
  } else if (pos < w + h) {
    int c = pos - w;
    a = rect(time, x, y, w, c);
    b = rect(time, x, y + c, w, h - c);
  } else if (pos < w + h + w) {
    int c = w + h + w - pos;
    a = rect(time, x, y, c, h);
    b = rect(time, x + c, y, w - c, h);
  } else {
    int c = w + h + w + h - pos;
    a = rect(time, x, y, w, c);
    b = rect(time, x, y + c, w, h - c);
  }
  return mp(a, b);
}

int main()
{
  while (cin >> n >> w >> h and w) {
    vector<rect> cakes;
    cakes.pb(rect(-1, 0, 0, w, h));
    rep(i, n) {
      sort(all(cakes));
      int p, s;
      cin >> p >> s;
      pair<rect, rect> nw = cut(i, cakes[p - 1], s);
      cakes[p - 1] = nw.first;
      cakes.pb(nw.second);
    }
    int m = cakes.size();
    vector<int> ans;
    rep(i, m) ans.pb(cakes[i].area());
    sort(all(ans));
    rep(i, m - 1) cout << ans[i] << ' ';
    cout << ans.back() << endl;
  }

  return 0;
}
