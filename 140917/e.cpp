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

int n;
vector<double> X, R;
vector<double> h;
vector<double> rght, lft;
set<int> done;
bool C(double height, int lid, int rid) {
    double width = X[rid] - X[lid+1]
        + sqrt(R[rid]*R[rid] - height*height)
        + sqrt(R[lid+1]*R[lid+1] - height*height);
    return 2*height < width;
}

void solve() {
    X.clear(); R.clear(); X.resize(n); R.resize(n);
    rep(i, n) cin >> X[i] >> R[i];

    double ans = 0;
    rep(i, n) ans = max(ans, 2*R[i] / sqrt(2));

    h.clear(); rght.clear(); lft.clear();
    rep(i, n-1) {
        double r1 = R[i], r2 = R[i+1], x1 = X[i], x2 = X[i+1];
        double d = x2-x1;
        double costh1 = (r1*r1 + d*d - r2*r2)/(2*r1*d);
        double costh2 = (r2*r2 + d*d - r1*r1)/(2*r2*d);
        double sinth1 = sqrt(1-costh1*costh1);
        h.pb(r2*sinth1);
        rght.pb(costh1*r1);
        lft.pb(costh2*r2);
    }
    
    vector<pair<double, int> > q;
    rep(i, n-1) q.pb(mp(h[i], i));
    sort(all(q));

    done.clear();
    done.insert(-1);
    done.insert(n-1);
    rep(i, n-1) {
        int id = q[i].second;
        set<int>::iterator itr = done.lower_bound(id);
        itr--;
        int lid = *itr;
        itr++;
        int rid = *itr;
        //cout << "lid rid " << lid << " " << rid << endl;
        double height = q[i].first;
        double upper = height;
        double lower = ans/2;
        rep(loop, 100) {
            if(upper < lower) {
                upper = ans/2;
                break;
            }
            double mid = (upper + lower) / 2.0;
            if(C(mid, lid, rid)) lower = mid;
            else upper = mid;
        }
        //cout << upper*2 << endl;
        ans = max(ans, upper*2);
        done.insert(id);
    }
    
    printf("%.15f\n", ans);
}

int main()
{
    while(cin >> n, n) {
        solve();
    }
    
    return 0;
}
