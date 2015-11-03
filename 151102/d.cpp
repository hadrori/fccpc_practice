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

const long inf = 1e16;

long extgcd(long a, long b, long& x, long& y)
{
    long g = a;
    x = 1, y = 0;
    if (b != 0) {
        g = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return g;
}

long inv(long a, long m)
{
    long x, y;
    if (extgcd(a, m, x, y) != 1) return 0;
    return (x % m + m) % m;
}

long discrete_log(long a, long m)
{
    if (a == 0) return -1;
    long b = long(sqrt(m)) + 1;
    long t = 1;
    map<long, long> mem;
    rep(i, b) {
        if (mem.find(t) == end(mem)) {
            mem[t] = i;
        }
        t = t * a % m;
        if (t == 1) return i + 1;
    }
    long ret = inf, u = t;
    for (int i = b; i < m + b; i += b) {
        if (mem.find(inv(u, m)) != end(mem)) {
            ret = min(ret, mem[inv(u, m)] + i);
        }
        u = u * t % m;
    }
    return ret == inf ? -1 : ret;
}

long solve(long n)
{
    if (n == 2) return 1;
    vector<long> fac;
    long t = n;
    for (long p = 2; p * p <= t; ++p) {
        if (t % p == 0) {
            if (t % (p * p) == 0) return -1;
            t /= p;
            fac.push_back(p);
        }
    }
    if (t >= 2) fac.push_back(t);

    const int k = fac.size();
    long ans = 1;
    rep(i, k) {
        long m = fac[i] - 1;
        long t = discrete_log(n % m, m);
        if (t == -1) return -1;
        ans = ans / __gcd(ans, t) * t;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
