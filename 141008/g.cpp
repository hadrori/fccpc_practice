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

using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;

const int MAX = 5;
const int di[] = {0, 1, 1,-1};
const int dj[] = {1, 0, 1, 1};
char f[MAX][MAX];
const int NUM = 3;
bool inrange(int i, int j) { return i >= 0 and j >= 0 and i < MAX and j < MAX; }
bool check(char c) {
    rep(i, MAX) rep(j, MAX) {
        rep(dir, 4) {
            bool ok = true;
            rep(k, NUM) {
                int ti = i + k*di[dir], tj = j + k*dj[dir];
                if(!inrange(ti, tj) or
                   f[ti][tj] != c) ok = false;
            }
            /*
            int ti, tj;
            ti = i+3*di[dir], tj = j+3*dj[dir];
            if(inrange(ti, tj) and f[ti][tj] == c) ok = false;
            ti = i-di[dir], tj = j-dj[dir];
            if(inrange(ti, tj) and f[ti][tj] == c) ok = false;
            */
            if(ok) return true;
        }
        
    }
    return false;
}

void solve() {
    rep(i, MAX) rep(j, MAX) cin >> f[i][j];
    /*
    rep(i, MAX) {
        rep(j, MAX) cout << f[i][j];
        cout << endl;
    }
    cout << endl;
    */
    bool awin = check('A');
    bool bwin = check('B');
    if(awin and !bwin) cout << "A wins" << endl;
    else if(!awin and bwin) cout << "B wins" << endl;
    else cout << "draw" << endl;
    
}

int main()
{
    int T;
    cin >> T;
    rep(i, T) solve();
    return 0;
}
