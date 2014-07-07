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

struct cp {
    int a, b;
    vector<int> ul;
};
struct circle {
    int x, y, r, c;
};
char done[1<<24];
vector<cp> pl;
int n;

bool intersect(circle &c1, circle &c2) {
    int dx = c1.x - c2.x;
    int dy = c1.y - c2.y;
    int dst2 = dx*dx + dy*dy;
    return dst2 < (c1.r + c2.r) * (c1.r + c2.r);
}

bool get(int state, int pos) {
    return (state>>pos)&1;
}

int dfs(int state) {
    int ret = n - __builtin_popcount(state);
    if(state == 0) return ret;
    if(done[state]) return 0;
    done[state] = 1;

    rep(i, pl.size()) {
        if(get(state, pl[i].a) and get(state, pl[i].b)) {
            bool ok = true;
            vector<int> &ul = pl[i].ul;
            rep(j, ul.size()) {
                if(get(state, ul[j])) ok = false;
            }
            if(ok) {
                int next_state = state;
                next_state -= (1<<pl[i].a);
                next_state -= (1<<pl[i].b);
                ret = max(ret, dfs(next_state));
            }
        }
    }
    return ret;
}

int main()
{
    while(cin >> n, n) {
        memset(done, 0, sizeof(done));
        vector<circle> cv;
        rep(i, n) {
            int x, y, r, c;
            cin >> x >> y >> r >> c;
            cv.pb((circle){x, y, r, c});
        }

        pl.clear();
        rep(i, n) repi(j, i+1, n) if(cv[i].c == cv[j].c && !intersect(cv[i], cv[j])){
            cp tcp;
            tcp.a = i, tcp.b = j;
            rep(k, n) if((k < i && intersect(cv[k], cv[i])) or
                         (k < j && intersect(cv[k], cv[j]))) tcp.ul.pb(k);
            pl.pb(tcp);
        }

        cout << dfs((1<<n) - 1) << endl;
    }

    
    return 0;
}
