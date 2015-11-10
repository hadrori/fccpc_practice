#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define pb push_back
#define all(u) begin(u),end(u)
#define mp make_pair
#define long int64_t

const int N = 128;

int n, x[N], y[N];

void input() {
    rep(i, n) cin >> x[i] >> y[i];
}

double attempt(double th) {
    double a = cos(th), b = sin(th);
    long tx = 0, ty = 0;
    rep(i, n) {
        if (a * x[i] + b * y[i] > 0.0) {
            tx += x[i], ty += y[i];
        } else {
            tx -= x[i], ty -= y[i];
        }
    }
    return hypot(tx, ty);
}

void solve() {
    vector<double> vec;
    rep(i, n) {
        vec.push_back(atan2(x[i], -y[i]));
        vec.push_back(atan2(-x[i], y[i]));
    }
    sort(all(vec));
    double ans = attempt(acos(-1));
    rep(i, 2*n-1) {
        double th = (vec[i] + vec[i+1]) / 2.0;
        ans = max(ans, attempt(th));
    }
    cout << fixed << setprecision(3) << ans << endl;
}

int main() {
    cin.tie(0);
    while (cin >> n and n) {
        input();
        solve();
    }
    return 0;
}
