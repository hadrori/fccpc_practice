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

using namespace std;

typedef long long ll;
typedef vector<int> vi;

string s;

int solve()
{
    const int n = s.length();
/*/
    int ans = 0, depth = 0;
    rep(i, n) {
        if (depth >= n - i) {
            return ans + count(s.begin() + i, s.end(), '{');
        }

        if (s[i] == '{') ++depth;
        else --depth;

        if (depth < 0) ++ans, depth = 1;
    }
    return ans;
/*/
    string t;
    rep(i, n) {
        if (s[i] == '}' and !t.empty() and *t.rbegin() == '{') {
            t.erase(t.end() - 1);
        } else {
            t.pb(s[i]);
        }
    }
    cout << t << endl;
    return t.length() / 2 + count(all(t), '}') % 2;
/**/
}

const int N = 2048;
const int inf = N;
/*
int mem[N][N];

int recur(int i, int depth)
{
    if (i == s.length()) return depth == 0 ? 0 : inf;
    if (depth < 0) return inf;

    int& ret = mem[i][depth];
    if (ret >= 0) return ret;

    return ret = min(recur(i + 1, depth + 1) + (s[i] != '{'),
                     recur(i + 1, depth - 1) + (s[i] != '}'));
}

int solve()
{
    memset(mem, -1, sizeof(mem));

    return recur(0, 0);
}
*/
int main()
{
    int cnt = 0;
    while (cin >> s && s[0] != '-') {
        cout << ++cnt << ". " << solve() << endl;
    }

    return 0;
}
