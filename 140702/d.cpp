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

int w, h;
const int MAX = 64;
char inp[MAX][MAX];
int f[MAX][MAX];
int done[MAX][MAX];
vector<vector<int> > E;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
bool inrange(int i, int j) {
    return i >= 0 && j >= 0 && i < h && j < w;
}
void dfs_number(int i, int j, char c, int id) {
    if(done[i][j]) return;
    done[i][j] = 1;
    f[i][j] = id;
    rep(k, 4) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if(inrange(ni, nj) && inp[ni][nj] == c)
            dfs_number(ni, nj, c, id);
    }
}

int id;
void numbering() {
    memset(done, 0, sizeof(done));
    memset(f, -1, sizeof(f));
    id = 0;
    rep(i, h) rep(j, w) {
        if(inp[i][j] != '.' && !done[i][j]) dfs_number(i, j, inp[i][j], id++);
    }
}

void input() {
    rep(i, h) rep(j, w) {
        cin >> inp[i][j];
    }
}

void createEdge() {
    E.clear();
    E.resize(id);
    rep(i, h-1) rep(j, w) if(f[i][j] >= 0) {
        if(f[i][j] != f[i+1][j] && f[i+1][j] >= 0)
            E[f[i+1][j]].pb(f[i][j]);
    }
    
    rep(i, id) {
        sort(all(E[i]));
        UNIQUE(E[i]);
    }
}

bool dfs(int now, double &g, int &sum) {
    sum = 0;
    g = 0;
    //rec
    rep(i, E[now].size()) {
        int to = E[now][i];
        double tg;
        int tsum;
        if(!dfs(to, tg, tsum)) {
            //cout << now << ": child is unstable" << endl;
            return false;
        }
        sum += tsum;
        g += tg * tsum;
    }

    //myself
    double xl = 10000, xr = -10000;
    rep(i, h) rep(j, w) {
        if(now == f[i][j]) {
//            cout << j+0.5 << endl;
            sum += 1;
            g += j+0.5;
            if((i <= h-2 && f[i+1][j] >= 0 && f[i+1][j] != f[i][j]) || i == h-1) {
                xl = min(xl, j+0.0);
                xr = max(xr, j+1.0);
            }
        }
    }
    g /= sum;
    //cout <<g << " " << sum << " " << xl << " " << xr << endl;
    //if(!(xl < g - EPS && g + EPS < xr)) cout << now << ": unstable" << endl;
    return xl < g - EPS && g + EPS < xr;
}

void solve() {
    rep(j, w) if(f[h-1][j] >= 0) {
        double g;
        int sum;
        if(dfs(f[h-1][j], g, sum)) cout << "STABLE" << endl;
        else cout << "UNSTABLE" << endl;
        break;
    }
}

int main()
{
    while(cin >> w >> h, w||h) {
        input();
        numbering();
        /*
        cout << "====================" << endl;
        rep(i, h) {
            rep(j, w) if(f[i][j] >= 0) cout << f[i][j] << " ";
            else cout << ". ";
            cout << endl;
        }
        cout << "====================" << endl;
        */
        createEdge();
        solve();
    }
    
    return 0;
}
