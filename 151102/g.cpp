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

struct Point {
    long x, y, z;
    Point(long x, long y, long z): x(x), y(y), z(z) {}
    bool operator<(const Point &o) const {
        if (x != o.x) return x < o.x;
        if (y != o.y) return y < o.y;
        return z < o.z;
    }
};

int main()
{
    long a, b, c, n;
    set<Point> st;
    cin >> a >> b >> c >> n;
    const long dx[] = {-1, 1, 0, 0, 0, 0};
    const long dy[] = {0, 0,-1, 1, 0, 0};
    const long dz[] = {0, 0, 0, 0,-1, 1};
    long ans = 2*(a*b + b*c + c*a);
    rep(i, n) {
        long x, y, z;
        cin >> x >> y >> z;
        Point p(x, y, z);
        int cnt = 0;
        if (x == 0) cnt++;
        if (y == 0) cnt++;
        if (z == 0) cnt++;
        if (x == a-1) cnt++;
        if (y == b-1) cnt++;
        if (z == c-1) cnt++;
        rep(j, 6) {
            Point tp(x + dx[j], y + dy[j], z + dz[j]);
            if (st.find(tp) != st.end()) cnt++;
        }
        //cout << cnt << endl;
        ans += 6 - 2*cnt;
        st.insert(p);
    }
    cout << ans << endl;
    
    return 0;
}
