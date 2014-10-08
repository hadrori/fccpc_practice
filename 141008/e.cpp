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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> lst(n+1, -1);
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    bool ok = true;
    vector<int> ans(m, 0);
    vector<int> from(m, -1);
    set<int> st;
    rep(i, m) {
        if(a[i] == 0) st.insert(i);
        else {
            set<int>::iterator itr = st.lower_bound(lst[a[i]]);
            if(itr == st.end()) {
                ok = false;
                break;
            }
            from[i] = *itr;
            lst[a[i]] = i;
            st.erase(itr);
        }
    }
    rep(i, m) if(from[i] >= 0) ans[from[i]] = a[i];
    if(ok) {
        cout << "YES" << endl;
        bool flag = false;
        rep(i, m) {
            if(a[i] == 0) {
                if(flag) cout << " ";
                flag = true;
                cout << ans[i];
            }
        }
        cout << endl;
    } else cout << "NO" << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(i, T) solve();
    return 0;
}
