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

const int N = 1000010;

int n, p[N], s[N];

void input()
{
    cin >> n;
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> s[i];
    p[n] = 1024;
    s[n] = 1024;
    ++n;
}

void solve()
{
    int ans = 0;

    deque<pair<int, int> > q;
    q.pb(mp(-1, 1024));
    rep(i, n) {
        int pop = -2;
        while (not q.empty() and q.front().second > s[i]) {
            pop = q.front().first;
            q.pop_front();
        }
        if (pop > -2) q.push_front(mp(pop, s[i]));

        int push = i;
        while (not q.empty() and q.back().second < p[i]) {
            pair<int, int> back = q.back();
            q.pop_back();

            if (q.empty()) break;

            int h = min(q.back().second, p[i]);
            ans += (i - back.first) * (h - back.second);
            push = back.first;
        }
        q.push_back(mp(push, p[i]));
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }

    return 0;
}
