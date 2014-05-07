#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

typedef long long ll;
typedef vector<int> vi;

const int N = 1024;

int n;
bool petra;
vector<pair<int, int> > v;

void input()
{
    v.clear();

    string name;
    cin >> n >> name;
    petra = name == "Petra";
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        v.pb(mp(a, -b));
    }
    sort(rall(v));
}

const int inf = 100000000;

pair<int, int> dp[N][N];

#define fst first
#define snd second

void solve()
{
    rep(i, N) rep(j, N) dp[i][j] = mp(-inf, -inf);
    dp[0][0] = mp(0, 0);

    rep(i, n) rep(j, i + 1) {
        dp[i + 1][j] = mp(dp[i][j].fst, dp[i][j].snd + v[i].fst);
        if (j and j <= (i + !petra + 1) / 2) {
            dp[i + 1][j] = max(dp[i + 1][j], mp(dp[i][j - 1].fst - v[i].snd, dp[i][j - 1].snd));
        }
    }
    pair<int, int> ans = dp[n][(n + !petra) / 2];
    cout << ans.second << ' ' << ans.first << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        input();
        solve();
    }

    return 0;
}
