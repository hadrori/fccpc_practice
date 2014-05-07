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
    int N, n, m;
    entry(int N, int n, int m) : N(N), n(n), m(m) {}
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

long calc(long n, long m)
{
    m = min(m, n - m);

    long a = n - 2 * (m - 1) - 1;
    return m * a + m * (m - 1) + 1;
}

void solve()
{
    rep(i, P) {
        cout << V[i].N << ' ' << calc(V[i].n, V[i].m) << endl;
    }
}

int main()
{
    input();
    solve();

    return 0;
}
