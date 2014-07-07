#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) repi(i,0,n)

typedef unsigned long long hash;

string line;

#define repit(it,u) for(__typeof(u.begin()) it=u.begin();it!=u.end();++it)
#define mp make_pair

const hash p = 1e9 + 7;
int strnum;
int idnum;
map<pair<int, int>, int> par;
map<pair<int, int> ,bool> comp;
struct node
{
  set<hash> s;
  node *l, *r;
  int num, den;
  int id;
  node() : s(), l(NULL), r(NULL), num(0), den(1) { id = idnum++;}
  node(node *l, node *r) : s(), l(l), r(r), num(0), den(1) { id = idnum++;}
  void calc() {
    if (l == NULL) {
      s.insert(1ULL);
    } else {
      l->calc();
      r->calc();
      repit(itl, l->s) repit(itr, r->s) {
	pair<int, int> key = mp(min(*itl, *itr), max(*itl, *itr));
	if(par.find(key) == par.end()) par[key]= strnum++;
	s.insert(par[key]);
      }
    }
  }
  void calc1() {
    if (l == NULL) return;

    l->calc1();
    r->calc1();

    repit(it, l->s) s.insert(*it);
    repit(it, r->s) s.insert(*it);

    set<hash> u;
    repit(it, l->s) u.insert(*it);
    repit(it, r->s) u.insert(*it);

    num = 0;
    repit(it, l->s) if (r->s.find(*it) != r->s.end()) {
      ++num;
    }
    den = u.size();
  }
  void rearrange(bool flip) {
    if (l == NULL) return;
    if (*l < *r ^ flip) {
      swap(l, r);
    }
    l->rearrange(false);
    r->rearrange(true);
  }
  void dump() {
    //cout << (double)num << ',' << den;
    if (l == NULL) {
      cout << 'x';
      return;
    }
    cout << '(';
    l->dump();
    cout << ' ';
    r->dump();
    cout << ')';
  }
  bool operator !=(const node& t) const {
    return *this < t or t < *this;
  }
  bool operator <(const node& t) const {
    bool ret;
    if(comp.find(mp(id, t.id)) != comp.end()) return comp[mp(id, t.id)];
    if (num * t.den != den * t.num) ret = num * t.den > den * t.num;
    else if (l == NULL or t.l == NULL) ret = false;
    else if (max(*l, *r) != max(*(t.l), *(t.r))) ret = max(*l, *r) < max(*(t.l), *(t.r));
    else if (min(*l, *r) != min(*(t.l), *(t.r))) ret = min(*l, *r) < min(*(t.l), *(t.r));
    else ret = false;
    return comp[mp(id, t.id)] = ret;
  }
};

node *get(int i, int& next)
{
  if (line[i] == '(') {
    node *l = get(i + 1, next);
    node *r = get(next + 1, next);
    next += 1;
    return new node(l, r);
  }

  next = i + 1;
  return new node();
}

void solve()
{
  int dummy;
  node *root = get(0, dummy);
  root->calc();
  root->calc1();
  root->rearrange(false);
  root->dump();
  cout << endl;
}

int main()
{
  int cnt = 0;
  while (getline(cin, line) and line[0] != '0') {
    //cerr << ++cnt << endl;
    comp.clear();
    par.clear();
    solve();
  }

  return 0;
}
