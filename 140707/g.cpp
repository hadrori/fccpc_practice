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
#define INF 100000
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
struct edge{
    int x, y;
};

int h, w;
vector<edge> E[32][32];

bool input(){
    cin >> h >> w;
    if(!h and !w) return 0;
    rep(i,32)rep(j,32) E[i][j].clear();
    rep(y,h){
        rep(x,w-1){
            int t; cin >> t;
            if(!t){
                E[x][y].pb((edge){x+1,y});
                E[x+1][y].pb((edge){x,y});
            }
        }
        if(y == h-1) continue;
        rep(x,w){
            int t; cin >> t;
            if(!t){
                E[x][y].pb((edge){x,y+1});
                E[x][y+1].pb((edge){x,y});
            }
        }
    }
    return 1;
}

int doorCost[32][32][4];
struct node {
    int x, y, cst;
};
int calcCost(int sx, int sy, int gx, int gy, int tx, int ty) {
    queue<node> q;
    q.push((node){sx, sy, 0});
    int done[32][32] = {0};
    while(q.size()) {
        int x = q.front().x;
        int y = q.front().y;
        int cst = q.front().cst; q.pop();
        if(done[x][y]) continue;
        done[x][y] = true;
        if(x == gx and y == gy) {
            return cst;
        }
        rep(i, E[x][y].size()) {
            edge &e = E[x][y][i];
            if(x == sx and y == sy and e.x == tx and e.y == ty) continue;
            if(e.x == sx and e.y == sy and x == tx and y == ty) continue;
            q.push((node){e.x, e.y, cst+1});
        }
    }
    return INF;
}

void calcDoorCost() {
    rep(y, h) rep(x, w) rep(i, 4) doorCost[x][y][i] = INF;
    rep(y, h) rep(x, w) {
        rep(i, E[x][y].size()) {
            edge &e = E[x][y][i];
            doorCost[x][y][i] = calcCost(x, y, w-1, h-1, e.x, e.y);
        }
    }
}

struct nd {
    int x, y, cst, step;
    vector<pair<int, int> > route;
    bool operator<(const nd &o) const {
        return cst > o.cst;
    }
};
int solve() {
    calcDoorCost();
    priority_queue<nd> pq;
    pq.push((nd){0, 0, 0, 0,vector<pair<int, int> >()});
    const int lim = 256;
    int done[32][32][lim] = {0};
    int ret = INF;
    while(pq.size()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int cst = pq.top().cst;
        int step = pq.top().step;
        vector<pair<int, int> > route = pq.top().route;
        pq.pop();
        if(step > lim) continue;
        if(done[x][y][step]) continue;
        done[x][y][step] = true;
        if(x == w-1 and y == h-1) {
            /*
            cout << route.size() << endl;
            rep(i, route.size()) {
                cout << route[i].first << " " << route[i].second << endl;
            }
            cout << endl;*/
            ret = min(ret, cst);
            return ret;
        }
        rep(i, E[x][y].size()) {
            edge &e = E[x][y][i];
            vector<pair<int, int> > tv = route;
            tv.pb(mp(x, cst));
            pq.push((nd){e.x, e.y, max(cst, step + doorCost[x][y][i]),step+1, tv});
        }
    }
    return ret;
}

int main()
{
    while(input()){
        int ans = solve();
        if(ans < INF) cout << ans << endl;
        else cout << -1 << endl;
    } 
    return 0;
}
