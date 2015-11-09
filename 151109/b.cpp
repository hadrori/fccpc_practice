#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define long int64_t

bool input() {
}

void solve() {
}

int main() {
    cin.tie(0);
    vector<long> v(3);
    rep(i, 3) cin >> v[i];
    sort(all(v));
    long ans = 0;
    rep(i, 3) ans += v[i]/3;
    long tmp = 3;
    rep(i, 3) tmp = min(tmp, v[i]%3);
    ans += tmp;

    do {
        if (v[0]%3 == 2 and v[1]%3 == 2 and v[2]%3 == 0 and v[2] > 0) {
            ans++;
            break;
        }
    } while(next_permutation(all(v)));
    
    cout << ans << endl;
    return 0;
}
