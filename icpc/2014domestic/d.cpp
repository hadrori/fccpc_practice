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

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define repd(i,a,b) for(int i=int(a);i>=int(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
string s;

void solve(string s) {
    int n = s.size();

    vector<string> ans;
    rep(S, 1<<n) {
        vector<bool> done(26);
        bool ok = true;
        rep(i, n) {
            if((S>>i)&1) {
                if(s[i] == 'z') ok = false;
                if(done[s[i]-'a']) ok =false;
                done[s[i]-'a'] = true;
            }
        }

        if(!ok) continue;
        string ns = s;
        rep(i, n) {
            if((S>>i)&1) {
                ns[i] = (char)(s[i] + 1);
            }
        }

        string ts = ns;
        done.clear();
        done.resize(26);
        rep(i, ts.size()) {
            if(!done[ts[i]-'a'] and ts[i] > 'a') {
                done[ts[i]-'a'] = true;
                ts[i] = (char)(ts[i] - 1);
            }
        }
        
        if(ts == s) {
            //cout << "pushed " << ns << " " << ts << " " << s << endl;
            ans.pb(ns);
        }
    }
    sort(all(ans));
    uniq(ans);
    cout << ans.size() << endl;
    if(ans.size() > 10) {
        rep(i, 5) cout << ans[i] << endl;
        rep(i, 5) cout << ans[ans.size()-5+i] << endl;
    } else {
        rep(i, ans.size()) cout << ans[i] << endl;
    }
    
}

int main()
{
    while(getline(cin, s), s != "#") {
        solve(s);
    }
    return 0;
}
