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

int main()
{
    int N, P, Q;
    cin >> N >> P >> Q;
    vector<int> C(N);
    rep(i, N) cin >> C[i];
    rep(i, N) C[i] = C[i] + P * i;
    sort(all(C));
    rep(i, N-1) C[i+1] += C[i];
    int ans = C[N-1] - N*(N-1)*P/2;
    repi(M, 1, N+1) {
        cout << M << " " << M*(Q+(M-1)*P) + (C[N-1] - C[M-1]) - N*(N-1)*P/2 << endl;
        ans = max(ans,
                  M*(Q+(M-1)*P) + (C[N-1] - C[M-1]) - N*(N-1)*P/2);
    }
    cout << ans << endl;
    
    return 0;
}
