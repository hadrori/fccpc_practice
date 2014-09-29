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

const int N = 128;
const int M = 300;

int n, w[N], dp[M] = {1};

int main()
{
    cin >> n;
    rep(i, n) cin >> w[i], w[i] /= 100;

    int s = 0;
    rep(i, n) s += w[i];

    if (s & 1) {
        cout << "NO" << endl;
        return 0;
    }

    rep(i, n) {
        for (int j = w[i]; j < M; ++j) {
            dp[j] |= dp[j - w[i]];
        }
    }

    if (dp[s / 2]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
