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

const int N = 210;
const int M = N * (N-1) / 2;

const double inf = 1e12;

struct edge {
    int to, d, v;
    edge(int to, int d, int v) : to(to), d(d), v(v) {}
};

long n, m, p;
vector<vector<edge>> G;
double best[N];

double solve()
{
    const double ideal = 1e4;
    struct entry {
        int v, d; double w;
        entry(int v, int d, double w) : v(v), d(d), w(w) {}
        bool operator <(const entry& o) const { return w > o.w; }
    };
    vector<vector<int>> ved(n, vector<int>(p+1));
    vector<vector<double>> loss(n, vector<double>(p+1, inf));
    priority_queue<entry> que;
    loss[0][0] = 0.0, que.emplace(0, 0, 0.0);
    while (not que.empty()) {
        entry cur = que.top(); que.pop();
        if (loss[cur.v][cur.d] < cur.w) continue;
        if (ved[cur.v][cur.d]) continue;
        ved[cur.v][cur.d] = 1;
        for (auto& e : G[cur.v]) {
            int nv = e.to;
            int np = cur.d + e.d;
            double nw = cur.w + ideal * e.d - e.v;
            if (not ved[nv][np] and nw >= cur.w and 2 * np <= p and loss[nv][np] > nw) {
                loss[nv][np] = nw, que.emplace(nv, np, nw);
            }
        }
    }
    double ans = -inf;
    rep(i, n) rep(j, p/2+1) {
        double t = ideal * p;
        t -= 2 * loss[i][j] + (ideal - best[i]) * (p - 2*j);
        ans = max(ans, t);
    }
    return ans;
}

int main()
{
    cin >> n >> m >> p;
    G.assign(n, vector<edge>());
    rep(i, m) {
        int s, t, d, v;
        cin >> s >> t >> d >> v, --s, --t;
        G[s].emplace_back(t, d, v);
        G[t].emplace_back(s, d, v);
        best[s] = max(best[s], double(v) / d);
        best[t] = max(best[t], double(v) / d);
    }
    cout << fixed << setprecision(10)
         << solve() << endl;
    
    return 0;
}
