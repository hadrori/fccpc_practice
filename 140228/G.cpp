#include <algorithm>
#include <bitset>
#include <cmath>
#include <cctype>
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

int T, N;
const int MAX_N = 1000000;
int n, k;
int rank[MAX_N+1], tmp[MAX_N+1], sa[MAX_N+1], lcp[MAX_N+1];

bool compare_sa(int i, int j) {
    if(rank[i] != rank[j]) return rank[i] < rank[j];
    else {
        int ri = i + k <= n ? rank[i+k] : -1;
        int rj = j + k <= n ? rank[j+k] : -1;
        return ri < rj;
    }
}

void construct_sa(string S) {
    n = S.length();
    for(int i = 0; i <= n; i++) {
        sa[i] = i;
        rank[i] = i < n ? S[i] : -1;
    }
    for(k = 1; k <= n; k*=2) {
        sort(sa, sa+n+1, compare_sa);
        tmp[sa[0]] = 0;
        for(int i = 1; i <= n; i++) {
            tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
        }
        for(int i = 0; i <= n; i++) {
            rank[i] = tmp[i];
        }
    }
}

void construct_lcp(string S) {
    int n = S.length();
    for(int i = 0; i <= n; i++) rank[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for(int i = 0; i < n; i++) {
        int j = sa[rank[i] - 1];
        if(h > 0) h--;
        for(; j + h < n && i + h < n; h++) {
            if(S[j+h] != S[i+h]) break;
        }
        lcp[rank[i] - 1] = h;
    }
}

string toStr(int num) {
    string ret = "";
    rep(i, 6) {
        ret += (char)(num%10 + '0');
        num /= 10;
    }
    reverse(all(ret));
    return ret;
}

int main()
{
    cin >> T;
    for(int _ = 0; _ < T; _++){
        int n;
        cin >> n;
        vector<string> s(n);
        vector<int> w(n);
        rep(i, n) cin >> s[i] >> w[i];
        vector<vector<int> > G(n);
        
        string S;
        rep(i, n) S += s[i] + "#" + toStr(i);
        construct_sa(S);
        construct_lcp(S);
        vector<bool> start(S.size());
        start[0] = true;
        rep(i, S.size()-1) if(S[i] == '#') start[i+7] = true;
        vector<int> from(S.size());
        int cnt = 0;
        rep(i, S.size()) {
            from[i] = cnt;
            if(S[i] == '#') cnt++;
        }

        int val = 0;
        int size = 1000000000;
        int frm = -1;
        bool ok = true;
        vector<int> dp(n);
        rep(i, n) dp[i] = w[i];
        rep(i, S.size()) if(S[sa[i]] != '#' && !isdigit(S[sa[i]])) {
            if(ok) {
                if(lcp[i-1] >= size) {
                    if(from[sa[i]] > frm) {
                        dp[from[sa[i]]] = max(dp[from[sa[i]]], val + w[from[sa[i]]]);
                        //cout << from[sa[i]] << " " << frm << endl;
                    }
                } else ok = false;
            }
            if(start[sa[i]]) {
                val = dp[from[sa[i]]];
                size = s[from[sa[i]]].size();
                frm = from[sa[i]];
                ok = true;
            }
        }


//        rep(i, S.size()) cout << lcp[i] << " " << S.substr(sa[i]) << endl;

        int ans = 0;
        rep(i, n) ans = max(ans, dp[i]);
        
        cout << "Case #" << _+1 << ": ";
        cout << ans << endl;
    }
    return 0;
}
