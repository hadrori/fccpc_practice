#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair

unsigned rotl(unsigned n) {
    return n << 1 | n >> 31;
}

unsigned rotr(unsigned n) {
    return n >> 1 | (n&1) << 31;
}

const int inf = 100;

int ll(unsigned a, unsigned b) {
    rep(i, 32) {
        if (a == b) return i;
        a = rotl(a);
    }
    return inf;
}

int rr(unsigned a, unsigned b) {
    rep(i, 32) {
        if (a == b) return i;
        a = rotr(a);
    }
    return inf;
}

unsigned a, b;

void solve() {
    int l = ll(a, b);
    int r = rr(a, b);
    if (l < r) {
        cout << l << " Left" << endl;
    } else if (l > r) {
        cout << r << " Right" << endl;
    } else if (l == inf) {
        cout << "Not possible" << endl;
    } else {
        cout << l << " Any" << endl;
    }
}

void input() {
    cin >> hex >> a >> b >> dec;
}

int main() {
    cout << fixed << setprecision(12);
    int t; cin >> t;
    rep(i,t) {
        cout << "Case #" << i+1 << ": ";
        input();
        solve();
    }
    return 0;
}
