#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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

using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i = (int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i = (int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it = (u).begin(); it!=(u).end(); ++it)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;

ll n, m;
vector<ll> a;
string line;

bool input()
{
    cin >> n;
    if (n == 0) return false;
    a.resize(n);
    rep(i, n) cin >> a[i];
    cin >> m >> line;
    return true;
}

string var;

void prepare()
{
    var.clear();
    rep(i, line.length()) {
        if (isalpha(line[i])) {
            var.pb(line[i]);
        }
    }
    sort(all(var));
    uniq(var);
}

ll parse(int& pos)
{
    char c = line[pos];
    if (isalpha(c)) {
        ++pos;
        return a[var.find(c)];
    }
    if (c == '(') {
        ++pos;
        ll lhs = parse(pos);
        char op = line[pos++];
        ll rhs = parse(pos);
        ++pos;
        if (op == '+') return lhs + rhs;
        else if (op == '-') return lhs - rhs;
        else return lhs * rhs;
    }
    assert(false);
    return -1;
}

void solve()
{
    prepare();

    sort(all(a));
    do {
        int pos = 0;
        pos = 0;
        if (parse(pos) == m) {
            cout << "YES" << endl;
            return;
        }
    } while (next_permutation(all(a)));
    cout << "NO" << endl;
}

int main()
{
    while (input()) solve();

    return 0;
}
