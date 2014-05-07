#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>ago
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

int main()
{
    int t;
    cin >> t;
    rep(_, t) {
        string s[3];
        rep(i, 3) cin >> s[i];
        vector<char> st;
        rep(i, 3) rep(j, s[i].size()) st.pb(s[i][j]);
        sort(all(st));
        UNIQUE(st);
        int n = st.size();
        vector<int> v1;
        vector<int> v2;
        rep(i, 10-n) v2.pb(0);
        rep(i, n) v2.pb(1);

        rep(i, 10) v1.pb(i);
        int ans = 0;
        do{
            vector<int> v;
            rep(i, 10) if(v2[i]) v.pb(v1[i]);
            do {
                vector<int> table(5);
                rep(i, n) table[st[i]-'A'] = v[i];

                int num[3] = {0};
                bool ok = true;
                rep(i, 3) if(s[i].size() > 1 && table[s[i][0]-'A'] == 0) ok = false;
                if(!ok) continue;
                rep(i, 3) {
                    rep(j, s[i].size()) {
                        num[i] *= 10;
                        num[i] += table[s[i][j] - 'A'];
                    }
                }
//                rep(i, 3) cout << num[i] << " ";
//                cout << endl;
                if(num[0] + num[1] == num[2]) ans++;
                if(num[0] - num[1] == num[2]) ans++;
                if(num[0] * num[1] == num[2]) ans++;
                if(num[1] != 0 && num[0] == num[1]*num[2]) ans++;
                /*
                if(num[0] == num[1] + num[2]) ans++;
                if(num[0] == num[1] - num[2]) ans++;
                if(num[0] == num[1] * num[2]) ans++;
                if(num[0]*num[2] == num[1]) ans++;
                */
//                cout << ans << endl;
            } while(next_permutation(all(v)));
        } while(next_permutation(all(v2)));
        cout << ans << endl;
    }
    return 0;
}
