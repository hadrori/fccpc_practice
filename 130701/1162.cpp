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

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
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
typedef pair<int,int> pii;

int n, m, s, g;
int dv[] = {-1,0,1};

struct S{
    int cur, prev, vel;
    double dist;
    S(int cur, int prev, int vel, double dist):cur(cur),prev(prev),vel(vel),dist(dist){}
    bool operator>(const S &p) const{
        return dist > p.dist;
    }
};

int main() {
    while(cin >> n >> m, n || m){
        cin >> s >> g;
        s--; g--;
        vector<vector<pii> > path(n,vector<pii> (n,mp(INF,INF)));
        rep(i,m){
            int x, y, d, c;
            cin >> x >> y >> d >> c;
            x--; y--;
            path[x][y] = mp(d,c);
            path[y][x] = mp(d,c);
        }

        double d[32][32][32];
        rep(i,32)rep(j,32)rep(k,32) d[i][j][k] = INF;
//        d[s][s][0] = 0;
        priority_queue<S, vector<S>, greater<S> > que;
        que.push(S(s,s,0,0));
        double ans = -1;
        while(!que.empty()){
            S tmp = que.top(); que.pop();
            int cur = tmp.cur, prev = tmp.prev, vel = tmp.vel;
            double dist = tmp.dist;
            if(dist >= d[cur][prev][vel]) continue;
            d[cur][prev][vel] = dist;
            if(vel == 1 && cur == g) {
                ans = dist;
                break;
            }
            rep(i,n)rep(j,3){
                if(i == prev || path[cur][i].first == INF) continue;
                if(vel + dv[j] > 0 && vel + dv[j] <= path[cur][i].second){
                    que.push(S(i,cur,vel+dv[j],dist + 1.0 * path[cur][i].first / (vel+dv[j])));
                }
            }
        }
        if(ans>=0) printf("%.8f\n",ans);
        else cout << "unreachable\n";
    }
    return 0;
}
