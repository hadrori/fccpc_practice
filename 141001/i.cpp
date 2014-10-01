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

const int N = 100010;

int c[N];

void prepare()
{
    for (int i = 2; i * i < N; ++i) {
        if (not c[i]) {
            for (int j = i * i; j < N; j += i) {
                c[j] = true;
            }
        }
    }
}       

int parseInt(string s)
{
    int ret = 0;
    rep(i, s.length()) {
        ret *= 10, ret += s[i] & 15;
    }
    return ret;
}

string line;

int main()
{
    prepare();

    while (cin >> line and line != "0") {
        const int len = line.length();

        int ans = 0;
        repi(i, 1, 6) rep(j, len - i + 1) {
            const int p = parseInt(line.substr(j, i));
            if (not c[p]) {
                ans = max(ans, p);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
