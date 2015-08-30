#include <bits/stdc++.h>
using namespace std;

#define repi(i,a,b) for(int i = (int)(a); i<(int)(b); ++i)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;
#define long int64_t

long mod = 1000000007;

const int MAX = 512;
long C[MAX][MAX];
long fact[MAX];

void genC() {
    rep(i, MAX) {
        C[i][0] = 1;
        repi(j, 1, i+1) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }
}

void genFact() {
    fact[0] = 1;
    rep(i, MAX-1) {
        fact[i+1] = (fact[i] * (i+1)) % mod;
    }
}

void gen() {
    genC();
    genFact();
}

void solve() {
    long N, K, p;
    cin >> N >> K >> p;
    if(p == N) {
        cout << (C[N-1][K-1] * fact[K-1]) % mod << endl;
        return;
    }
    long ans = 0;
    repi(l, 0, N-K) {
        repi(x, p+1, N+1) {
            ans += (C[x-2][l] * fact[N-l-2]) % mod;
            ans %= mod;
        }
    }

    if ((K-1) - (N-p) >= 0) {
        ans += (fact[K-1] * C[p-1][(K-1) - (N-p)]) % mod;
        ans %= mod;
    }
    cout << ans % mod << endl;
        
}

int main()
{
    genC();
    genFact();
    
    int T;
    cin >> T;    
    rep(t, T) {
        cout << "Case #" << t+1 << ": ";
        solve();
    }
    return 0;
}
