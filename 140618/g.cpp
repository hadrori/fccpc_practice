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

struct edge{ int to, cap, d;};
struct node{
    int p, v, prev; double d;
    node(int p, int v, int prev, double d):p(p),v(v),prev(prev),d(d){}
    bool operator<(const node &n)const{ return d > n.d;}
};
const int dv[] = {-1,0,1};
int done[32][32][32], N, M, s, t;
double dist[32][32][32];
vector<edge> G[32];

void solve(){
    priority_queue<node> q;
    q.push(node(s,0,s,0));
    while(!q.empty()){
        node u = q.top(); q.pop();
        if(done[u.p][u.v][u.prev]) continue;
        if(u.p == t and u.v == 1){
            printf("%.8f\n", u.d);
            return;
        }
        done[u.p][u.v][u.prev] = 1;
        dist[u.p][u.v][u.prev] = u.d;
        rep(i,G[u.p].size()){
            edge &e = G[u.p][i];
            if(e.to == u.prev) continue;
            rep(j,3){
                int nv = u.v + dv[j];
                if(nv > 0 and nv <= e.cap)
                    q.push(node(e.to, nv, u.p, 1.*e.d/nv+u.d));
            }
        }
    }
    puts("unreachable");
}

void input(){
    cin >> s >> t;
    s--; t--;
    rep(i,M){
        int x, y, d, c; cin >> x >> y >> d >> c;
        x--; y--;
        G[x].pb((edge){y,c,d});
        G[y].pb((edge){x,c,d});
    }
}

void init(){
    rep(i,32) G[i].clear();
    memset(done, 0, sizeof(done));
}

int main()
{
    while(cin  >> N >> M, N or M){
        init();
        input();
        solve();
    }
    return 0;
}
