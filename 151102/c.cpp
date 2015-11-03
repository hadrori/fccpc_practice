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

struct Seg {
    int s, t;
    Seg() { s = t = 0; }
    Seg(int s, int t): s(s), t(t) {}
    bool operator<(const Seg &o) const {
        if (s != o.s) return s < o.s;
        return t > o.t;
    }
};

void rotate(vector<long> &w, vector<Seg> &segs, int base) {
    int n = w.size();
    vector<long> nw(n);    
    
    rep(i, n) {
        nw[i] = w[(i+base) % n];
    }
    w = nw;

    rep(i, segs.size()) {
        segs[i].s = (segs[i].s + n - base) % n;
        segs[i].t = (segs[i].t + n - base) % n;
    }    
}

bool isCross(vector<long> w, vector<Seg> segs) {
    rep(i, segs.size()) {
        if (segs[i].s > segs[i].t) swap(segs[i].s, segs[i].t);            
    }
    sort(all(segs));
    rep(i, (int)segs.size() -1 ) {
        if (segs[i].t < segs[i+1].t) return true;
    }
    return false;
}

bool isReverse(vector<long> w, vector<Seg> segs) {
    sort(all(segs));
    rotate(w, segs, segs[0].s);
    sort(all(segs));

    int t = segs[0].t;
    for (Seg seg: segs) {
        if (seg.s == t) return true;
        else if (seg.s < t && seg.s > seg.t)  return true;
        else if (seg.s > t && seg.s < seg.t)  return true;
    }

    return false;
}

long sum(int l, int r, const vector<long> &v) {
    if (r == 0) return 0;
    if (l == 0) return v[r-1];
    return v[r-1] - v[l-1];
}

long solve_uni(vector<long> w, vector<Seg> segs) {
    int n = w.size();
    vector<long> w_sum = w;
    rep(i, n) w_sum.push_back(w[i]);    
    rep(i, 2*n-1) w_sum[i+1] += w_sum[i];

    // rep(i, n) cout << sum(i, i+1, w_sum) << endl;
    long l = sum(0, n-1, w_sum);
    long val1 = 0, val2 = 0;
    rep(i, n) {
        if (segs[i].s > segs[i].t) segs[i].t += n;

        cout << sum(segs[i].s, segs[i].t, w_sum) << endl;
        val1 += sum(segs[i].s, segs[i].t, w_sum);
        val2 += l - sum(segs[i].s, segs[i].t, w_sum);
    }    
    cout << val1 << " "  << val2 << endl;
    return min(val1, val2);
}

long solve_bi(vector<long> w, vector<Seg> segs) {
    struct Point {
        int pos, type;
        Point(int pos, int type): pos(pos), type(type) {}
        bool operator<(const Point &o) const {
            if (pos != o.pos) return pos < o.pos;
            return type < o.type;
        }
    };

    int n = w.size();
    
    vector<Point> pv;
    rep(i, segs.size()) {
        pv.push_back(Point(segs[i].s, 0));
        pv.push_back(Point(segs[i].t, 1));
        pv.push_back(Point(segs[i].s + n, 0));
        pv.push_back(Point(segs[i].t + n, 1));
    }

    sort(all(pv));

    int base = -1;
    rep(i, (int)pv.size() - 1) {
        if (pv[i].type == 1 and pv[i+1].type == 0) {
            base = i+1;
        }
    }
    if (base == -1) assert(false);

    rotate(w, segs, base);    
    vector<long> w_sum = w;
    rep(i, n) w_sum.push_back(w[i]);    
    rep(i, 2*n-1) w_sum[i+1] += w_sum[i];        

    long l = sum(0, n-1, w_sum);
    long val = 0;
    rep(i, n) val += sum(segs[i].s, segs[i].t, w_sum);
    long ans = val;
    rep(i, n) {
        val += l - sum(segs[i].s, segs[i].t, w_sum) * 2;
        ans = min(ans, val);
    }

    return ans;
}

int main()
{
    int n, q;
    cin >> n >> q;
    
    vector<long> w(n);
    rep(i, n) cin >> w[i];

    vector<Seg> segs(q);
    rep(i, q) {
        cin >> segs[i].s >> segs[i].t;
    }

    long ans;
    if (isCross(w, segs) || isReverse(w, segs)) {
        ans = solve_uni(w, segs);
    } else {
        ans = solve_bi(w, segs);
    }
    
    cout << ans << endl;
    
    return 0;
}
