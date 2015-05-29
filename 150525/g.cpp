#include <bits/stdc++.h>
using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) _repi(i,0,n)
#define _repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)

struct edge {
    string to;
    double rate;
    edge(string to, double rate) : to(to), rate(rate) {}
};

int n;
map<string, vector<edge>> G;
double a0;
string s0;

void input()
{
    G.clear();
    rep(i, n) {
        double a, b;
        string s, t;
        (cin >> a >> s >> ws).ignore() >> b >> t;
        G[s].emplace_back(t, a / b);
        G[t].emplace_back(s, b / a);
    }
    cin >> a0 >> s0;
}

const int N = 100000;

void solve()
{
    set<string> ved;
    queue<pair<string, double>> que;
    que.emplace(s0, 1.0);
    tuple<double, string, int> ans{1e16, "", -1};
    while (not que.empty()) {
        string s;
        double r;
        tie(s, r) = que.front();
        que.pop();
        if (s != s0) {
            int t = ceil(a0 / r - 1e-9);
            if (t <= N) ans = min(ans, make_tuple(t * r - a0, s, t));
        }
        ved.insert(s);
        for (auto p : G[s]) {
            if (ved.find(p.to) == ved.end()) {
                que.emplace(p.to, r * p.rate);
            }
        }
    }
    cout << get<2>(ans) << ' ' << get<1>(ans) << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t = 0;
    while (cin >> n, n) {
        cout << "Case " << ++t << ": ";
        input();
        solve();
    }
}
