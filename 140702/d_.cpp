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
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const string st = "STABLE", ust = "UNSTABLE";
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1};
const double eps = 1e-9;
struct S{ int id, i, j;};

int w, h;
int blk[64][16], done[64][16], wei[16], l[16], r[16], visited[64][16], checked[16];

inline bool in(int i, int j){ return i >= 0 and i < h and j >= 0 and j < w;}

void search(int i, int j, int id, vector<S> &to){
    done[i][j] = 1;
    wei[j]++;
    l[id] = l[id]<0? j: min(l[id],j);
    r[id] = max(r[id],j);
    rep(d,4){
        int ni = i + di[d], nj = j + dj[d];
        if(!in(ni,nj) or !blk[ni][nj]) continue;
        if(d==2 and blk[ni][nj] != id) to.pb((S){ni,nj,blk[ni][nj]});
        if(blk[ni][nj] == id and !done[ni][nj]) search(ni,nj,id,to);
    }
}

bool dfs(int i, int j, int id){
    vector<S> to;
    search(i,j,id,to);
    rep(a,to.size())if(!checked[to[a].id]){
        checked[to[a].id] = 1;
        if(!dfs(to[a].i,to[a].j,to[a].id)) return 0;
    }
    int sum = 0;
    double cent = 0.;
    rep(c,w) sum += wei[c], cent += wei[c]*c;
    cent /= sum;
    return l[id]+eps<cent and cent < r[id]-eps;
}

string solve(){
    memset(done,0,sizeof(done));
    memset(visited,0,sizeof(visited));
    memset(checked,0,sizeof(checked));
    memset(wei,0,sizeof(wei));
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    rep(j,w)if(blk[h-1][j])
        return dfs(h-1,j,blk[h-1][j])? st: ust;
}

bool input(){
    cin >> w >> h;
    if(!w and !h) return 0;
    rep(i,h){
        string s; cin >> s;
        rep(j,w)
            if(s[j] == '.') blk[i][j] = 0;
            else blk[i][j] = s[j]-'0';
    }
    return 1;
}

int main()
{
    while(input()) cout << solve() << endl;
    return 0;
}
