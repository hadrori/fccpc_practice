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

string s;
int ans;
int cw;
int n;
const int dx[] = {-2, 2,-1, 1};
void dfs(int a, int b, int d, int pos) {
    if(d == ans) return;
//    cout << a << " " << b << " " << s << " " << d << endl;
    if((a + n - b - 1 - (a<=pos && pos<=b?0:1)) == cw) {
        ans = min(ans, d);
        return;
    }

    rep(i, 4) {
        int to = pos + dx[i];
        if(to >= s.size() || to < 0) continue;
        int tcw = cw;
        int ta = a, tb = b;
        if(abs(dx[i]) == 2) {
            if(s[to] == 'W') {
                cw--;
                s[to] = 'B';
            }else {
                cw++;
                s[to] = 'W';
            }
        }
        swap(s[pos], s[to]);
        
        while(a < n-1 && (s[a] == 'W' || s[a] == 'F')) a++;
        while(b > 0 && (s[b] == 'W' || s[b] == 'F')) b--;

        
        if(s[to] == 'B') {
            a = min(a, to);
            b = max(b, to);
        }
        if(s[pos] == 'B') {
            a = min(a, pos);
            b = max(b, pos);
        }

        dfs(a, b, d+1, to);
        
        swap(s[pos], s[to]);
        if(abs(dx[i]) == 2) {
            if(s[to] == 'W') s[to] = 'B';
            else s[to] = 'W';
        }
        a = ta, b = tb, cw = tcw;
    }
    
}


int solve() {
    n = s.size();
    ans = 10;
    cw = count(all(s), 'W');
    int a = 0, b = n-1, f;
    rep(i, n) if(s[i] == 'F') f = i;

    while(a < s.size() && (s[a] == 'W' || s[a] == 'F')) a++;
    while(b >= 0 && (s[b] == 'W' || s[b] == 'F')) b--;
    if(a == n) return 0;
    
    dfs(a, b, 0, f);
    if(ans == 10) return -1;
    return ans;
}


int main()
{
    int cnt = 1;
    while(cin >> s, s != "---") {
        cout << cnt++ << ". ";
        cout << solve() << endl;
    }

    return 0;
}
