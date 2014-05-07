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

#define repi(i,a,b) for(int i=(a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a); i>=(b); i--)
#define repit(i,a) for(typeof((a).begin()) i=(a).begin(); i != (a).end(); i++)

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

set<string> ans;

struct node
{
    int a, b, v;
    node(int a, int b, int v) : a(a), b(b), v(v) {}
    bool operator <(const node &t) const {
	return a < t.a || a == t.a && (b < t.b || b == t.b && v < t.v);
    }
};

map<node, string> mem;

void trace(ostringstream &out, int a, int b, int *v)
{
    int v1 = *v;
    if (mem.find(node(a, b, v1)) != mem.end())
	return;

    ostringstream inner;
    if (a <= 2) {
	*v = b + 1;
	inner << "1 2 3 15 ";
    } else if (a > b) {
	++*v;
	inner << "1 2 4 5 6 9 12 13 ";
	trace(inner, a - 3, *v, v);
	inner << "14 15 ";
    } else {
	--*v;
	inner << "1 2 4 5 7 8 9 10 ";
	trace(inner, a - 1, b, v);
	inner << "11 ";
	trace(inner, a - 2, *v, v);
	inner << "14 15 ";
    }
    mem[node(a, b, v1)] = inner.str();
    out << inner.str();
}

void attempt(ostringstream &out, int x, int y, int *z)
{
    out << "16 17 18 19 20 ";
    trace(out, x, y, z);
    out << "21";
}

void gen()
{
    rep(x, 21) rep(y, 101) {
	int z = 1567125216;
	ostringstream out;
	attempt(out, x, y, &z);
	if (out.str().length() <= 65536)
	    ans.insert(out.str());
    }
}

int main()
{
    gen();

    int N;
    cin >> N;
    cin.ignore();
    while (N--) {
	string line;
	getline(cin, line);
	cout << (ans.find(line) != ans.end() ? "feasible" : "infeasible") << endl;
    }

    return 0;
}
