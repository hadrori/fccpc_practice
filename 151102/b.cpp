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

#define long int64_t

const int N = 3015;

int n;
char d[N];

vector<int> unzipx, unzipy;
unordered_map<int, int> zipx, zipy;

struct Node {
    long x, y;
    char dir;
    Node* l;
    Node* r;
    Node* d;
    Node* u;    
    
    Node(): dir('#') { l = r = d = u = NULL; }
    Node(long x, long y, char dir): x(x), y(y), dir(dir) { l = r = d = u = NULL; }
    bool operator<(const Node &o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};

vector<Node> nodes;
vector<Node> ll, rr, uu, dd;

void setEdge() {
    rep(y, ll.size()) {
        ll[y].r = &rr[y];
    }
    rep(y, rr.size()) {
        rr[y].l = &ll[y];
    }
    rep(x, dd.size()) {
        dd[x].u = &uu[x];
    }
    rep(x, uu.size()) {
        uu[x].d = &dd[x];
    }
}

long solve(int i) {
    setEdge();

    for (Node &node: nodes) {
        int x = node.x, y = node.y;

        node.l = rr[y].l;
        rr[y].l->r = &node;
        rr[y].l = &node;
        node.r = &rr[y];
        
        node.d = uu[x].d;
        uu[x].d->u = &node;
        uu[x].d = &node;
        node.u = &uu[x];
    }

    Node *now = &nodes[i];
    long cnt = 0;
    while (now->dir != '#') {
        Node *before = now;
        //cout << now->dir << " " << now->x << " " << now->y << endl;
        switch (now->dir) {
        case '>': now = now->r; break;
        case '<': now = now->l; break;
        case 'v': now = now->d; break;
        case '^': now = now->u; break;
        }        
        before->r->l = before->l;
        before->l->r = before->r;
        before->u->d = before->d;
        before->d->u = before->u;
        cnt++;
    }
    //cout << endl;

    return cnt;
}

int main()
{
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> d[i];        
        unzipx.push_back(x[i]);
        unzipy.push_back(-y[i]);
    }
    sort(all(unzipx)), uniq(unzipx);
    sort(all(unzipy)), uniq(unzipy);
    rep(i, unzipx.size()) zipx[unzipx[i]] = i;
    rep(i, unzipy.size()) zipy[unzipy[i]] = i;
    
    ll = vector<Node>(zipy.size());
    rr = vector<Node>(zipy.size());
    uu = vector<Node>(zipx.size());
    dd = vector<Node>(zipx.size());

    rep(i, n) {
        nodes.push_back(Node(zipx[x[i]], zipy[-y[i]], d[i]));
    }
    sort(all(nodes));

    long ans = 0;
    rep(i, n) ans = max(ans, solve(i));

    cout << ans << endl;
    return 0;
}
