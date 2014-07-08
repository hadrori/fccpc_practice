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

const int MAX_V = 20000;

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

int bi_matching(int V){
    int res = 0;
    memset(match, -1, sizeof(match));
    rep(v,V) if(match[v] < 0){
        memset(used, 0, sizeof(used));
        if(dfs(v)) res++;
    }
    return res;
}

struct line{
    int sx, sy, tx, ty;
};

vector<line> hol, vir;

int h, w, c[128][128];

inline bool isJ(int i, int j){ return !c[i][j] and c[i+1][j] and c[i][j+1] and c[i+1][j+1];}
inline bool isL(int i, int j){ return c[i][j] and c[i+1][j] and !c[i][j+1] and c[i+1][j+1];}
inline bool is7(int i, int j){ return c[i][j] and !c[i+1][j] and c[i][j+1] and c[i+1][j+1];}
inline bool isF(int i, int j){ return c[i][j] and c[i+1][j] and c[i][j+1] and !c[i+1][j+1];}
inline bool isl(int i, int j){ return c[i][j] and c[i+1][j] and !c[i][j+1] and !c[i+1][j+1];}
inline bool ism(int i, int j){ return c[i][j] and !c[i+1][j] and c[i][j+1] and !c[i+1][j+1];}


int count_corner(){
    int ret = 0;
    rep(i,h-1)rep(j,w-1)
        if(isJ(i,j) or isL(i,j) or is7(i,j) or isF(i,j)) ret++;
    return ret;
}

inline bool intersect(int i, int j){ // hol[i] , vir[j]
    return hol[i].sx <= vir[j].sx and vir[j].sx <= hol[i].tx and
           vir[j].sy <= hol[i].sy and hol[i].sy <= vir[j].ty;
}

void build_edge(){
    rep(i,hol.size())rep(j,vir.size())
        if(intersect(i,j)) add_edge(i,hol.size()+j);
}

void build_line(){
    rep(i,h-1)rep(j,w-1){
        if(isJ(i,j) or is7(i,j))
            repi(nj,j+1,w-1)
                if(isl(i,nj)) break;
                else if(isF(i,nj) or isL(i,nj)){
                    hol.pb((line){j,i,nj,i});
                    break;
                }
        if(isJ(i,j) or isL(i,j))
            repi(ni,i+1,w-1)
                if(ism(ni,j)) break;
                else if(isF(ni,j) or is7(ni,j)){
                    vir.pb((line){j,i,j,ni});
                    break;
                }
    }
}

void debug_lines(){
    cerr << "hol lines:" << endl;
    rep(i,hol.size())
        cerr << "\t" << hol[i].sx << ' ' << hol[i].sy << ' ' << hol[i].tx << ' ' << hol[i].ty << endl;
        
    cerr << "vir lines:" << endl;
    rep(i,vir.size())
        cerr << "\t" << vir[i].sx << ' ' << vir[i].sy << ' ' << vir[i].tx << ' ' << vir[i].ty << endl;
        
}

void debug_bi_edges(){
    cerr << "hol to vir:" << endl;
    rep(i,hol.size()){
        cerr << i << " -> " << endl;
        rep(j,G[i].size())
            cerr << "\t" << G[i][j] << endl;
    }
}

int solve(){
    build_line();
    build_edge();
    int sz = hol.size()+vir.size();
//    debug();
//    cerr << "number of conrner : " << count_corner() << endl;
//    debug_bi_edges();
    return count_corner() - sz + bi_matching(sz) + 1;
}

void init(){
    memset(c,0,sizeof(c));
    hol.clear();
    vir.clear();
    rep(i,MAX_V) G[i].clear();
}

bool input(){
    cin >> h >> w;
    if(!h and !w) return 0;
    init();
    rep(i,h) rep(j,w){
        char ch; cin >> ch;
        if(ch == '#') c[i][j] = 1;
    }
    return 1;
}

int main()
{
    while(input()) cout << solve() << endl;
    return 0;
}
