#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define repd(i,a,b) for(int i=int(a);i>=int(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

typedef vector<int> die;

int rotinfo[4][4] = {
    {0, 3, 5, 1},
    {0, 2, 5, 4},
    {0, 4, 5, 2},
    {0, 1, 5, 3}
};

die rotate(die d, int dir)
{
    rep(i, 3) swap(d[rotinfo[dir][i]], d[rotinfo[dir][i + 1]]);
    return d;
}

int adj[6][4] = {
    {1, 2, 3, 4},
    {0, 2, 4, 5},
    {0, 1, 3, 5},
    {0, 2, 4, 5},
    {0, 1, 3, 5},
    {1, 2, 3, 4}
};

bool can(die d)
{
    if (not accumulate(d.begin(), d.end(), 0)) return true;

    ++d[5];
    rep(i, 6) {
        int tmp = 0;
        rep(j, 4) tmp += d[adj[i][j]];
        if (d[i] > tmp) return false;
    }
    return true;
}

int t[6], p, q;

string attempt()
{
    int cnt = accumulate(t, t + 6, 0);
    die d(t, t + 6);
    const string dir = "ENSW";
    string ans;
    rep(_, cnt) {
        rep(i, 4) {
            die tmp = rotate(d, i);
            if (tmp[5] == 0) continue;
            --tmp[5];
            rep(j, 6) cerr << tmp[j] << ' ';
            if (can(tmp)) {
                cerr << "can!" << endl;
                ans.pb(dir[i]);
                d = tmp;
                break;
            }
            cerr << "cannot..." << endl;
            ++tmp[5];
        }
    }
    return ans;
}

void solve()
{
    string ans = "~";
    do {
        ans = min(ans, attempt());
    } while (next_permutation(t, t + 6));
    cout << ans.substr(p - 1, q - p + 1) << endl;
}

const int M = 10;
bool memo[6][M][M][M][M][M][M];
vector<vector<int> > E;
bool dfs(int now, int a1, int a2, int a3, int a4, int a5, int a6) {
    if(a1 == 0 and a2 == 0 and a3 == 0 and
       a4 == 0 and a5 == 0 and a6 == 0) return true;
    if(!(a1 >= 0 and a1 < M and a2 >= 0 and a2 < M and a3 >= 0 and a3 < M and
         a4 >= 0 and a1 < M and a5 >= 0 and a5 < M and a6 >= 0 and a6 < M)) return false;
    if(memo[now][a1][a2][a3][a4][a5][a6]) return true;
    bool ret = false;
    rep(i, 4) if(!ret) {
        int to = E[now][i];
        int b1 = a1;
        int b2 = a2;
        int b3 = a3;
        int b4 = a4;
        int b5 = a5;
        int b6 = a6;
        if(to == 0) b1--;
        if(to == 1) b2--;
        if(to == 2) b3--;
        if(to == 3) b4--;
        if(to == 4) b5--;
        if(to == 5) b6--;
        if(dfs(to, b1, b2, b3, b4, b5, b6)) ret = true;
    }
    
    return memo[now][a1][a2][a3][a4][a5][a6] = ret;
}

void test() {
    E.resize(6);
    E[0].pb(1); E[0].pb(2); E[0].pb(3); E[0].pb(4);
    E[1].pb(0); E[0].pb(2); E[0].pb(5); E[0].pb(4);
    E[2].pb(0); E[0].pb(1); E[0].pb(3); E[0].pb(5);
    E[3].pb(0); E[0].pb(2); E[0].pb(5); E[0].pb(4);
    E[4].pb(0); E[0].pb(1); E[0].pb(3); E[0].pb(5);
    E[5].pb(1); E[0].pb(2); E[0].pb(3); E[0].pb(4);
    rep(now, 6) rep(a1, M) rep(a2, M) rep(a3, M) rep(a4, M) rep(a5, M) rep(a6, M) {
        if(dfs(now, a1, a2, a3, a4, a5, a6)) {
            cout << now << " " << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << endl;
            cout << dfs(now, a1, a2, a3, a4, a5, a6) << endl;
        }
    }
}

int main()
{
    test();
    return 0;
    while (true) {
        rep(i, 6) cin >> t[i];
        if (accumulate(t, t + 6, 0) == 0) break;
        cin >> p >> q;
//        solve();
    }

    return 0;
}
