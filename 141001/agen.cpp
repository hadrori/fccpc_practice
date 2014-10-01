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

int main()
{
    const int n = 4;
    const int m = 4;
    cout << (1<<(n*m)) << endl;
    
    rep(S, (1<<(n*m))) {
        cout << n << " " << m << endl;
        rep(i, n) {
            rep(j, m) cout << ((S>>(i*n+j))&1);
            cout << endl;
        }
    }

    return 0;
}
