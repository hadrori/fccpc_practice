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

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 10010;

int n = 0, pre[N];

int post(int i, int mn, int mx)
{
    if (pre[i] <= mn or mx <= pre[i]) return i;

    int ret = i + 1;
    ret = post(ret, mn, min(mx, pre[i]));
    ret = post(ret, max(mn, pre[i]), mx);
    cout << pre[i] << endl;
    return ret;
}

int main()
{
    int e;
    while (cin >> e) pre[n++] = e;

    post(0, 0, 1000000);

    return 0;
}
