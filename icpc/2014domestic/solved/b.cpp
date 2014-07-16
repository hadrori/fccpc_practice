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

const int MAX = 16;
int f[MAX][MAX];
int e[MAX][MAX];
int h;
int solve() {
    bool end = false;
    int ans = 0;
    while(!end) {
        end = true;
        memset(e, 0, sizeof(e));
        rep(i, h) rep(j, 5) if(f[i][j] != 0){
            int cnt = 0;
            rep(k, 5) {
                if(j+k >= 5 or f[i][j+k] != f[i][j]) break;
                cnt++;
            }
            if(cnt >= 3) {
                end = false;
                rep(k, cnt) e[i][j+k] = 1;
            }
        }
        rep(i, h) rep(j, 5) if(e[i][j]) {
            if(f[i][j] != 0) ans+=f[i][j];
            f[i][j] = 0;
        }

        rep(j, 5) rep(_, h) repd(i, h-1, 1) {
            if(f[i][j] == 0 and f[i-1][j] != 0) {
                swap(f[i][j], f[i-1][j]);
            }
        }
/*
        rep(i, h) {
            rep(j, 5) cout << f[i][j] << " ";
            cout << endl;
        }
        cout << endl;*/
    }
    return ans;
}

int main()
{
    while(cin >> h, h) {
        rep(i, h) rep(j, 5) cin >> f[i][j];
        cout << solve() << endl;
    }
    return 0;
}
