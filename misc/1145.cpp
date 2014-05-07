#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#define rep(i,a) for(int i = 0;i < a; i++)

using namespace std;

struct expr;

struct term
{
  bool flg;
  string str;
  int n;
  expr *inner;

  term(bool flg, string str, int n, expr *inner);
  int length();
  char charAt(int pos);
};

struct expr
{
  vector<term> inner;

  expr(vector<term> inner) : inner(inner) {}

  int length() {
    int ret = 0;
    for (int i = 0; i < inner.size(); ++i)
      ret += inner[i].length();
    return ret;
  }

  char charAt(int pos) {
    int cur = 0;
    for (int i = 0; i < inner.size(); ++i) {
      int next = cur + inner[i].length();
      if (pos < next)
	return inner[i].charAt(pos - cur);
      cur = next;
    }
    return '0';
  }
};

term::term(bool flg, string str, int n, expr *inner)
  : flg(flg), str(str), n(n), inner(inner) {}

int term::length() {
  return flg ? min((long long) n * inner->length(), 100000000LL) : str.length();
}

char term::charAt(int pos) {
  return flg ? inner->charAt(pos % inner->length()) : str[pos];
}

int parsenum(string s, int pos, int& next)
{
  int ret = 0;
  while ('0' <= s[pos] && s[pos] <= '9') {
    ret *= 10;
    ret += s[pos] & 15;
    ++pos;
  }
  next = pos;
  return ret;
}

expr *parseexpr(string s, int pos, int& next);

term parseterm(string s, int pos, int& next)
{
  if ('0' <= s[pos] && s[pos] <= '9') {
    int n = parsenum(s, pos, next);
    if (s[next] == '(') {
      expr *inner = parseexpr(s, next + 1, next);
      ++next;
      return term(true, "", n, inner);
    } else {
      string str;
      str.push_back(s[next]);
      vector<term> inner;
      inner.push_back(term(false, str, 0, NULL));
      ++next;
      return term(true, "", n, new expr(inner));
    }
  } else {
    string ret;
    while ('A' <= s[pos] && s[pos] <= 'Z') {
      ret.push_back(s[pos]);
      ++pos;
    }
    next = pos;
    return term(false, ret, 0, NULL);
  }
}

expr *parseexpr(string s, int pos, int& next)
{
  vector<term> ret;
  while (pos < s.length() && s[pos] != ')') {
    term inner = parseterm(s, pos, next);
    ret.push_back(inner);
    pos = next;
  }
  return new expr(ret);
}

void solve(string s, int i)
{
  int dummy;
  expr *e = parseexpr(s, 0, dummy);
  cout << e->charAt(i) << endl;
}

int main()
{
  string s;
  int i;
  while (cin >> s >> i && s[0] != '0')
    solve(s, i);

  return 0;
}
