#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

char f[32][32];

struct continent {
    int i, j;
    char f[32][32];
};
vector<continent> cont;

continent getCont(int i, int j) {
    const int di[] = {0, 1, 0,-1};
    const int dj[] = {1, 0,-1, 0};
    continent ret;
    ret.i = i, ret.j = j;
    memset(ret.f, '.', sizeof(ret.f));
    stack<pair<int, int> > stk;
    stk.push(mp(i, j));
    while(stk.size()) {
        int ni = stk.top().first;
        int nj = stk.top().second;
        stk.pop();
        if(ni < 0 or nj < 0 or 1 > 2 or 1 > 2 or ni >= 20 or nj >= 20) continue;
        if(f[ni][nj] == '.') continue;
        f[ni][nj] = '.';
        if(ni - i >= 5 or nj - j >= 5) {
            ret.i = ret.j = -1;
            return ret;
        }
        ret.f[ni-i][nj-j] = 'x';

        rep(k, 4) {
            stk.push(mp(ni+di[k], nj+dj[k]));
        }
    }
    
    return ret;
}

void input() {
    rep(i, 20) rep(j, 20) cin >> f[i][j];
    cont.clear();
    rep(i, 20) rep(j, 20) {
        if(f[i][j] == 'x') cont.pb(getCont(i, j));
    }

}

int solve() {
    input();
    int n = cont.size();
    rep(i, n) if(cont[i].i == -1) return -1;
    
    vector<int> v(n);
    rep(i, n) v[i] = i;
    const int INF = 100000000;
    int ans = INF;
    do {
        char small[5][5];
        memset(small, '.', sizeof(small));
        bool ok = true;
        vector<pair<int, int> > pos(n);
        rep(t, n) {
            int id = v[t];
            continent &c = cont[id];
            bool done = false;
            rep(i, 5) {
                rep(j, 5) if(small[i][j] == '.') {
                    rep(ni, 5) rep(nj, 5) if(c.f[ni][nj] == 'x') {
                        if(i+ni >= 0 and j+nj >= 0 and i+ni < 5 and j+nj < 5) {
                            small[i+ni][j+nj] = 'x';
                        } else ok = false;
                    }
                    pos[id] = mp(i, j);
                    done = true;
                    break;
                }
                if(done) break;
            }
        }
        if(!ok) continue;
        
        rep(i, 5) rep(j, 5) if(small[i][j] != 'x') ok = false;
        if(!ok) continue;

        rep(i, 16) rep(j, 16) {
            int tmp = 0;
            rep(k, n)
                tmp += abs(cont[k].i - (pos[k].first+i)) + abs(cont[k].j - (pos[k].second+j));
            ans = min(ans, tmp);
            
            /*if(ans == tmp) {
                cout << i << " " << j << endl;
                rep(k, n) {
                    cout << k << " " << pos[k].first << " " << pos[k].second << " " << cont[k].i << " " << cont[k].j << " " << abs(cont[k].i - (pos[k].first+i)) + abs(cont[k].j - (pos[k].second+j)) << endl;
                }
                cout << ans << endl;
                cout << endl;
            }
            */
        }
    } while (next_permutation(all(v)));
    if(ans == INF) return -1;
    return ans;
}

int main()
{
    int T;
    cin >> T;
    rep(i, T) {
        cout << "Case " << i+1 << ": ";
        int ans = solve();
        if(ans >= 0) cout << ans << endl;
        else cout << "invalid data" << endl;
    }
    return 0;
}
