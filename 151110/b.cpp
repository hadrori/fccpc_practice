#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define pb push_back
#define all(u) begin(u),end(u)
#define uniq(u) (u).erase(unique(all(u)), (u).end())
#define mp make_pair
#define long int64_t

struct Range {
    int type;
    int x, y;
    Range(int type, int x, int y): type(type), x(x), y(y) {}
};

int n;
vector<Range> rv;
map<int, int> zipx, zipy;
vector<int> unzipx, unzipy;

class Bit {
    int n, sz;
    vector<int> unzip;
    vector<int> dat;
public:
    Bit(const vector<int> &cand) {
        unzip = cand;
        unzip.pb(-10000000);
        sort(all(unzip));        
        uniq(unzip);

        n = unzip.size() + 2;        
        dat.assign(n, 0);        
        sz = 0;
    }

    void add(int k_) {
        sz++;
        int k = lower_bound(all(unzip), k_) - unzip.begin();
        while(k <= n) {
            dat[k]++;
            k += k&-k;
        }
    }

    int sum(int k_) {
        //assert(zip.find(k_) != zip.end());        
        int k = lower_bound(all(unzip), k_) - unzip.begin();        
        int ret = 0;
        while(k) {
            ret += dat[k];
            k -= k&-k;
        }
        return ret;
    }

    int size() { return sz; }
};

class Segtree {
    int n;
    vector<vector<int> > cand;
    vector<Bit> dat;

    int query(int a, int b, int k, int l, int r, int y) {
        if (r <= a or b <= l) return 0;
        if (a <= l and r <= b) {
            int ret = dat[k].size() - dat[k].sum(y-1);
            cout << a << " " << b << " " << k << " " << l << " " << r << " " << y << " " << ret << endl;
            cout << " " << dat[k].size() << " " << dat[k].sum(y-1) << endl;
            return ret;
        }
        
        int m = (l + r) / 2;
        return query(a, b, k*2+1, l, m, y) + query(a, b, 2*k+2, m, r, y);
    }
    
public:
    Segtree(vector<Range> &ranges) {
        int maxx = 0;
        for (Range &range: ranges) maxx = max(maxx, range.x+1);
        n = 1;
        while (n < maxx) n *= 2;

        cand.assign(2*n, vector<int>());

        for (Range &range: ranges) {
            int k = range.x + n-1;
            cand[k].pb(range.y);            
            while (k) {
                k = (k-1) / 2;
                cand[k].pb(range.y);
            }
        }
        
        rep(i, cand.size()) dat.pb(Bit(cand[i]));                
    }
    
    int query(int x, int y) {
        return query(0, x+1, 0, 0, n, y);
    }
    
    void add(int x, int y) {
        x += n-1;
        while (x) {            
            //cout << "ADD: "<< x << " " << y << endl;
            dat[x].add(y);
            x = (x-1) / 2;
        }
        //cout << "ADD: "<< x << " " << y << endl;
        dat[x].add(y);
    }
};

void calcZip() {
    rep(i, n) {
        unzipx.pb(rv[i].x);
        unzipy.pb(rv[i].y);        
    }
    sort(all(unzipx));
    sort(all(unzipy));
    uniq(unzipx);
    uniq(unzipy);
    
    rep(i, unzipx.size()) zipx[unzipx[i]] = i;
    rep(i, unzipy.size()) zipy[unzipy[i]] = i;
}

void input() {    
    cin >> n;
    rep(i, n) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == '+') rv.pb(Range(0, x, y));
        else rv.pb(Range(1, x, y));
    }    
    
    calcZip();

    rep(i, n) {
        rv[i].x = zipx[rv[i].x];
        rv[i].y = zipy[rv[i].y];
    }
    
    Segtree seg(rv);

    rep(i, n) {
        cout << "query: " << rv[i].type << " " << rv[i].x << " " << rv[i].y << endl;
        cout << unzipx[rv[i].x] << " " << unzipy[rv[i].y] << endl;
        if (rv[i].type == 1) {
            cout << seg.query(rv[i].x, rv[i].y) << endl;
        } else {
            seg.add(rv[i].x, rv[i].y);
        }
    }
    
}

void solve() {
}

int main() {
    input();
    solve();
    return 0;
}
