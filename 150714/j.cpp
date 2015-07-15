#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define all(c) begin(c),end(c)
#define max(a, b) (a<b?b:a)
#define min(a, b) (a>b?b:a)
#ifndef DEBUG
const string name = "javacert"; // input filename here!!
ifstream fin(name + ".in");
ofstream fout(name + ".out");
#define cin fin
#define cout fout
#endif

int N, M, K;
char dp[16][128][128][128];
char select[16][128][128][128];
char bj[16][128][128][128];
char bk[16][128][128][128];
char bl[16][128][128][128];
int A[16][128];

const char inf = 127;

void trace(int i, int j, int k, int l) {
    vector<pair<int, int> > v;

    while(i) {
        int tj = bj[i][j][k][l];
        int tk = bk[i][j][k][l];
        int tl = bl[i][j][k][l];
        int x = select[i][j][k][l];
        v.push_back(make_pair(A[i-1][x], x));

        i--;
        j = tj;
        k = tk;
        l = tl;
    }

    reverse(all(v));
    for(auto p : v) {
        cout << p.first << " " << p.second << endl;
    }

}

void solve() {
    cin >> K >> N >> M;
    K = N-K;
    
    vector<int> p(M);
    rep(i, M) {
        cin >> p[i];
    }

    memset(A, -1, sizeof(A));
    rep(i, M) repi(j, 1, N+1) rep(k, j+1) {
        int x;
        if(200*(j-k)%j == 0 and 1000*(j-k)%j%10 == 5) {
            x = 100*(j-k)/j;
            if(x%2) x++;
        }
        else x = round(100.*(j-k)/j) + 0.5;
        if(x == p[i]) A[i][j] = k;
    }
    
    rep(i, M+1) rep(j, 101) rep(k, 101) rep(l, 101) dp[i][j][k][l] = inf;
    
    dp[0][N][0][0] = 0;
    rep(i, M) rep(j, N+1) rep(k, N+1) rep(l, N+1) repi(x, 1, N+1-l) if(A[i][x] != -1 and dp[i][j][k][l] != inf) {
        int nj = min(j, x);
        int nk = k+A[i][x];
        int nl = l+x;
        if(nk > N) continue;
        char &nxt = dp[i+1][nj][nk][nl];
        char tmp = max(dp[i][j][k][l], x);
        if(nxt > tmp) {
            select[i+1][nj][nk][nl] = x;
            bj[i+1][nj][nk][nl] = j;
            bk[i+1][nj][nk][nl] = k;
            bl[i+1][nj][nk][nl] = l;
            nxt = tmp;
        }
    }
    
    char ans = inf;
    rep(j, N+1) if(dp[M][j][K][N] < inf) {
        if(dp[M][j][K][N] - j < ans) {
            ans = dp[M][j][K][N] - j;
        }
    }
    
    rep(j, N+1) if(dp[M][j][K][N] < inf) {
        if(dp[M][j][K][N] - j == ans) {
            trace(M, j, K, N);
            return;
        }
    }
}

int main()
{
    solve();
}
