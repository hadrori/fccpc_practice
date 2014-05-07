#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>

#define repi(i,a,b) for(int i = int(a); i < int(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = int(a); i >= int(b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);

using namespace std;

typedef long long ll;
typedef vector<string> state;

vector<vector<int> > G;

int x, y;
state s, t;

void input()
{
    G.assign(2 * x, vector<int>()), s.assign(x, ""), t.assign(x, "");

    rep(i, y) {
        int p, q; char P, Q;
        cin >> p >> P >> q >> Q;
        int a = P == 'W' ? p : p + x;
        int b = Q == 'W' ? q : q + x;
        G[a].pb(b), G[b].pb(a);        
    }
    rep(i, x) {
        cin >> s[i];
        if (s[i] == "-") s[i] = "";
    }
    rep(i, x) {
        cin >> t[i];
        if (t[i] == "-") t[i] = "";
    }
}

map<state, int> fromS, fromT;

void bfs(state start, map<state, int> &mem)
{
    mem.clear();

    queue<pair<state, int> > Q;
    Q.push(mp(start, 0));
    while (!Q.empty()) {
        pair<state, int> cur = Q.front(); Q.pop();

        if (mem.find(cur.first) != mem.end() || cur.second > 3)
            continue;
        mem[cur.first] = cur.second;

        if (cur.second == 3) continue;

        rep(i, x) rep(cut, cur.first[i].length()) {
            rep(j, G[i].size()) if (cut) {
                string west = cur.first[i].substr(0, cut);

                int to = G[i][j];
                state next = cur.first;
                next[i].erase(next[i].begin(), next[i].begin() + cut);
                if (to < x) {
                    reverse(all(west));
                    next[to].insert(next[to].begin(), all(west));
                } else
                    next[to - x].insert(next[to - x].end(), all(west));
                Q.push(mp(next, cur.second + 1));
            }
            rep(j, G[i + x].size()) if (cut < cur.first[i].length() - 1) {
                string east = cur.first[i].substr(cut);

                int to = G[i + x][j];
                state next = cur.first;
                next[i].erase(next[i].begin() + cut, next[i].end());
                if (to < x)
                    next[to].insert(next[to].begin(), all(east));
                else {
                    reverse(all(east));
                    next[to - x].insert(next[to - x].end(), all(east));
                }
                Q.push(mp(next, cur.second + 1));
            }
        }
    }
}

void solve()
{
    bfs(s, fromS), bfs(t, fromT);

    int ans = 10;
    repit(it, fromS) {
        map<state, int>::iterator it1 = fromT.find(it->first);
        if (it1 != fromT.end())
            ans = min(ans, it->second + it1->second);
    }
    cout << ans << endl;
}

signed main()
{
    while (cin >> x >> y && x) {
        input();
        solve();
    }

    return 0;
}
