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

const int N = 1000010;

int primes[100000], P = 0;

void prepare()
{
    static bool c[N];
    for (int i = 2; i * i < N; ++i) {
        if (not c[i]) {
            for (int j = i * i; j < N; j += i) {
                c[j] = true;
            }
        }
    }
    repi(i, 2, N) if (not c[i]) primes[P++] = i;
}

vector<long> divisors(long n)
{
    vector<long> ret(1, 1);
    rep(i, P) {
        const int& p = primes[i];
        if (p * p > n) break;
        vector<long> tmp(ret);
        for (long q = p; n % p == 0; n /= p, q *= p) {
            for (long t : ret) {
                tmp.push_back(t * q);
            }
        }
        ret = move(tmp);
    }
    if (n >= 2) {
        vector<long> tmp(ret);
        for (long t : tmp) {
            ret.push_back(t * n);
        }
    }
    return ret;
}

int main()
{
    prepare();
    long n;
    cin >> n;
    int ans = 0;
    for (long d : divisors(n)) {
        ++ans;
        for (long dd : divisors(n-d)) {
            ans += dd > d and dd % d == 0;
        }
    }
    cout << ans << endl;
    return 0;
}
