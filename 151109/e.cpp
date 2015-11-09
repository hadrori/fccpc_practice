#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define long int64_t

int n;
vector<vector<int>> G;

bool input() {
    scanf("%d", &n);
    G.assign(n, vector<int>());
    rep(i,n-1) {
        int u, v;
        scanf("%d%d", &u, &v), --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

const int N = 100010;

int level[N], par[N], done[N];

vector<int> bfs(int s) {
    vector<int> ret;
    queue<int> que;
    que.push(s);
    par[s] = -1;
    while (not que.empty()) {
        int v = que.front(); que.pop();
        ret.push_back(v);
        done[v] = true;
        for (int u : G[v]) {
            if (level[u] == 0 and not done[u]) {
                que.push(u);
                par[u] = v;
            }
        }
    }
    return ret;
}

int sz[N], mx[N];

void update(int v) {
    sz[v] = 1;
    mx[v] = 0;
    for (int u : G[v]) {
        if (u != par[v] and level[u] == 0) {
            sz[v] += sz[u];
            mx[v] = max(mx[v], sz[u]);
        }
    }
}

char ans[2*N];

void solve() {
    auto ord = bfs(0);
    rep(i, 26) {
        fill_n(done, n, 0);
        for (int v : ord) {
            if (level[v] == 0 and not done[v]) {
                auto t = bfs(v);
                reverse(all(t));
                for (int u : t) update(u);
                int whole = sz[v];
                int tmp = mx[v];
                bool updated = true;
                while (updated) {
                    updated = false;
                    for (int c : G[v]) {
                        if (level[c] == 0) {
                            int tttmp = max(mx[c], whole - sz[c]);
                            if (tmp > tttmp) {
                                v = c;
                                tmp = tttmp;
                                updated = true;
                                break;
                            }
                        }
                    }
                }
                level[v] = i + 1;
            }
        }
    }
    char *p = ans;
    rep(i, n) {
        *p++ = 'A' + level[i] - 1;
        if (i < n-1) *p++ = ' ';
    }
    *p = 0;
    puts(ans);
}

int main() {
    input();
    solve();
    return 0;
}
