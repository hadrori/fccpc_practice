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

const int ind[] = {
    0, 1, 2,
    5, 6, 7, 8,
    10, 11, 12, 13, 14,
    16, 17, 18, 19,
    22, 23, 24
};

int embed[25];

void prepare()
{
    rep(i, 5) rep(j, 5) {
        embed[i * 5 + j] = 1 << (4 - i * 2 + j * 3);
    }
}

char line[150];

int masked[25], filtered[25];

int fun(int* a, int i)
{
    int ret = a[i - 6] | a[i - 5] | a[i - 1] | a[i] | a[i + 1] | a[i + 5] | a[i + 6];
    return line[ret / embed[i - 1]] & 1;
}

#define filter(i) (filtered[i] = embed[i] & -fun(masked, i))

bool solve()
{
    rep(S, 1 << 19) {
        rep(i, 19) masked[ind[i]] = embed[ind[i]] & -(S >> i & 1);
        filter(6);
        filter(7);
        filter(11);
        filter(12);
        filter(13);
        filter(17);
        filter(18);
        if (!!filtered[12] != fun(filtered, 12)) return false;
    }
    return true;
}

int main()
{
    prepare();

    while (cin >> line and line[0] != '#') {
        cout << (solve() ? "yes" : "no") << endl;
    }

    return 0;
}
