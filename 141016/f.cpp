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

const int N = 1000100;

int c[N], p[N] = {0, 0};
int mx[N] = {0};

void prepare()
{
    for (int i = 2; i * i < N; ++i) {
        if (c[i] == 0) {
            for (int j = i * i; j < N; j += i) {
                c[j] = i;
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        if (c[i] == 0) {
            p[i] = 1;
        } else {
            p[i] = p[i / c[i]] + 1;
        }
    }
    for (int i = 2; i < N; ++i) {
        if (p[i] == 1) {
            p[i] = -1;
        }
    }
    for (int i = 1; i < N; ++i) {
        p[i] += p[i - 1] - 1;
    }
    for (int i = 1; i < N; ++i) {
        mx[i] = max(mx[i - 1], p[i]);
    }
    int tt = 25;
    for (int i = tt; i < N; ++i) {
        assert(mx[i - tt] < p[i]);
    }
}

int a, b;

const int k = 25;

void solve()
{
    --a;
    int ans = p[b] - p[a];
    rep(i, k) rep(j, k) {
        int l = a + i;
        int r = b - j;
        if (l >= r) continue;
        ans = max(ans, p[r] - p[l]);
    }
    cout << ans << endl;
}

int main()
{
    prepare();

    int t = 0;
    while (cin >> a >> b and a != -1) {
        cout << ++t << ". ";
        solve();
    }

    return 0;
}
