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
const int MAX = 10000007;
bool prime[MAX];
void gen() {
    repi(i, 2, MAX) prime[i] = true;
    rep(i, MAX) if(prime[i]) {
        for(int j = i*2; j < MAX; j += i) prime[j] = false;
    }
}

void solve() {
    string s;
    cin >> s;
    vector<int> v;
    rep(i, s.size()) v.pb(s[i]-'0');
    sort(all(v));
    set<int> ans;

    rep(S, 1<<s.size()) {
        vector<int> tv;
        rep(i, v.size()) if((S>>i)&1) tv.pb(v[i]);
        do {
            int num = 0;
            rep(i, tv.size()) {
                num *= 10;
                num += tv[i];
            }
            if(prime[num]) ans.insert(num);
        } while(next_permutation(all(tv)));
    }
    cout << ans.size() << endl;
}

int main()
{
    gen();
    int T;
    cin >> T;
    rep(i, T) solve();
    return 0;
}
