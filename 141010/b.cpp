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

const int N = 400000;
const ll p = 1000000007;

ll powp[N] = {1};

void prepare()
{
    repi(i, 1, N) powp[i] = powp[i - 1] * p;
}

int len;
char line[N];

ll h[N];

ll ha(int a, int b)
{
    return h[b] - h[a] * powp[b - a];
}

int paren[N];

int cnt;
map<ll, int> mem;

void dfs(int& pos)
{
    int i = pos;
    while (i < len and islower(line[i])) ++i;

    if (line[i] != '(') {
        ll tmp = ha(pos, i);
        if (mem.find(tmp) != mem.end()) {
            cout << mem[tmp];
            pos = i;
        } else {
            mem[tmp] = ++cnt;
            while (pos < i) {
                cout << line[pos];
                ++pos;
            }
        }
    } else {
        int b = paren[i] + 1;
        ll tmp = ha(pos, b);
        if (mem.find(tmp) != mem.end()) {
            cout << mem[tmp];
            pos = b;
        } else {
            mem[tmp] = ++cnt;
            while (pos < i) {
                cout << line[pos];
                ++pos;
            }
            ++pos, cout << '(';
            dfs(pos);
            ++pos, cout << ',';
            dfs(pos);
            ++pos, cout << ')';
        }
    }
}

void solve()
{
    rep(i, len) {
        h[i + 1] = h[i] * p + line[i];
    }
    memset(paren, -1, sizeof(paren));
    stack<int> stk;
    for (int i = len - 1; i >= 0; --i) {
        if (line[i] == ')') stk.push(i);
        if (line[i] == '(') {
            paren[i] = stk.top();
            stk.pop();
        }
    }
    cnt = 0;
    mem.clear();
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
        len = strlen(line);
        while (len > 0 and line[len - 1] <= 32) line[--len] = 0;
        solve();
    }

    return 0;
}
