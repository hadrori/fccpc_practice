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

const int base = 405;

int n, a[405][810];

void input()
{
    memset(a, 0, sizeof(a));
    rep(i, n) repi(j, -i, i + 1) {
        cin >> a[i][base + j];
    }
    rep(i, n) repi(j, -i, i + 1) {
        a[i][base + j] += a[i][base + j - 1];
    }
}

int solve()
{
    int ans = -1e9;
    rep(i, n) repi(j, -i, i + 1) {
        const int dk = i + j & 1 ? -1 : 1;

        int k = i, l = j - 1, r = j;
        int val = a[k][base + r] - a[k][base + l];
        while (k < n) {
            // cerr << k << ',' << val << ' ';
            ans = max(ans, val);
            k += dk, --l, ++r;
            if (l < -k - 1 or k < r) break;
            val += a[k][base + r] - a[k][base + l];
        }
        // cerr << endl;
    }
    return ans;
}

int main()
{
    int k = 0;
    while (cin >> n and n) {
        input();
        cout << ++k << ". " << solve() << endl;
    }

    return 0;
}
