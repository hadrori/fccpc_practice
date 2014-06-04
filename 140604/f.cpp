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

const int N = 1024;

int n;
ll s, pm[N];

inline int nextInt() { int n; scanf("%d", &n); return n; }

int main()
{
    int cnt = 0;
    while (n = nextInt()) {
        s = 0;
        fill(pm, pm + n, 0LL);

        rep(i, n) rep(j, n) {
            int a = nextInt();
            s += a;
            pm[i] -= a;
            pm[j] += a;
        }

        ll ans = 0;
        rep(i, n) ans += abs(pm[i]);

        printf("%d. %lld %lld\n", ++cnt, s, ans >> 1);
    }

    return 0;
}
