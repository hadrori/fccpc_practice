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

typedef unsigned long long ll;

ll calc(ll n, ll m)
{
    const ll t = min(n,m)/2, t1 = t+1, t2= 2*t+1;
    return t*(6*t*t1*t1+3*(2*n+2*m+n*m+3)*t1-2*(n+m+3)*t1*t2-3*(n+m+n*m+1))/3;
}

int main()
{
    ll n, m;
    while(scanf("%lld%lld", &n, &m), n or m) {
        printf("%lld\n", calc(n+1,m+1));
    }
    return 0;
}
