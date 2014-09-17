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

string line;

void solve()
{
    vector<char> v;
    {
        int pos = 0;
        while (pos < line.length()) {
            v.pb(line[pos]);
            if (line[pos] == 'n') {
                pos += 5;
            } else {
                pos += 4;
            }
        }
    }
    const int n = v.size();

    ll ans = v.back() == 'n' ? 0 : 90;
    for (int i = n - 2; i >= 0; --i) {
        ans *= 2;
        if (v[i] == 'n') {
            ans -= 90;
        } else {
            ans += 90;
        }
    }
    ll num = ans, den = 1LL << (n - 1);
    {
        const ll g = __gcd(num, den);
        num /= g, den /= g;
    }
    cout << num;
    if (den > 1) cout << '/' << den;
    cout << endl;
}

int main()
{
    while (cin >> line and line[0] != '#') {
        solve();
    }

    return 0;
}
