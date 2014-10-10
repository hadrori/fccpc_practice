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
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 300000;
const ll p = 9973;
const ll mod = 1000000007;

char line[N];
int len, cnt;

ll powp[N] = {1};
ll hsh[N];
map<ll, int> mem;

void prepare()
{
    repi(i, 1, N) {
        powp[i] = powp[i - 1] * p % mod;
    }
}

ll hs(int a, int b)
{
    return ((hsh[b] - hsh[a] * powp[b - a]) % mod + mod) % mod;
}

void dfs(int& pos)
{
    const int prev = pos;

    int i = pos;
    while (i < len and isalpha(line[i])) ++i;
    const int paren = line[i] == '(' ? i : -1;
    if (paren >= 0) {
    int nest = 0;
    do {
        if (line[i] == '(') ++nest;
        if (line[i] == ')') --nest;
    } while (++i, nest);
    }
    if (mem.find(hs(prev, i)) != mem.end()) {
        cout << mem[hs(prev, i)];
        pos = i;
    } else {
        mem[hs(prev, i)] = ++cnt;
        if (paren >= 0) {
            while (pos < paren) {
                cout << line[pos];
                ++pos;
            }
            ++pos, cout << '(';
            dfs(pos);
            ++pos, cout << ',';
            dfs(pos);
            ++pos, cout << ')';
        } else {
            while (pos < i) {
                cout << line[pos];
                ++pos;
            }
        }
    }
}

void solve()
{
    mem.clear();
    len = strlen(line);
    while (line[len - 1] <= ' ') line[--len] = 0;
    cnt = 0;
    hsh[0] = 0;
    rep(i, len) {
        hsh[i + 1] = (hsh[i] * p + line[i]) % mod;
    }

    int pos = 0;
    dfs(pos);
    cout << endl;
}

int main()
{
    prepare();

    int t;
    scanf("%d ", &t);
    while (t--) {
        fgets(line, sizeof(line), stdin);
        solve();
    }

    return 0;
}
