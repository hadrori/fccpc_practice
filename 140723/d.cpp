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

using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;
int n, m, q;
int f[4][1024][1024];

int ch_i(int i, int j, int t) {
    if(t == 0) return i;
    if(t == 1) return j;
    if(t == 2) return n-i-1;
    if(t == 3) return m-j-1;
    return -1;
}

int ch_j(int i, int j, int t) {
    if(t == 0) return j;
    if(t == 1) return n-i-1;
    if(t == 2) return m-j-1;
    if(t == 3) return i;
    return -1;
}

void input() {
    rep(i, n) rep(j, m) {
        cin >> f[0][i][j];
    }
    n = m = max(n, m);
    rep(t, 4) rep(i, n) rep(j, m) f[t][ch_i(i, j, t)][ch_j(i, j, t)] = f[0][i][j];
}

struct bit {
    vector<int> data;
    bit(int n) {
        data = vector<int>(n+1);
    }

    void renew(int k, int x) {
        k++;
        while(k < data.size()) {
            data[k] += x;
            k += k&-k;
        }
    }

    int sum(int k) {
        k++;
        int ret = 0;
        while(k) {
            ret += data[k];
            k -= k&-k;
        }
        return ret;
    }

    int sum(int l, int r) {
        return sum(r)-sum(l-1);
    }
};

void solve() {
    vector<vector<bit> > bv(4, vector<bit>(n, n));
    rep(t, 4) rep(i, n) {
        rep(j, n) if(f[t][i][j]) bv[t][i].renew(j, 1);
    }
    
    rep(_, q) {
        int op, ti, tj;
        cin >> op >> ti >> tj;
        ti--; tj--;
        if(op == 1) {
            rep(t, 4) {
                int ni = ch_i(ti, tj, t), nj = ch_j(ti, tj, t);
                if(f[t][ni][nj]) {
                    bv[t][ni].renew(nj, -1);
                    f[t][ni][nj] = 0;
                } else {
                    bv[t][ni].renew(nj, 1);
                    f[t][ni][nj] = 1;
                }
            }
        } else {
            int ans = 0;
            rep(t, 4) {
                int ni = ch_i(ti, tj, t), nj = ch_j(ti, tj, t);
                vector<int> v1, v2;
                int j = n-1;
                repi(i, ni, n) {
                    while(j >= nj and bv[t][i].sum(nj, j) != (j-nj+1)) j--;
                    if(j-nj+1 > 0) v1.pb(j-nj+1);
                }
                j = 0;
                repi(i, ni, n) {
                    while(j <= nj and bv[t][i].sum(j, nj) != (nj-j+1)) j++;
                    if(nj-j+1 > 0) v2.pb(nj-j+1);
                }
                rep(i, v1.size()) {
                    ans = max(ans, (v1[i]+v2[i]-1)*(i+1));
                }
            }
            cout << ans << endl;
        }
    }
}

int main()
{
    cin >> n >> m >> q;
    input();
    solve();
    return 0;
}
