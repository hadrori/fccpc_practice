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

map<ll, int> table;
int solve(ll a, ll b) {
    int cnt = 0;
    while(true) {
        cnt++;
        table[a] = cnt;
        ll nxt = 0;
        while(a) {
            nxt += (a%10) * (a%10);
            a /= 10;
        }
        a = nxt;
        if(table.find(a) != table.end()) break;
    }

    cnt = 0;
    int ans = 1000000;
    set<ll> st;
    while(true) {
        cnt++;
        if(table.find(b) != table.end()) ans = min(ans, cnt + table[b]);
        int nxt = 0;
        while(b) {
            nxt += (b%10) * (b%10);
            b /= 10;
        }
        b = nxt;
        if(st.find(b) != st.end()) return ans;
        st.insert(b);
    }
}

int main()
{
    int a, b;
    while(cin >> a >> b, a||b) {
        table.clear();
        int ans = solve(a, b);
        if(ans == 1000000) ans = 0;
        cout << a << " " << b << " " << ans << endl;
    }
    return 0;
}
