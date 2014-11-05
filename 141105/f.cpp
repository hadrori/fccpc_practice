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

const int N = 50010;
const int p = 1000000007;

ll powp[N] = {1};

void prepare()
{
    repi(i, 1, N) powp[i] = powp[i - 1] * p;
}

int n;
char line[N];

void input()
{
    cin >> line;
    n = strlen(line);
}

ll ha[N];
inline ll h(int a, int b) { return ha[b] - ha[a] * powp[b - a]; }

int solve()
{
    ha[0] = 0;
    rep(i, n) ha[i + 1] = ha[i] * p + line[i];

    int ans = 0, i = 0;
    while (true) {
        int len = 1;
        bool flg = false;
        while (i + len <= n / 2) {
            if (h(i, i + len) == h(n - i - len, n - i)) {
                ans += 2, i += len;
                flg = true;
                break;
            }
            ++len;
        }
        if (not flg) {
            return ans + (2 * i < n);
        }
    }
}

int main()
{
    prepare();

    int t;
    cin >> t;
    rep(i, t) {
        input();
        cout << "Case #" << i + 1 << ": ";
        cout << solve() << endl;
    }

    return 0;
}
