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

const int rotinfo[4][4] = {
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

const int adj[6][4] = {
    {1, 2, 3, 4},
    {0, 2, 4, 5},
    {0, 1, 3, 5},
    {0, 2, 4, 5},
    {0, 1, 3, 5},
    {1, 2, 3, 4}
};
const int tmp[4] = {0, 2, 3, 1};

const int M = 20;

char mem[M][M][M][M][M][M] = {};

bool can(die d)
{
    if (*min_element(all(d)) < 0) return false;
    if (accumulate(all(d), 0) == 0) return true;

    int mxx = *max_element(all(d));

    int mx = 0;
    rep(i, 4) mx = max(mx, d[i + 1]);
    if (mx == 0) return false;
    int mn = 10000;
    rep(i, 4) mn = min(mn, d[i + 1]);
    if (mxx < M) {
        char& ret = mem[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]];
        if (ret) return ret > 0;
    }
    if (mn == mx) {
        die next = rotate(d, 0);
        --next[5];
        return can(next);
    }
    if (d[1] == mx and d[3] == mx) {
        die next = rotate(d, 0);
        --next[5];
        return can(next);
    }
    if (d[2] == mx and d[4] == mx) {
        die next = rotate(d, 1);
        --next[5];
        return can(next);
    }

    rep(i, 6) cerr << d[i] << ' '; cerr << endl;

    int cnt = 0;
    rep(i, 4) if (d[i + 1] == mx and ++cnt <= 2) {
        die next = rotate(d, tmp[i]);
        --next[5];
        if (can(next)) {
            if (mxx < M) mem[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]] = 1;
            return true;
        }
    }
    if (mxx < M) mem[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]] = -1;
    return false;
}

int t[6], p, q;

const string dir = "ENSW";

string attempt()
{
    die d(t, t + 6);
    int cnt = accumulate(t, t + 6, 0);
    cerr << 1 << endl;
    if (not can(d)) return "~";
    cerr << 2 << endl;
    string ans;
    rep(_, cnt) {
        rep(j, 6) cerr << d[j] << ' ';
        cerr << _ << endl;

        rep(i, 4) {
            die tmp = rotate(d, i);
            --tmp[5];
            if (can(tmp)) {
                ans.pb(dir[i]);
                d = tmp;
                break;
            }
        }
    }
    return ans;
}

void solve()
{
    string ans = "~";
    do {
        string tmp = attempt();
        cerr << tmp << endl;
        ans = min(ans, tmp);
    } while (next_permutation(t, t + 6));
    if (ans[0] == '~') cout << "impossible" << endl;
    else cout << ans.substr(p - 1, q - p + 1) << endl;
}

int main()
{
    while (true) {
        rep(i, 6) cin >> t[i];
        if (accumulate(t, t + 6, 0) == 0) break;
        cin >> p >> q;
        solve();
    }

    return 0;
}
