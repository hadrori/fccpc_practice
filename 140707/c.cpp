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

int h, w, c, ans;
int panel[8][8], done[8][8];
const int di[] = {1,0,-1,0}, dj[] = {0,1,0,-1};
inline bool in(int i, int j) { return i >= 0 and i < h and j >= 0 and j < w;}

int dfs2(int i, int j, int prev, int to, int p[8][8]){
    done[i][j] = 1;
    p[i][j] = to;
    int ret = 1;
    rep(d,4){
        int ni = i + di[d], nj = j + dj[d];
        if(in(ni,nj) and !done[ni][nj] and p[ni][nj] == prev)
            ret += dfs2(ni,nj,prev, to, p);
    }
    return ret;
}

void dfs(int turn, int pp[8][8]){
    int p[8][8];
    if(turn == 4){
        memcpy(p,pp,sizeof(p));
        memset(done, 0, sizeof(done));
        dfs2(0,0,p[0][0],c,p);
        memset(done, 0, sizeof(done));
        ans = max(ans, dfs2(0,0,p[0][0],c,p));
    }
    else {
        repi(i,1,7){
            memcpy(p,pp,sizeof(p));
            memset(done, 0, sizeof(done));
            dfs2(0,0,p[0][0],i,p);
            dfs(turn+1,p);
        }
    }
}

int solve(){
    ans = 0;
    dfs(0,panel);
    return ans;
}

bool input(){
    cin >> h >> w >> c;
    if(!h and !w and !c) return 0;
    rep(i,h)rep(j,w) cin >> panel[i][j];
    return 1;
}

int main()
{
    while(input()) cout << solve() << endl;
    return 0;
}
