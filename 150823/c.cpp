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

int n;
int f[32][32];
map<int, int> tbl;

bool inrange(int x, int y) 
{
    return x >= 0 and x < n and y >= 0 and y < n;
}

void put(int x, int y, int d)
{
    set<pair<int, int> > st;
    for(int dx = -2; dx <= 2; dx++) {
        for(int dy = -2; dy <= 2; dy++) {
            for(int r = 0; r < n; r++) {
                int tx = x + dx*r;
                int ty = y + dy*r;
                if(inrange(tx, ty)) {
                    st.insert(mp(tx, ty));
                }
            }
        }
    }

    for (pair<int, int> p : st) {
        int tx = p.first, ty = p.second;
        f[tx][ty] += d;
    }
}

bool canPut(int x, int y)
{
    return f[x][y] == 0;
}

void put(int x, int y)
{
    put(x, y, 1);
}

void remove(int x, int y)
{
    put(x, y, -1);
}

void print()
{
    rep(x, n) {
        rep(y, n) {
            cout << f[x][y] << " ";
        }
        cout << endl;
    }
        
    cout << endl;
}
void dfs(int x, int y, int depth, int num)
{
    //cout << x << " " << y << " " << depth << " " << num << endl;
    //print();
    
    if(y == n) {
        dfs(x+1, 0, depth, num);
        return;
    }
    if(x == n) {
        tbl[num]++;
        return;
    }
    
    if(canPut(x, y)) {
        put(x, y);
        dfs(x, y+1, depth+1, num+1);
        remove(x, y);
    }
    
    dfs(x, y+1, depth+1, num);
}
void solve()
{
    memset(f, 0, sizeof(f));
    tbl.clear();
    
    cin >> n;
    int m;    
    cin >> m;
    int ini = 0;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        put(x, y);
        ini++;
    }

    
    dfs(0, 0, 0, 0);
    int ans = 0, cnt = 0;
    for (pair<int, int> p : tbl) {
        ans = p.first;
        cnt = p.second;
    }
    cout << ans + ini << " " << cnt << endl;
}

int main()
{
    int n;
    cin >> n;
    rep(i, n) solve();
    return 0;
}
