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

using namespace std;

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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n, m;
int rnk[512];
pii rev[25010];
int to[512][512];

void input()
{
    cin >> n;
    rep(i,n){
        cin >> rnk[i];
        rnk[i]--;
    }
    cin >> m;
    rep(i,m){
        int a, b; cin >> a >> b;
        rev[i] = pii(a-1, b-1);
    }
}

int ans[512];
int visited[512];

bool rec(int v, int s){
    if(visited[v] and v == s) return 0;
    if(visited[v]) return 1;
    visited[v] = 1;
    bool ok = 1;
    rep(i,n) if(to[v][i]) {
        ok = rec(i,s);
        if(!ok) return 0;
    }
    return 1;
}

void dfs(int v, int &k){
    visited[v] = 1;
    rep(i,n) if(to[v][i] and !visited[i]) dfs(i, k);
    ans[k++] = v;
}

void solve()
{
    memset(to, 0, sizeof(to));
    memset(visited, 0, sizeof(visited));
    rep(i,n) repi(j,i+1,n) to[rnk[i]][rnk[j]] = 1;
    rep(i,m){
        int a = rev[i].first, b = rev[i].second;
        swap(to[a][b], to[b][a]);
    }
    rep(i,n){
        memset(visited, 0, sizeof(visited));
        if(!rec(i, i)){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    int k = 0;
    memset(visited, 0, sizeof(visited));
    rep(i,n) if(!visited[i]) dfs(i, k);
    reverse(ans, ans+n);
    rep(i,n) cout << ans[i]+1 << (i==n-1?'\n':' ');
    return;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        input();
        solve();
    }

    return 0;
}
