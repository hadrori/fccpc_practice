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

const int N = 10010;
const int mod = 10001;

int n, x[N];

void input()
{
    cin >> n;
    rep(i, n) cin >> x[i];
}

int minv(int x, int m)
{
    if (x == 0) return -1;
    if (x == 1) return 1;
    if (minv(m % x, m) < 0) return -1;

    return (m - m / x) * minv(m % x, m) % m;
}

int next(int a, int b, int x)
{
    return (a * x + b) % mod;
}

bool attempt(int a)
{
    const int c = (a + 1) % mod;
    const int d = ((x[1] - (ll) a * a * x[0]) % mod + mod) % mod;
    int m = mod;

    if (c % 73 == 0) {
        if (d % 73 != 0) return false;
        m /= 73;
    }
    if (c % 137 == 0) {
        if (d % 137 != 0) return false;
        m /= 137;
    }
    if (minv(c, m) < 0) return false;

    const int b = (minv(c, m) * d) % mod;

    rep(i, n - 1) {
        if (next(a, b, next(a, b, x[i])) != x[i + 1]) {
            return false;
        }
    }

    rep(i, n) {
        cout << next(a, b, x[i]) << endl;
    }
    return true;
}

void solve()
{
    rep(a, 10001) {
        if (attempt(a)) break;
    }
}

int main()
{
    input();
    solve();

    return 0;
}
