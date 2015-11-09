#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back

int n, m;

bool input() {cin>>n>>m;
}

void solve() {
    cout << n+m-1 << endl;
    rep(i,m) cout << 1 << ' ' << i+1 << endl;
    repi(i,1,n) cout << i+1 << ' ' << 1 << endl;
}

int main() {
    cin.tie(0);
    input();
    solve();
    return 0;
}
