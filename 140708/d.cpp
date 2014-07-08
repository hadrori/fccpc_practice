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

int n, m, C, s, g;

struct edge {
    int to, c, d;
};
vector<vector<edge> > E;
vector<vector<int> > q;
vector<vector<int> > r;
vector<vector<int> > sum;

bool input() {
    cin >> n >> m >> C >> s >> g;
    if(!(n||m||C||s||g)) return false;
    s--; g--;
    E.clear();
    E.resize(n);
    // edge
    rep(i, m) {
        int x, y, d, c;
        cin >> x >> y >> d >> c;
        x--; y--; c--;
        E[x].pb((edge){y, c, d});
        E[y].pb((edge){x, c, d});
    }

    // lines
    q.clear();
    vector<int> p(C);
    rep(i, C) cin >> p[i];
    r.clear();
    rep(i, C) {
        vector<int> tq(p[i]+1);
        rep(j, p[i]-1) cin >> tq[j+1];
        tq[0] = 0;
        tq[p[i]] = INF;
        q.pb(tq);
        
        vector<int> tr(p[i]);
        rep(j, p[i]) cin >> tr[j];
        r.pb(tr);
    }

    // clac sum
    sum.clear();
    sum.resize(C);
    rep(c, C) {
        sum[c].resize(r[c].size()+1);
        rep(i, sum[c].size()-1) {
            sum[c][i+1] = sum[c][i] + (q[c][i+1] - q[c][i]) * r[c][i];
        }
    }
    
    return true;
}

struct node {
    int now, company, dist, cst;
    bool operator<(const node &o) const {
        return cst > o.cst;
    }
};

int f(int c, int dst) {
    int pos = upper_bound(all(q[c]), dst) - q[c].begin();
    pos--;
    return sum[c][pos] + r[c][pos] * (dst - q[c][pos]);
}

int solve() {
    priority_queue<node> pq;
    pq.push((node){s, C, 0, 0});
    vector<vector<set<int> > > done(n, vector<set<int> >(C+1, set<int>()));
    while(pq.size()) {
        int now = pq.top().now;
        int company = pq.top().company;
        int dist = pq.top().dist;
        int cst = pq.top().cst;
        pq.pop();
        int lim = 10000;
        if(company < C) lim = *(q[company].end()-2);
        if(done[now][company].find(min(lim+1, dist)) != done[now][company].end()) continue;
        done[now][company].insert(min(lim+1,dist));

        if(now == g) {
            return cst;
        }
        
        rep(i, E[now].size()) {
            edge &e = E[now][i];
            int ncst, ndist;
            if(e.c == company) {
                ndist = dist + e.d;
                ncst = cst + f(e.c, ndist) - f(e.c, dist);
            } else {
                ndist = e.d;
                ncst = cst + f(e.c, ndist);
            }
            pq.push((node){e.to, e.c, ndist, ncst});
        }
    }
    return -1;
}

int main()
{
    
    while(input()) {
        cout << solve() << endl;
    }
    
    return 0;
}
