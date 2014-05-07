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

const int N = 100010;
const long long inf = 1e16;

int n;
long long a[N][5];

void input()
{
    rep(i, n) {
        a[i][0] = a[i][4] = inf;
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    }
}

const int di[] = {-1, -1, -1, 0};
const int dj[] = {-1, 0, 1, -1};

void solve()
{
    a[0][1] = inf;
    a[0][3] += a[0][2];
    repi(i, 1, n) repi(j, 1, 4) {
        long long prev = inf;
        rep(dir, 4) prev = min(prev, a[i + di[dir]][j + dj[dir]]);
        a[i][j] += prev;
    }
    cout << a[n - 1][2] << endl;
}

int main()
{
    int cnt = 0;
    while (cin >> n && n) {
        input();
        cout << ++cnt << ". ";
        solve();
    }

    return 0;
}
