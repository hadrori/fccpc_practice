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
typedef pair<int,int> pii;
vector<pii> G[2048];
vi seq;
int V, C, X, Y;
bool locked[2048];

bool rec(int s, int t){
    int from[2048], to[2048];
    memset(from, -1, sizeof(from));
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        rep(i,G[v].size()) if(from[G[v][i]] != -1){
            from[G[v][i]] = v;
            q.push(G[v][i]);
        }
    }
    int cur = t;
    while(cur != s) {
        to[from[cur]] = cur;
        cur = from[cur];
    }

}

void solve(){
    bfs(X, Y);
    rec(X,Y);
}

bool input(){
    cin >> V >> C >> X >> Y;
    if(!V) return 0;
    rep(i,C){
        cin >> keys[i];
        locked[i] = 1;
    }
    rep(i,V) G[i].clear();
    rep(i,V-1){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].pb(pii(b,c));
        G[b].pb(pii(a,c));
        if()
    }
    return 1;
}

int main()
{
    while(input()) solve();
    return 0;
}
