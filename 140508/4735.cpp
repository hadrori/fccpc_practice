#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>ago
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

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

int p, q;

void solve()
{
    set<int> s;
    map<int, int> m;

    for (int i = 2; i * i <= p; ++i) {
        int e = 0;
        while (p % i == 0) p /= i, ++e;
        if (e) s.insert(i);
        m[i] += e;
    }
    if (p > 1) s.insert(p), ++m[p];

    for (int i = 2; i * i <= q; ++i) {
        int e = 0;
        while (q % i == 0) q /= i, ++e;
        if (e) s.insert(i);
        m[i] -= e;
    }
    if (q > 1) s.insert(q), --m[q];

    int d = 0;
    repit(it, m) {
        d += abs(it->second);
    }
    cout << s.size() << ':' << d << endl;
}

int main()
{
    int cnt = 0;
    while (cin >> p >> q && p) {
        cout << ++cnt << ". ";
        solve();
    }

    return 0;
}
