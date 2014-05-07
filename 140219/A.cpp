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
#define inf 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int T, fx, fy, tx, ty, M, ans;
vector<pii> m;
bool dist[10010][10010];

void init(){
    m.clear();
    ans = inf;
    memset(dist,0,sizeof(dist));
}

void input(){
    cin >> fx >> fy >> tx >> ty >> M;
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        m.pb(pii(x, y));
    }
}


void bfs(){
    queue<pair<pii,int> > que;
    que.push(mp(pii(fx, fy),0));
    while(!que.empty()){
        int x = que.front().first.first, y = que.front().first.second;
        int s = que.front().second;
        que.pop();
        if(x < 0 || x > 10020 || y < 0 || y > 10020) continue;
        if(dist[x][y]) continue;
        dist[x][y] = 1;
        if(x == tx && y == ty){
            ans = s;
            return;
        }
        for(int i = 0; i < M; i++){
            int nx = x+m[i].first, ny = y+m[i].second;
            que.push(mp(pii(nx, ny), s+1));
        }
    }
}

void solve(){
    bfs();
    if(ans == inf) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}

int main()
{
    cin >> T;
    while(T--){
        init();
        input();
        solve();
    }
    return 0;
}
