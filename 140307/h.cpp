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

struct entry
{
    int N, n, k;
    entry(int N, int n, int m) : N(N), n(n), k(m) {}
    bool operator <(const entry &t) const {
        return N < t.N;
    }
};

int P;
vector<entry> V;

void input()
{
    cin >> P;
    rep(i, P) {
        int N, n, m;
        cin >> N >> n >> m;
        V.pb(entry(N, n, m));
    }
    sort(all(V));
}

const int mm = 24;

long fact[mm] = {1};
long binom[mm][mm] = {1};

void gen()
{
    repi(i, 1, mm) {
        fact[i] = fact[i - 1] * i;
    }
    repi(i, 1, mm) {
        binom[i][0] = 1;
        repi(j, 1, i + 1) {
            binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
        }
    }
}

long calc(long n, long k)
{
    if (k == 1) return fact[n - 1];

    long ret = 0;
    rep(i, k - 1) {
        ret += binom[k - 2][i] * fact[i + 1] * fact[n - i - 2];
    }
    return ret;
}

void solve()
{
    gen();

    rep(i, P) {
        cout << V[i].N << ' ' << calc(V[i].n, V[i].k) << endl;
    }
}

int main()
{
    input();
    solve();

    return 0;
}
