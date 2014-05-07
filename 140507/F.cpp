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

const int N = 64;

int n;
double x, y, z, a[N], b[N], c[N];

void input()
{
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
}

double get(double p, double q, double r)
{
    double ret = 1e16;
    rep(i, n) {
        ret = min(ret, max(max(abs(p - a[i]), abs(q - b[i])), abs(r - c[i])));
    }
    return ret;
}

int solve()
{
    double ret = 0.0;
    rep(i, 8) {
        ret = max(ret, get(
                      i & 4 ? x : 0.0,
                      i & 2 ? y : 0.0,
                      i & 1 ? z : 0.0
                      ));
    }
    rep(i, n) repi(j, i + 1, n) {
        ret = max(ret, get((a[i] + a[j]) * 0.5,
                           (b[i] + b[j]) * 0.5,
                           (c[i] + c[j]) * 0.5));
    }
    return int(ret * 2 + 0.5);
}

int main()
{
    int cnt = 0;
    while (cin >> n >> x >> y >> z && n) {
        input();
        cout << ++cnt << ". " << solve() << endl;
    }

    return 0;
}
