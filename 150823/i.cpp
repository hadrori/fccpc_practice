#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
const int MAX_V = 50000;

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

int n;
set<pair<int,pii>> ps;
map<int,int> rid;
map<pii,int> tsid;

int get_rid(int i)
{
    if(rid.count(i)) return rid[i];
    return rid[i] = rid.size()-1;
}

int get_tsid(pii p)
{
    if(tsid.count(p)) return tsid[p];
    return tsid[p] = tsid.size()-1;    
}

int solve()
{
    rid.clear();
    tsid.clear();
    for(auto &p: ps) {
        get_rid(p.first);
        get_tsid(p.second);
    }
    V = rid.size()+tsid.size();
    rep(i,V) G[i].clear();
    for(auto &p: ps) add_edge(rid[p.first], tsid[p.second]+rid.size());
    return bi_matching();
}

void input()
{
    cin >> n;
    ps.clear();
    rep(i,n) {
        int r, t, s, g;
        cin >> r >> t >> s;
        g = __gcd(t,s);
        ps.insert(mp(r,pii(t/g,s/g)));
    }
}

int main()
{
    int t;
    for(cin >> t; t--; ) {
        input();
        cout << solve() << endl;
    }
    return 0;
}
