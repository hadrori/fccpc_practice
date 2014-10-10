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
const int MAX = 10007;

const int dx[2][6] = {{1, 0,-1,-1, 0, 1}, {1, 0,-1,-1, 0, 1}};
const int dy[2][6] = {{0, 1, 0,-1,-1,-1}, {1, 1, 1, 0,-1, 0}};

int dir[MAX];
int ans[MAX];
int px, py;
int freq[5];
int now;
map<pair<int, int>, int> f;
void makedir() {
    int cnt = 0;
    int T = 1;
    while(cnt < MAX) {
        dir[cnt++] = 0;
        rep(i, T-1) if(cnt < MAX) dir[cnt++] = 1;
        rep(i, T) if(cnt < MAX) dir[cnt++] = 2;
        rep(i, T) if(cnt < MAX) dir[cnt++] = 3;
        rep(i, T) if(cnt < MAX) dir[cnt++] = 4;
        rep(i, T) if(cnt < MAX) dir[cnt++] = 5;
        rep(i, T) if(cnt < MAX) dir[cnt++] = 0;
        T++;
    }
}

int getf(int x, int y) {
    if(f.find(mp(x, y)) == f.end()) return -1;
    return f[mp(x, y)];
}

void setf(int x, int y, int val) {
    f[mp(x, y)] = val;
}

int getnext() {
    vector<bool> cand(5, true);
    rep(i, 6) {
        int tmp = getf(px + dx[abs(px)%2][i], py + dy[abs(px)%2][i]);
        if(tmp >= 0) cand[tmp] = false;
    }
    int min_freq = MAX;
    rep(i, 5) if(cand[i]) min_freq = min(min_freq, freq[i]);
    rep(i, 5) if(min_freq < freq[i]) cand[i] = false;
    rep(i, 5) if(cand[i]) return i;
}

void step() {
    int nx = px+dx[abs(px)%2][dir[now]];
    int ny = py+dy[abs(px)%2][dir[now]];
    px = nx, py = ny;
}

void prep() {
    px = 0, py = 0;
    makedir();
    for(now = 0; now < MAX; now++) {
        int tmp = getnext();
        setf(px, py, tmp);
        ans[now] = tmp;
        freq[tmp]++;
        step();
    }
}

void solve() {
    int a;
    cin >> a;
    cout << ans[a-1]+1 << endl;
}

int main()
{
    prep();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
