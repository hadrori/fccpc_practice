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
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;

int n;
string ans;

void solve(int n)
{
    if (n == 1) {
        ans.pb(48);
        return;
    }

    int d = 0;
    for (int t = n; t; t >>= 1) {
        ++d;
        ans.pb(48 | (t & 1));
    }
    if (d >= 2) solve(d - 1);
}

int main()
{
    while (cin >> n and n) {
        ans.clear();
        solve(n);
        reverse(all(ans));
        cout << ans << endl;
    }

    return 0;
}
