#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define pb push_back
#define all(u) begin(u),end(u)
#define mp make_pair
#define long int64_t

const int N = 1024;

long n, s, t, x[N], y[N], th;
double a, b;

void input() {
    cin >> n >> s >> t >> a >> b, --s, --t;
    th = (a+b)*(a+b) + 1e-8;
    rep(i, n) cin >> x[i] >> y[i];
}

int d[N];

inline long sq(long n) { return n * n; }
void solve() {
    fill_n(d, n, -1);
    queue<int> que;
    que.push(s), d[s] = 0;
    while (not que.empty()) {
        int v = que.front(); que.pop();
        if (v == t) break;
        rep(u, n) if (u != v and d[u] == -1 and sq(x[v]-x[u])+sq(y[v]-y[u]) <= th) {
            que.push(u), d[u] = d[v] + 1;
        }
    }
    if (d[t] != -1) {
        cout << d[t] << endl;
    } else {
        cout << "Impossible" << endl;
    }
}

int main() {
    cin.tie(0);
    int _; cin >> _;
    while(_--) {
        input();
        solve();
    }
    return 0;
}
