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

int n, k;
vector<vector<int>> children;
vector<int> in_deg;

void input()
{
    cin >> n >> k >> ws;
    children.assign(n, vector<int>());
    in_deg.assign(n, 0);
    rep(i, n) {
        string s;
        getline(cin, s);
        istringstream sin(s);
        vector<int> vec;
        for (int t; sin >> t; ) {
            vec.push_back(t);
        }
        if (vec[0] == 0) continue;
        const int deg = vec.size();
        children[i].resize(deg);
        rep(j, deg) {
            const int c = vec[j] - 1;
            children[i][j] = c;
            ++in_deg[c];
        }
    }
}

const int N = 128;
const int NA = -1;

int dp[N][3];

void dfs(int v)
{
    int cur[4][N], suc[4][N];
    memset(cur, NA, sizeof(cur));
    cur[0][0] = 0;
    const int deg = children[v].size();
    rep(k, deg) {
        const int c = children[v][k];
        dfs(c);
        memset(suc, NA, sizeof(suc));
        rep(i, 3) rep(j, k+1) if (cur[i][j] != NA) {
            rep(ci, 3) if (dp[c][ci] != NA) {
                suc[i | ci][j + (ci == 0)] = max(suc[i | ci][j + (ci == 0)],
                                                 cur[i][j] + dp[c][ci]);
            }
        }
        memcpy(cur, suc, sizeof(cur));
    }
    dp[v][0] = max(*max_element(cur[0], cur[0] + deg + 1),
                   *max_element(cur[2], cur[2] + deg + 1));
    dp[v][1] = max(cur[0][k], cur[1][k]);
    if (dp[v][1] != NA) ++dp[v][1];
    dp[v][2] = max(cur[0][k-1], cur[1][k-1]);
    if (dp[v][2] != NA) ++dp[v][2];
}

int solve()
{
    if (k <= 0) return n;
    rep(i, n) if (in_deg[i] == 0) {
        dfs(i);
        return max(dp[i][0], dp[i][1]);
    }
    return NA;
}

int main()
{
    int t;
    for (cin >> t; t--; ) {
        input();
        cout << solve() << endl;
    }
    return 0;
}
