#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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

using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i = (int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i = (int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it = (u).begin(); it!=(u).end(); ++it)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 500010;

int n, b, a[N];

bool input()
{
    cin >> n >> b;
    if (n < 0) return false;
    rep(i, n) cin >> a[i];
    return true;
}

bool attempt(int m)
{
    int s = 0;
    rep(i, n) s += (a[i] - 1) / m + 1;
    return s <= b;
}

void solve()
{
    int l = 0, r = int(1e9);
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (attempt(m)) r = m;
        else l = m;
    }
    cout << r << endl;
}

int main()
{
    while (input()) solve();

    return 0;
}
