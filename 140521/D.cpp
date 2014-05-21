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

const int N = 100;

int n, m, a[N], b[N];

char ans[N][N];

void input()
{
    rep(i, n) cin >> a[i];
    rep(j, m) cin >> b[j];
}

int mra[N], mrb[N];

bool recur(int i, int j)
{
    if (i == n) return true;
    if (j == m) {
        ans[i][j] = '\0';
        return recur(i + 1, 0);
    }
    if(a[i] == 0 || b[j] == 0) {
        ans[i][j] = 'N';
        return recur(i, j+1);
    }
    
    int ra = mra[i], rb = mrb[j];

//    repi(ii, i, n) if (a[ii]) ++ra;
//    repi(jj, j, m) if (b[jj]) ++rb;
    
    if (a[i] > rb or b[j] > ra) return false;
    if (a[i] == rb or b[j] == ra) {
        ans[i][j] = 'Y';
        --a[i], --b[j];
        return recur(i, j+1);
    }
    
    ans[i][j] = 'N';
    if (!recur(i, j + 1)) {
        ans[i][j] = 'Y';
        --a[i], --b[j];
        return recur(i, j+1);
    }
    return true;
}

bool slv() {

    vector<vector<int> > rema(n, vector<int>(m));
    vector<vector<int> > remb(n, vector<int>(m));
    rep(i, n) if(b[0]) rema[i][0] = 1;
    rep(j, n) if(a[0]) remb[0][j] = 1;
    
    rep(i, n) repd(j, m-1, 1) rema[i][j-1] = rema[i][j] + (b[j-1]?1:0);
    rep(j, n) repd(i, n-1, 1) remb[i-1][j] = remb[i][j] + (a[i-1]?1:0);
    
    rep(i, n) {
        rep(j, m) {
            if(a[i] && b[j] && (a[i] == rema[i][j] or b[j] == remb[i][j])) {
                ans[i][j] = 'Y';
                a[i]--; b[j]--;
            } else ans[i][j] = 'N';
        }
    }
    return true;
}

bool solve()
{
    int s = 0;
    rep(i, n) s += a[i];
    rep(j, m) s -= b[j];
    if (s) return false;

    int t = 0, p = 0;
    rep(i, n) if (a[i]) ++t;
    rep(j, m) if (b[j]) ++p;

    rep(i, n) if (a[i] > p) return false;
    rep(j, m) if (b[j] > t) return false;

    memset(mra, 0, sizeof(mra));
    memset(mrb, 0, sizeof(mrb));
    rep(i, n) mra[i] = n-i-count(a+i, a+n, 0);
    rep(j, m) mrb[j] = m-j-count(b+j, b+m, 0);
//    return slv();
    return recur(0, 0);
}

int main()
{
    while (cin >> n >> m and n) {
        input();
        bool a = solve();
        if (not a) {
            cout << "Impossible" << endl;
        } else {
            rep(i, n) cout << ans[i] << endl;
        }
        cout << endl;
    }

    return 0;
}
