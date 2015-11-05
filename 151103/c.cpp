#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair

const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

int x, y, vs[256][256];
string s;

void solve() {
    memset(vs,0,sizeof(vs));
    vs[x][y] = 1;
    int d = 0, n = 0;
    for(char &c: s) {
        if(c == 'F') {
            x += dx[d], y += dy[d];
            if(vs[x][y] == 1) n++;
            vs[x][y]++;
        }
        else if(c == 'R') d = (d+1)%4;
        else d = (d+3)%4;
    }
    cout << x << ' ' << y << ' ' << n << endl;
}

void input() {
    cin >> x >> y;
    cin >> s;
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
