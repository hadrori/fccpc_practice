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

const int N = 200010;

int s, n, a[N];

void input()
{
    cin >> s >> n;
    rep(i, n) cin >> a[i], --a[i];
}

int last[N], prev[N];

void solve()
{
    memset(last, -1, sizeof(last));

    int cur = 0;
    rep(i, n) {
        prev[i] = cur = max(cur, last[a[i]] + 1);
        last[a[i]] = i;
    }
    const int nn = s + n + 1;
    repi(i, n, nn + 1) {
        prev[i] = cur = max(cur, i - s + 1);
    }

    int ans = 0;
    rep(i, s) {
        int flag = 1;
        for (int j = i; j <= nn; j += s) {
            if (prev[j] > 0 and j - prev[j] + 1 < s) {
                flag = 0;
                break;
            }
        }
        ans += flag;
    }
    cout << ans << endl;
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
