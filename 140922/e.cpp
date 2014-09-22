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
int pi, pj;
int dir;
string s;
int pos;
int ans;

int done[MAX][MAX][1024][4] = {0};

void program();
bool inrange(int i, int j) {
    return i >= 0 and j >= 0 and i < n and j < m;
}

void move() {
    if(ans < 0) return;
    if(f[pi][pj] == 'g') return;
//    cout << "move " << s.substr(pos) << endl;
    if(s[pos] == '^') {
        ans++;
        int ni = pi + di[dir];
        int nj = pj + dj[dir];
        if(inrange(ni, nj) and f[ni][nj] != '#') {
            pi = ni, pj = nj;
        }
    } else if(s[pos] == 'v') {
        ans++;
        int ni = pi - di[dir];
        int nj = pj - dj[dir];
        if(inrange(ni, nj) and f[ni][nj] != '#') {
            pi = ni, pj = nj;
        }
    } else if(s[pos] == '>') {
        ans++;
        dir = (dir+1)%4;            
    } else if(s[pos] == '<') {
        ans++;
        dir = (dir+3)%4;
    }
    pos++;
}

bool cond() {
//    cout << "cond " << s.substr(pos) << endl;
    bool rev = false;
    if(s[pos] == '~') {
        rev = true;
        pos++;
    }
    bool cd = (s[pos] == 'N' and dir == 0)
        or (s[pos] == 'E' and dir == 1)
        or (s[pos] == 'S' and dir == 2)
        or (s[pos] == 'W' and dir == 3)
        or (s[pos] == 'C' and f[pi+di[dir]][pj+dj[dir]] == '#')
        or (s[pos] == 'T');
    pos++;
    return rev ^ cd;
}

void ifs() {
//    cout << "if " << s.substr(pos) << endl;
    pos++;
    int tpos = pos;
    if(cond()) {
        program();
        pos++;
    }

    pos = tpos;
    int tmp = 1;
    while(tmp) {
        if(s[pos] == '[') tmp++;
        else if(s[pos] == ']') tmp--;
        pos++;
    }
}

void whiles() {
//    cout << "while " << s.substr(pos) << endl;
    pos++;
    int tpos = pos;
    while(cond()) {
        program();
        if(f[pi][pj] == 'g') return;
        if(ans < 0) return;
        pos = tpos;
    }
    pos = tpos;
    int tmp = 1;
    while(tmp) {
        if(s[pos] == '{') tmp++;
        else if(s[pos] == '}') tmp--;
        pos++;
    }
}

void state() {
    if(f[pi][pj] == 'g') return;
    if(ans < 0) return;
    //cout << "state " << s.substr(pos) << endl;
    if(s[pos] == '[') {
        ifs();
    } else if(s[pos] == '{') {
        whiles();
    } else {
        move();
    }
}

void program() {
//    cout << "program " << s.substr(pos) << endl;
    while(pos < s.size() and s[pos] != ']' and s[pos] != '}') {
        if(done[pi][pj][pos][dir]) {
            ans = -1;
            return;
        }
        if(ans < 0) return;
        done[pi][pj][pos][dir] = 1;
        if(f[pi][pj] == 'g') return;
        state();
    }
}

int main() {
    cin >> n >> m;
    rep(i, n) rep(j, m) cin >> f[i][j];

    dir = 0;
    rep(i, n) rep(j, m) if(f[i][j] == 's') {
        pi = i;
        pj = j;
    }

    cin >> s;
    ans = 0;
    pos = 0;
    program();
    cout << ans << endl;
    return 0;
}
