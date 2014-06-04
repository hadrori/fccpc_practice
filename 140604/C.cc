#include <algorithm>
#include <cassert>
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
#define pb push_back

using namespace std;
const int INF = 1e9;
inline void f(int &a, int b){ a=min(a,b);}
int w[128][128], N, C, R;
char l, r;
string cm;
vector<string> br;
map<string,int> id;

int solve(){
    rep(i,N) w[i][i] = 0;
    rep(k,N)rep(i,N)rep(j,N) f(w[i][j],w[i][k]+w[k][j]);
    int ans = 0;
    rep(i,C) ans += w[id[cm]][id[br[i]]]+w[id[br[i]]][id[cm]];
    return ans;
}

void init(){
    id.clear(); br.clear();
    rep(i,N)rep(j,N) w[i][j] = INF;
}

bool input(){
    cin >> N >> C >> R;
    if(!N) return 0;
    init();
    string a, b;
    cin >> cm;
    rep(i,C){
        cin >> a;
        br.pb(a);
    }
    int idx = 0, v;
    rep(i,R){
        cin >> a;
        scanf(" %c-%d-%c", &l, &v, &r);
        cin >> b;
        if(!id.count(a)) id[a] = idx++;
        int ia = id[a];
        if(!id.count(b)) id[b] = idx++;
        int ib = id[b];
        if(l=='<') f(w[ib][ia],v);
        if(r=='>') f(w[ia][ib],v);
    }
    return 1;
}

int main()
{
    int T = 0;
    while(input()) cout << ++T << ". " << solve() << endl;
    return 0;
}
