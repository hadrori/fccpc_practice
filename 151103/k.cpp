#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair

string s;
long x;

void input() {
    cin >> s >> x;
}

const int N = 40010;
const string WRG = "WRG";

int n, a[N];

void shift(long k) {
    static int tmp[N];
    k %= n;
    copy_n(a, n, tmp);
    for (int i = n-1; i >= 0; --i) {
        tmp[i] += a[(i+k)%n];
        if (tmp[i] >= 3) tmp[i] -= 3;
    }
    copy_n(tmp, n, a);
}

void solve() {
    n = s.length();
    rep(i, n) a[i] = WRG.find(s[i]);
    for (long k = 1; x; k *= 3, x /= 3) {
        rep(_, x % 3) shift(k);
    }
    rep(i, 3) {
        cout << ' ' << count(a, a + n, i);
    }
    cout << endl;
}

int main() {
    cout << fixed << setprecision(12);
    int t; cin >> t;
    rep(i,t) {
        cout << "Case #" << i+1 << ":";
        input();
        solve();
    }
    return 0;
}
