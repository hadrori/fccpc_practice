#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a%b);
}

// a x + b y = gcd(a, b)
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g; // 1なら解あり
}

ll solve_t(ll a, ll b, ll c) {
    if (a < c and b < c) return -1;
    
    ll g = gcd(a, b);
    a /= g;
    b /= g;    
    if (c % g != 0) return -1;
    c /= g;
    
    ll x, y;
    extgcd(a, b, x, y);
    x *= c;
    y *= c;

    ll t1 = -x / b - 1;
    while (t1 * b < -x) t1++;
    
    ll t2 = y / a - 1;
    while (t2 * a < y) t2++;
    
    ll t = max(t1, t2);
    
    ll ax = x + t * b;
    ll ay = y - t * a;
    //cout << x << " " << y << " " << t << endl;
    ll ans = 2 * ax - ay * 2;
    // if ((ax*a) / b != ((ax-1)*a) / b) ans--;
    return ans;
}


ll solve(ll a, ll b, ll c) {
    if (c == 0) {
        return 0;
    }
    if (c == a or c == b) {
        return 1;
    }
    
    ll ans = min(solve_t(a, b, c), solve_t(b, a, c));
    if (a >= c) ans = min(ans, solve_t(b, a, a-c));
    if (b >= c) ans = min(ans, solve_t(a, b, b-c));
    return ans;
}

ll solve_naive(ll a, ll b, ll c) {
    struct node {
        ll av, bv;
        int cst;
        node(ll av, ll bv, int cst) : av(av), bv(bv), cst(cst) {}
    };

    set<ll> done;
    
    queue<node> q;
    q.push(node(0, 0, 0));
    while(q.size()) {
        node nd = q.front(); q.pop();
        
        ll key = nd.av * (b+1) + nd.bv;
        if (done.find(key) != done.end()) continue;
        done.insert(key);
        if (nd.av == c or nd.bv == c) {
            return nd.cst;
        }
        
        q.push(node(0, nd.bv, nd.cst+1));
        q.push(node(nd.av, 0, nd.cst+1));

        q.push(node(a, nd.bv, nd.cst+1));
        q.push(node(nd.av, b, nd.cst+1));
        if (nd.av + nd.bv <= a) q.push(node(nd.bv + nd.av, 0, nd.cst+1));
        else q.push(node(a, nd.bv - (a - nd.av), nd.cst+1));
        if (nd.av + nd.bv <= b) q.push(node(0, nd.bv + nd.av, nd.cst+1));
        else q.push(node(nd.av - (b - nd.bv), b, nd.cst+1));
    }
    return -1;
}

void gen() {
    cout << 100000000 << endl;
    repi(a, 1, 100) repi(b, 1, 100) repi(c, 1, 100)
        cout << a << " " << b << " " << c << endl;
}

int main()
{
    /*
    gen();
    return 0;
    */
    int T;
    cin >> T;
    rep(t, T) {
        ll a, b, c;
        cin >> a >> b >> c;
        
        // cout << a << " " << b << " " << c << endl;
        cout << solve(a, b, c) << endl;
        // cout << solve_naive(a, b, c) << endl;
        /*
        if (solve(a, b, c) != solve_naive(a, b, c)) {
            cerr << "error" << endl;
            return 1;
            }*/

    }
    return 0;
}

