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

int n;
double x[20];

void input()
{
    cin >> n;
    rep(i, n) cin >> x[i];
}

double get_s(const vector<double>& xs)
{
    double l = 0.0, r = 1e9;
    rep(_, 100) {
        double m = (l + r) / 2;
        double t = 0.0;
        for (double x : xs) {
            t += pow(x, m);
        }
        if (t > 1.0) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

void solve()
{
    priority_queue<double> que;
    repi(s, 1, 1 << n) {
        if ((s & -s) == s) continue;
        vector<double> vec;
        rep(i, n) if (s >> i & 1) {
            vec.push_back(x[i]);
        }
        que.push(get_s(vec));
    }
    while (que.size() >= 2) {
        double a = que.top(); que.pop();
        double b = que.top(); que.pop();
        que.push(max(a, b) / 2);
    }
    cout << fixed << setprecision(6) << que.top() << endl;
}

int main()
{
    int t;
    for (cin >> t; t--; ) {
        input();
        solve();
    }
    return 0;
}
