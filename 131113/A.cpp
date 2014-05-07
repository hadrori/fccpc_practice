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

map<char, int> ofs;

void gen()
{
  ofs['m'] = 0;
  ofs['s'] = 1;
  ofs['p'] = 2;
  ofs['c'] = 3;
}

int a[64];

void input()
{
  memset(a, 0, sizeof(a));
  rep(i, 13) {
    int n; char kind;
    scanf("%d%c", &n, &kind);
    --n;
    if (kind == 'c')
      n *= 2;
    ++a[ofs[kind] * 10 + n];
  }
}

bool check(int i = 0, bool pair = false)
{
  if (a[i] == 0) {
    if (i >= 50)
      return pair;
    else
      return check(i + 1, pair);
  }

  bool ret = false;
  if (a[i] >= 1 && a[i + 1] >= 1 && a[i + 2] >= 1) {
    --a[i], --a[i + 1], --a[i + 2];
    ret |= check(i, pair);
    ++a[i], ++a[i + 1], ++a[i + 2];
  }
  if (a[i] >= 2 && !pair) {
    a[i] -= 2;
    ret |= check(i, true);
    a[i] += 2;
  }
  if (a[i] >= 3) {
    a[i] -= 3;
    ret |= check(i, pair);
    a[i] += 3;
  }
  return ret;
}

bool check1()
{
  bool ret = true;
  rep(i, 50)
    ret &= a[i] == 0 || a[i] == 2;
  return ret;
}

inline bool yao(int i) { return i < 30 ? i % 10 == 0 || i % 10 == 8 : i % 2 == 0; }

bool check2()
{
  int kind = 0;
  bool pair = false;
  rep(i, 50) {
    kind += !!a[i];
    if (!yao(i)) {
      if (a[i] >= 1)
	return false;
    } else if (a[i] >= 2) {
      if (pair || a[i] >= 3)
	return false;
      pair = true;
    }
  }
  return kind == 13;
}

string notation(int i)
{
  ostringstream out;
  if (i < 30)
    out << i % 10 + 1 << "msp"[i / 10];
  else
    out << (i - 30) / 2 + 1 << 'c';
  return out.str();
}

vector<string> ans;

void attempt(int i)
{
  if (a[i] >= 4)
    return;

  ++a[i];
  if (check() || check1() || check2())
    ans.pb(notation(i));
  --a[i];
}

void solve()
{
  ans.clear();

  rep(i, 3) rep(j, 9)
    attempt(i * 10 + j);
  rep(i, 7)
    attempt(30 + 2 * i);

  if (ans.empty()) {
    cout << "Nooten" << endl;
    return;
  }

  cout << ans.size();
  rep(i, ans.size())
    cout << ' ' << ans[i];
  cout << endl;
}

int main()
{
  gen();

  int T;
  cin >> T;
  while (T--) {
    input();
    solve();
  }
    
  return 0;
}
