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

void solve()
{
    int n;
    cin >> n;
    priority_queue<int> q[101];
    rep(_, n) {
        char op;
        cin >> op;
        if (op == 'P') {
            int t, s, r;
            cin >> t >> s >> r;
            q[r].push(s - r * t);
        } else if (op == 'A') {
            int t;
            cin >> t;

            int cur = -1, id = -1;
            repd(r, 100, 0) {
                if (q[r].empty()) continue;
                const int s0 = q[r].top();
                int tmp = s0 + r * t;
                if (cur < tmp) {
                    cur = tmp, id = r;
                }
            }
            q[id].pop();
            cout << cur << ' ' << id << endl;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    rep(i, t) {
        cout << "Case #" << i + 1 << ":" << endl;
        solve();
    }

    return 0;
}
