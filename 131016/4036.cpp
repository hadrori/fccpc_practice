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

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define printv(v) repit(i,v){ cout << *i << endl;}

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

const int N = 1024;

int k, x[N], y[N];

void input()
{
    cin >> k;
    rep(i, k)
	cin >> x[i] >> y[i];
}

struct line
{
    int x, y, num, den;
    line(int x, int y, int num, int den)
	: x(x), y(y), num(num), den(den) {}
    bool operator <(const line &t) const {
	ll d = num * t.den - den * t.num;
	if (d < 0) return true;
	if (d > 0) return false;
	if (den == 0) return x < t.x;
	d = (ll) -num * t.den * x + den * t.den * y
	    - ((ll) -t.num * den * t.x + den * t.den * t.y);
	if (d < 0) return true;
	return false;
    }	
};

ostream& operator <<(ostream &out, line l)
{
    return out << '(' << l.x << ", " << l.y << ") " << l.num << "/" << l.den << endl;
}

void solve()
{
    map<line, int> m;
    rep(i, k) repi(j, i + 1, k)
	++m[line(x[i], y[i], y[j] - y[i], x[j] - x[i])];
    map<int, int> ans;
    repit(it, m) {
	// cerr << it->first << " -> " << it->second << endl;
	++ans[(int) sqrt(2 * it->second) + 1];
    }
    cout << ans.rbegin()->first << ' ' << ans.rbegin()->second << endl; 
}

int main()
{
    int T; cin >> T;
    while (T --> 0) {
	input();
	solve();
    }

    return 0;
}


