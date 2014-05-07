#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

struct ev
{
    virtual set<int> eval() = 0;
};

struct num : public ev
{
    int n;
    set<int> ed;

    num(int n) : n(n), ed() {
        ed.insert(n);
    }

    set<int> eval() {
        return ed;
    }
};

struct expr : public ev
{
    vector<char> op;
    vector<ev*> inner;
    vector<set<int> > ed;

    expr() : op(), inner(), ed() {}

    ~expr() {
        rep(i,(int)inner.size())
            delete inner[i];
    }

    set<int> eval() {
        rep(i,(int)inner.size())
            ed.pb(inner[i]->eval());

        return recur(0, inner.size());
    }

    set<int> recur(int a, int b) {
        if (a + 1 == b)
            return ed[a];

        set<int> ret;
        for (int i = a + 1; i < b; ++i) {
            set<int> lhs = recur(a, i);
            set<int> rhs = recur(i, b);
            repit(it1,lhs) {
                repit(it2,rhs) {
                    switch (op[i - 1]) {
                    case '+':
                        ret.insert(*it1 + *it2);
                        break;
                    case '-':
                        ret.insert(*it1 - *it2);
                        break;
                    case '*':
                        ret.insert(*it1 * *it2);
                        break;
                    case '/':
                        if (*it2 != 0)
                            ret.insert(*it1 / *it2);
                        break;
                    }
                }
            }
        }
        return ret;
    }
};

ev *parseTerm(const string &s, int pos, int &next);

expr *parseExpr(const string &s, int pos, int &next)
{
    expr *ret = new expr();
    while (pos < (int) s.length()) {
        ev *term = parseTerm(s, pos, pos);
        ret->inner.pb(term);
        char op = s[pos];
        if (op == ')')
            break;
        ret->op.pb(op);
        ++pos;
    }
    next = pos;
    return ret;
}

ev *parseTerm(const string &s, int pos, int &next)
{
    if (s[pos] == '(') {
        ev *inner = parseExpr(s, pos + 1, next);
        ++next;
        return inner;
    }

    int ret = 0;
    while (pos < (int) s.length() && '0' <= s[pos] && s[pos] <= '9') {
        ret *= 10;
        ret += s[pos] & 15;
        ++pos;
    }
    next = pos;
    return new num(ret);
}

int main()
{
    string line;
    while (cin >> line && line[0] != '#') {
        int dummy;
        expr *expr = parseExpr(line, 0, dummy);

        cout << expr->eval().size() << endl;
    }

    return 0;
}
