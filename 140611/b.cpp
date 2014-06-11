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

const int N = 100010;

int s, l;
vector<pair<int, int> > v;

int main()
{
    cin >> s >> l;

    repi(i, 1, l + 1) v.pb(mp(i & -i, i));
    sort(rall(v));

    vector<int> ans;
    rep(i, l) {
        if (s < v[i].first) continue;
        s -= v[i].first;
        ans.pb(v[i].second);
        if (s == 0) break;
    }

    if (s == 0) {
        cout << ans.size() << endl;
        rep(i, int(ans.size())) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
