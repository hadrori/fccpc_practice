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
#define repi(i,a,b) for(int i = (int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i = (int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it = (u).begin(); it!=(u).end(); ++it)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;
#define int ll
const int INF = 1000000000;

struct segtree
{
    int N;
    vector<int> dat;
    segtree(){}
    segtree(int n) {
        N = 1;
        while(N < n) N <<= 1;
        dat.assign(2*N-1,INF);
    }

    void update(int k, int val) {
        k += N-1;
        if(dat[k] <= val) return;
        dat[k] = val;
        while(k > 0) {
            k = (k-1)/2;
            dat[k] = min(dat[k],val);
        }
    }

    // return minimum of [a,b)
    int query(int a, int b) { return query(a,b,0,0,N);}
    int query(int a, int b, int k, int l, int r) {
        if(a >= r or b <= l) return INF;
        if(a <= l and r <= b) return dat[k];
        int m = (l+r)/2;
        return min(query(a,b,2*k+1,l,m),query(a,b,2*k+2,m,r));
    }
};

int n;

void solve2() {
    vector<int> a(2*n), s(2*n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i+n] = a[i];
    
    rep(i, 2*n) s[i] = a[i];
    rep(i, 2*n-1) s[i+1] += s[i];
    
    segtree st(2*n);
    rep(i, 2*n) st.update(i, s[i]);
    
    int ans = 0;
    rep(i, n) {
        if(st.query(i, i+n) + a[i] - s[i] >= 0) ans++;
    }
    cout << ans << endl;

    
}

void solve() {
    vector<int> a(2*n), s(2*n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i+n] = a[i];

    rep(i, 2*n) s[i] = a[i];
    rep(i, 2*n-1) s[i+1] += s[i];

    //segtree st(2*n);
    //rep(i, 2*n) st.update(i, s[i]);
    //rep(i, 2*n) cout << s[i] << " ";
    //cout << endl;
    
    int ans = 0;
    deque<pair<int, int> > v;
    rep(i, 2*n) {
        while(v.size() and v.front().second < i-n) v.pop_front();
        if(v.size()) {
            int val = v.front().first;
            //cout << i << " " << val << endl;
            if(i >= n and val + a[i-n] - s[i-n] >= 0) {
                //cout << i << " " << val << " " << a[i-n] << " " << s[i-n] << endl;
                ans++;
            }
        }

        //if(v.size()) cout << v.back().first << " " << s[i] << endl;
        while(!v.empty() and v.back().first >= s[i]) v.pop_back();
        v.push_back(mp(s[i], i));

        //rep(i, v.size()) cout << v[i].first << " ";
        //cout << endl;
        //if(st.query(i, i+n) + a[i] - s[i] >= 0) ans++;
    }
    cout << ans << endl;
    
}
signed main()
{
    while(cin >> n, n) solve();
    
    return 0;
}
