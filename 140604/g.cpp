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

ll n, r, s, e;

// [top, top + size) * [left, left + size)

ll recur(ll top, ll left, ll size)
{
    if (r < top or top + size <= r) return 0;
    if (e <= left or left + size <= s) return 0;
    if (size == 1) return 1;

    const ll half = size >> 1;

    ll ret = 0;
    if (top <= r and r < top + half) {
        ret += recur(top, left, half);
        ret += recur(top, left + half, half);
    } else {
        ret += recur(top + half, left, half);
        ret -= recur(top + half, left + half, half);
    }
    return ret;
}

void solve()
{
    cout << recur(0, 0, 1LL << n) << endl;
}

int main()
{
    while (cin >> n >> r >> s >> e and n != -1) {
        ++e;
        solve();
    }

    return 0;
}
