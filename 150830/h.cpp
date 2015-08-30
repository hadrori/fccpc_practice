#include <bits/stdc++.h>
using namespace std;

#define repi(i,a,b) for(int i = (int)(a); i<(int)(b); ++i)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

int n, m, k;
string s;

void input() 
{
    cin >> n >> m >> k >> s;
    reverse(all(s));
}

int dp[2][2048];

void solve()
{
    int cur = 0, suc = 1, dc = 1;
    for (char c : s) {
        const int team = c == 'B';
        queue<int> que;
        rep(i, min(dc + k, m + 1)) {
            if (i <= k) {
                dp[suc][i] = team;
            } else {
                while (not que.empty() and que.front() < i - k) que.pop();
                dp[suc][i] = que.empty() ? !team : team;
            }
            if (i < dc and dp[cur][i] == team) {
                que.push(i);
            }
        }
        dc += k;
        swap(cur, suc);
    }
    cout << char('A'+dp[cur][m]) << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        input();
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
