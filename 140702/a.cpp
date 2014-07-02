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

const int N = 256;

int n, x[N], y[N];

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void solve()
{
    int mx = 0, my = 0, Mx = 0, My = 0;

    x[0] = y[0] = 0;
    repi(i, 1, n) {
        int a, d;
        cin >> a >> d;
        x[i] = x[a] + dx[d];
        mx = min(mx, x[i]);
        Mx = max(Mx, x[i]);
        y[i] = y[a] + dy[d];
        my = min(my, y[i]);
        My = max(My, y[i]);
    }

    cout << Mx - mx + 1 << ' ' << My - my + 1 << endl;
}

int main()
{
    while (cin >> n and n) {
        solve();
    }

    return 0;
}
