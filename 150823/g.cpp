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
string s;
const int MAX = 32;
short f[MAX][MAX];
short cf[MAX][MAX];
int ans;
int ini;
int lft[MAX], rght[MAX];

const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

bool inrange(int x, int y) {
    return x >= 0 and x < MAX and y >= 0 and y < MAX;
}

void dfs(int x, int y, int depth, int cnt)
{
    if(s[depth-1] == '1') {
        rep(k, 8) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (inrange(nx, ny) and f[nx][ny] == 1) {
                cnt++;
            }
        }
    }    
    
    if(depth == n) {
        ans = max(ans, cnt);
        return;
    }
    
    if (cnt + rght[depth] * rght[depth] / 2 + rght[depth] * lft[depth] <= ans)
        return;

    rep(k, 8) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (!inrange(nx, ny)) continue;
        if (abs(dx[k]) > 0 and abs(dy[k]) > 0) {
            int lx = min(x, nx);
            int ly = min(y, ny);
            if (cf[lx][ly]) continue;
            cf[lx][ly] = 1;
        }
        
        if (f[nx][ny] == -1) {
            f[nx][ny] = s[depth] - '0';
            dfs(nx, ny, depth+1, cnt);
            f[nx][ny] = -1;
        }
        
        if (abs(dx[k]) > 0 and abs(dy[k]) > 0) {
            int lx = min(x, nx);
            int ly = min(y, ny);
            cf[lx][ly] = 0;
        }
    }
}

void solve()
{
    cin >> n;    
    cin >> s;
    memset(f, -1, sizeof(f));
    memset(cf, 0, sizeof(cf));

    ans = 0;
    
    ini = 0;
    rep(i, n-1) if(s[i] == '1' and s[i+1] == '1') ini++;

    memset(lft, 0, sizeof(lft));
    rep(i, n-1) {
        lft[i+1] = lft[i] + (s[i] - '0');
    }

    memset(rght, 0, sizeof(rght));
    rght[n-1] = s[n-1] - '0';
    repd(i, n-1, 1) {
        rght[i-1] = rght[i] + (s[i-1] - '0');
    }
    
    dfs(MAX/2, MAX/2, 0, -ini);
    cout << ans << endl;
}

int main()
{
    int n;
    cin >> n;
    rep(i, n) solve();
    
    return 0;
}
