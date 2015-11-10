#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define pb push_back
#define all(u) begin(u),end(u)
#define mp make_pair
#define long int64_t

const int N = 500010;

int n, x[N], y[N];
char op[N];
vector<pair<int,int>> ps;

void input() {
    cin >> n;
    rep(i, n) cin >> op[i] >> x[i] >> y[i], y[i] = -y[i];
    ps.clear();
    rep(i, n) if (op[i] == '+') {
        ps.emplace_back(x[i], y[i]);
    }
    sort(all(ps));
    for(auto p: ps)cerr<<p.first<<','<<p.second<<' ';cerr<<endl;
}

struct node {
    int a, b;
    node *l, *r;
    vector<int> ys, bit;
    node(int a, int b) : a(a), b(b) {}
};
inline int minx(node *v) { return ps[v->a].first; }
inline int maxx(node *v) { return ps[v->b - 1].first; }
node *construct_node(int a, int b) {
    if (a == b) return NULL;
    node *ret = new node(a, b);
    if (a == b-1) {
        ret->ys.push_back(ps[a].second);
        ret->bit.push_back(0);
    } else {
        int m = (a + b) / 2;
        if (ret->l = construct_node(a, m)) {
            ret->ys.insert(ret->ys.end(), all(ret->l->ys));
        }
        if (ret->r = construct_node(m, b)) {
            ret->ys.insert(ret->ys.end(), all(ret->r->ys));
        }
        sort(all(ret->ys));
        ret->bit.resize(b - a);
    }
    return ret;
}

void insert(node *v, int x, int y) {
    if (!v) return;
    if (mp(x, y) < ps[v->a]) return;
    if (mp(x, y) > ps[v->b - 1]) return;
    int k = lower_bound(all(v->ys), y) - v->ys.begin();
    for (++k; k < int(v->bit.size()); k += k & -k) {
        ++v->bit[k-1];
    }
    insert(v->l, x, y);
    insert(v->r, x, y);
}

int query(node *v, int x, int y) {
    if (!v) return 0;
    if (minx(v) > x) return 0;
    if (maxx(v) <= x) {
        int ret = 0, k = upper_bound(all(v->ys), y) - v->ys.begin();
        for (; k; k &= k - 1) {
            ret += v->bit[k-1];
        }
        return ret;
    }
    return query(v->l, x, y) + query(v->r, x, y);
}

void solve() {
    node *root = construct_node(0, ps.size());
    rep(i, n) {
        if (op[i] == '+') {
            insert(root, x[i], y[i]);
        } else if (op[i] == '?') {
            cout << query(root, x[i], y[i]) << endl;
        }
    }
}

int main() {
    cin.tie(0);
    input();
    solve();
    return 0;
}
