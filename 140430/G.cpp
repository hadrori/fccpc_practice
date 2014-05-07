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

using namespace std;

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

typedef long long ll;
typedef vector<int> vi;

const int N = 1024;

int n, m;
char f[N][N];

void input()
{
    cin >> n >> m;
    rep(i, n) cin >> f[i];
}

int a[N][N];

void solve()
{
    memset(a, 0, sizeof(a));
    
    map<int, int> ans;
    rep(i, n) {
        stack<pair<int, int> > stk;

        rep(j, m) {
            if(i == 0) {
                if(f[i][j] == '#') a[i][j] = 0;
                else a[i][j] = 1;
            } else {
                if(f[i][j] != '#') a[i][j] = a[i-1][j] + 1;
                else a[i][j] = 0;
            }

            if(f[i][j] == '.') {
                int tmp = j;
                while(stk.size() && stk.top().first > a[i][j]) {
                    tmp = stk.top().second;
                    stk.pop();
                }
                
                if(!stk.size() || stk.top().first + j - stk.top().second < a[i][j] + j - tmp)
                    stk.push(mp(a[i][j], tmp));
//                cout << (stk.top().first + j - stk.top().second+1) * 2 << endl;
                ans[(stk.top().first + j - stk.top().second+1) * 2]++;
            } else {
                stk = stack<pair<int, int> >();
            }
        }
    }
    repit(itr, ans) {
        cout << itr->second << " x " << itr->first << endl;
    }
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
