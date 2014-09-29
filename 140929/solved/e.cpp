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

vector<ll> dat;

void add(int k, int x) {
    while(k < dat.size()) {
        dat[k] += x;
        k += k&-k;
    }
}

ll sum(int k) {
    ll ret = 0;
    while(k) {
        ret += dat[k];
        k -= k&-k;
    }
    return ret;
}

ll solve() {
    ll n, k;
    cin >> n >> k;
    dat.clear(); dat.resize(n+1);
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    rep(i, n) v[i] = (v[i]-1)/k;
    ll a1 = 0, a2 = 0;
    rep(i, n) {
        a1 += sum(n-v[i]-1);
        add(n-v[i], 1);
    }

    vector<int> num(n);
    rep(i, n) {
        a2 = max(a2, abs((k*v[i] + num[v[i]]) - i));
        num[v[i]]++;
    }
    return a1 - a2;
}

int main()
{
    int T;
    cin >> T;
    rep(i, T) {
        cout << "Case " << i+1 << ": " << solve() << endl;
    }
    
    return 0;
}
