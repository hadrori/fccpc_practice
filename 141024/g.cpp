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

struct point {
    int x, y;
    point(int x, int y) : x(x), y(y) {}
    bool operator<(const point &o) const {
        if(x != o.x) return x < o.x;
        return y < o.y;
    }

    bool operator==(const point &o) const {
        if(x != o.x) return x == o.x;
        return y == o.y;
    }
};

struct seg {
    point a, b;
    seg(point a, point b) : a(a), b(b) {
        if(b < a) swap(this->a, this->b);
        assert(max(abs(a.x-b.x), abs(a.y-b.y)) <= 1);
    }
    bool operator<(const seg &o) const {
        if(!(a == o.a)) return a < o.a;
        return b < o.b;
    }
    bool operator==(const seg &o) const {
        if(!(a == o.a)) return false;
        return b == o.b;
    }
};

int n;
vector<seg> v;
set<point> obs;
void input() {
    cin >> n;
    v.clear();
    rep(i, n) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        v.pb(seg(point(x0, y0), point(x1, y1)));
    }

    obs.clear();
    int b;
    cin >> b;
    rep(i, b) {
        int x, y;
        cin >> x >> y;
        obs.insert(point(x, y));
    }
}

const int dx[] = {0, 1, 1, 0,-1,-1};
const int dy[] = {1, 1, 0,-1,-1, 0};

vector<point> getAround(point p) {
    vector<point> ret;
    rep(i, 6) ret.pb(point(p.x + dx[i], p.y + dy[i]));
    return ret;
}

map<seg, int> dst[16];

const int inf = 1000000000;
const int LIM = 6;
void calcDst() {
    rep(id, n) dst[id].clear();

    rep(id, n) {
        queue<pair<seg, int> > q;
        q.push(mp(v[id], 0));
        while(q.size()) {
            seg now = q.front().first;
            int step = q.front().second; q.pop();
            if(abs(now.a.x) > LIM or abs(now.b.x) > LIM or
               abs(now.a.y) > LIM or abs(now.b.y) > LIM) continue;
            if(obs.find(now.a) != obs.end() or
               obs.find(now.b) != obs.end()) continue;
            if(dst[id].find(now) != dst[id].end()) continue;
            dst[id][now] = step;
            
            seg nxt = now;
            nxt = seg(now.b, point(now.b.x + now.b.x - now.a.x,
                                   now.b.y + now.b.y - now.a.y));
            q.push(mp(nxt, step+1));
            nxt = seg(now.a, point(now.a.x + now.a.x - now.b.x,
                                   now.a.y + now.a.y - now.b.y));
            q.push(mp(nxt, step+1));

            vector<point> pa = getAround(now.a);
            vector<point> pb = getAround(now.b);
            
            rep(i, pa.size()) {
                rep(j, pb.size()) if(pa[i] == pb[j]) {
                    nxt = seg(now.a, pa[i]);
                    q.push(mp(nxt, step+1));
                    nxt = seg(pa[i], now.b);
                    q.push(mp(nxt, step+1));
                    break;
                }
            }
            
        }
        
    }
    
}
void solve() {
    input();
    if(n < 6) {
        cout << "impossible" << endl;
        return;
    }

    calcDst();

    /*
    rep(id, n) {
        cout << "from ";
        cout << "(" << v[id].a.x << " " << v[id].a.y << ") , ";
        cout << "(" << v[id].b.x << " " << v[id].b.y << ")" << endl;
        
        repit(itr, dst[id]) if(itr->second == 1) {
            cout << "(" << itr->first.a.x << " " << itr->first.a.y << ") , ";
            cout << "(" << itr->first.b.x << " " << itr->first.b.y << ")" << endl;
            cout << " " << itr->second << endl;
        }
        }*/
  
    vector<int> use(n, -1);
    rep(i, 6) use[i] = i;
    sort(all(use));
    int ans = inf;
    do {
        repi(cx, -LIM, LIM+1) repi(cy, -LIM, LIM+1) {
            vector<point> ard = getAround(point(cx, cy));
            vector<seg> goal;
            rep(i, 6) goal.pb(seg(ard[i], ard[(i+1)%6]));

            int tmp = 0;
            bool ok = true;
            rep(i, n) {
                if(use[i] >= 0) {
                    if(dst[i].find(goal[use[i]]) != dst[i].end())
                        tmp += dst[i][goal[use[i]]];
                    else ok = false;
                } else {
                    tmp++;
                }
            }
            
            if(ok) {
                ans = min(ans, tmp);
            }
        }
    } while(next_permutation(all(use)));

    if(ans < inf) cout << ans << endl;
    else cout << "impossible" << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(i, T) {
        cout << "Case " << i+1 << ": ";
        solve();
    }
    return 0;
}
