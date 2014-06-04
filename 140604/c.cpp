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
int n, c, r;

const int MAX = 105;
ll w[MAX][MAX];

ll solve() {
    vector<string> vs(c+1);
    rep(i, c+1) cin >> vs[i];
    vs.pb(vs[0]);
    map<string, int> idx;
    int cnt = -1;
    rep(i, MAX) rep(j, MAX) w[i][j] = 1000000000000LL;
    rep(i, r) {
        string a, b;
        cin >> a;
        char left, right;
        int v;
        scanf(" %c-%d-%c", &left, &v, &right);
        cin >> b;
        //cout << a << " " << b << endl;
        int ia, ib;
        if(idx.find(a) != idx.end()) {
            ia = idx[a];
        } else {
            ia = idx[a] = ++cnt;
        }
        if(idx.find(b) != idx.end()) {
            ib = idx[b];
        } else {
            ib = idx[b] = ++cnt;
        }

        if(left == '<') 
            w[ib][ia] = min(w[ib][ia], (ll)v);
        if(right == '>')
            w[ia][ib] = min(w[ia][ib], (ll)v);
    }

    rep(i, n) w[i][i] = 0;
    rep(k, n) rep(i, n) rep(j, n) w[i][j] = min(w[i][j], w[i][k] + w[k][j]);

    ll ans = 0;
    rep(i, vs.size()-1) {
        ans += w[idx[vs[i]]][idx[vs[i+1]]];
    }
    return ans;
}

int main()
{
    int cnt = 0;
    while(cin >> n >> c >> r, n||c||r) {
        cnt++;
        cout << cnt << ". " << solve() << endl;
    }
    return 0;
}
