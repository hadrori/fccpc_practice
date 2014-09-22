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

int n, m;
const int MAX = 64;
char f[MAX][MAX];
const int di[] = {-1, 0, 1, 0};
const int dj[] = { 0, 1, 0,-1};

int done[MAX][MAX][4];


bool inrange(int i, int j) {
    return i >= 0 and j >= 0 and i < n and j < m;
}

int main() {
    cin >> n >> m;
    rep(i, n) rep(j, m) cin >> f[i][j];
    int pi, pj, dir;
    rep(i, n) rep(j, m) {
        if(f[i][j] == '^') {
            pi = i, pj = j;
            dir = 0;
        } else if(f[i][j] == '>') {
            pi = i, pj = j;
            dir = 1;            
        } else if(f[i][j] == 'v') {
            pi = i, pj = j;
            dir = 2;
        } else if(f[i][j] == '<') {
            pi = i, pj = j;
            dir = 3;
        }
    }

    while(true) {
        //cout << pi << " " << pj << " " << dir << endl;
        if(done[pi][pj][dir]) break;
        done[pi][pj][dir] = 1;
        if(f[pi][pj] == 'G') break;
        int ni = pi + di[dir], nj = pj + dj[dir];
        int ndir = (dir+1)%4;
        int ndir2 = (dir+3)%4;
        int ti = pi + di[dir] + di[ndir], tj = pj + dj[dir] + dj[ndir];
        if(inrange(pi+di[ndir], pj + dj[ndir]) and f[pi+di[ndir]][pj+dj[ndir]] != '#') {
            dir = ndir;
            pi = pi+di[dir], pj = pj + dj[dir];
        } else if(inrange(ni, nj) and f[ni][nj] != '#') {
            pi = ni, pj = nj;
        } else if(inrange(pi+di[ndir2], pj + dj[ndir2]) and f[pi+di[ndir2]][pj+dj[ndir2]] != '#') {
            dir = ndir2;
            pi = pi+di[dir], pj = pj + dj[dir];
        } else {
            dir = (dir + 2) % 4;
            pi = pi+di[dir], pj = pj + dj[dir];
        }
    }
    
    int ans = 0;
    rep(i, n) rep(j, m) {
        bool used = false;
        rep(k, 4) if(done[i][j][k]) used = true;
        if(used) ans++;
    }
    if(f[pi][pj] != 'G') ans = -1;
    
    cout << ans << endl;
    
    return 0;
}
