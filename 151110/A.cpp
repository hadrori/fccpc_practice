#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define pb push_back
#define all(u) begin(u),end(u)
#define mp make_pair

string s;
char f[16][1024];

void input() {
    cin >> s;
}

void solve() {
    vector<int> vs;
    rep(i,s.size()) vs.push_back(s[i]-'0');
    int h = vs[0], H = *max_element(all(vs));
    vector<int> hs;
    memset(f,'*',sizeof(f));
    rep(i,vs.size()) {
        int f = h == vs[i];
        while(h < vs[i]) hs.pb(++h);
        while(h > vs[i]) hs.pb(--h);
        if(f) hs.pb(h);
    }
    rep(j,hs.size()) rep(i,hs[j]) f[i][j] = '+';
    for(int i = H-1; i >= 0; i--) {
        rep(j,hs.size()) cout << f[i][j];
        cout << endl;
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
