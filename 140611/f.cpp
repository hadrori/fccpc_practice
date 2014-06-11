#include <algorithm>
#include <bitset>
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

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vector<ll> a;
const int MAX = 100006;
ll bit[MAX];
int n, m;

void add(int k, ll x) {
    while(k <= n) {
        bit[k] += x;
        k += k&-k;
    }
}

ll sum(int k) {
    ll ret = 0;
    while(k) {
        ret += bit[k];
        k -= k&-k;
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    a.resize(n);
    rep(i, n) cin >> a[i];
    int rtn = 317;
    vector<priority_queue<pair<ll, int> > > pqv(rtn);
    rep(i, n) {
        add(i+1, a[i]);
        pqv[(i+1)/rtn].push(mp(a[i], i+1));
    }
    
    rep(i, m) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r;
            cin >> l >> r;
            cout << sum(r) - sum(l-1) << endl;
        } else if(type == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            ll val;
            repi(j, l/rtn, r/rtn+1) {
                priority_queue<pair<ll, int> > &pq = pqv[j];
                vector<pair<ll, int> > tmp;
                while(pq.size() && (val = pq.top().first) >= x) {
                    int idx = pq.top().second;
                    pq.pop();
                    ll nval = val%x;
                    if(idx < l || idx > r) nval = val;
                    add(idx, nval-val);
                    tmp.pb(mp(nval, idx));
                }
                repit(itr, tmp) pq.push(*itr);
            }

        } else {
            ll k, x;
            cin >> k >> x;
            ll val = sum(k) - sum(k-1);
            priority_queue<pair<ll, int> > &pq = pqv[k/rtn];
            vector<pair<ll, int> > tmp;
            while(pq.size()) {
                int idx = pq.top().second;
                int val = pq.top().first; pq.pop();
                if(idx == k) {
                    val = x;
                    tmp.pb(mp(val, idx));
                    break;
                }
                tmp.pb(mp(val, idx));
            }
            repit(itr, tmp) pq.push(*itr);
                
            add(k, x-val);
        }
        /*
        cout << i << " : ";
        rep(j, n) {
            cout << sum(j+1) - sum(j) << ' ';
        }
        cout << endl;
        */
    }

    return 0;
}
