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

int dp[128];

int solve(string &s) {
    int n = s.size();
    int ans = 0;
    rep(i, s.size()) ans += dp[s[i]];

    bool isA = false;
    vector<int> vi, vj;
    repi(i, 1, s.size()) {
        if(s[i] == 'A') {
            if(!isA) vi.pb(i);
            isA = true;
        } else {
            if(isA) vj.pb(i);
            isA = false;
        }
    }

    int df = n-1;
    if(isA) {
        vj.pb(n);
        df = min(df, vi[vi.size()-1]-1);
    }
    rep(k, vi.size()) {
        int i = vi[k], j = vj[k];
        df = min(df, (i-1)*2 + (n-1-j)+1);
    }
    ans += df;

    return ans;
}

int main()
{
    rep(i, 26) dp[i+'A'] = i;
    rep(i, 26) dp['Z'-i] = min(dp['Z'-i], i+1);

    int t;
    cin >> t;
    rep(i, t) {
        string s;
        cin >> s;
        int ans = 2000000;
        ans = min(ans, solve(s));
        reverse(s.begin()+1, s.end());
        ans = min(ans, solve(s));
        cout << ans << endl;
    }
    
    return 0;
}
