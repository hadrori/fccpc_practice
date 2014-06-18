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

const int MAX_V = 1024;
int  V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v){
    used[v] = 1;
    rep(i,G[v].size()){
        int u = G[v][i], w = match[u];
        if(w < 0 || !used[w] && dfs(w)){
            match[v] = u;
            match[u] = v;
            return 1;
        }
    }
    return 0;
}

int bi_matching(){
    int res = 0;
    memset(match, -1, sizeof(match));
    rep(v,V) if(match[v] < 0){
        memset(used, 0, sizeof(used));
        if(dfs(v)) res++;
    }
    return res;
}

int b[512], r[512], n, m;

int solve(){
    rep(i,m) rep(j,n) if(__gcd(b[i],r[j]) > 1) add_edge(i,m+j);
        
    return bi_matching();
}

int main()
{
    while(cin >> m >> n, m or n){
        rep(i,m) cin >> b[i];
        rep(i,n) cin >> r[i];
        V = m+n;
        rep(i,MAX_V) G[i].clear();
        cout << solve() << endl;
    }
    return 0;
}
