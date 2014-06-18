#include <algorithm>
#include <bitset>
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

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
vi prm, sm;
bool isp[300010] = {1, 1};
int N;

const int M = 300010;

void gen(){
    for (int i = 1; 7 * i < M; ++i) {
        int p = 7 * i - 1;
        if (!isp[p]) {
            for (int j = p + p; j < M; j += p) {
                isp[j] = 1;
            }
        }
        p = 7 * i + 1;
        if (!isp[p]) {
            for (int j = p + p; j < M; j += p) {
                isp[j] = 1;
            }
        }
    }
/*
    repi(i,2,300010)if(i%7==1 or i%7==6) sm.pb(i);
    rep(i,sm.size()){
        bool ok = 1;
        rep(j,i) if(sm[i]%sm[j]==0){
            ok = 0;
            break;
        }
        isp[i] = ok;
        if(ok) prm.pb(i);
    }
*/
}

void solve(){
    vector<int> ans;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            if (i % 7 == 1 or i % 7 == 6) {
                if (not isp[i]) ans.pb(i);
            }
            if (i * i == N) break;
            if (N/i % 7 == 1 or N/i % 7 == 6) {
                if (not isp[N/i]) ans.pb(N/i);
            }
        }
    }
    sort(all(ans));
    rep(i, int(ans.size())) {
        cout << ' ' << ans[i];
    }
    cout << endl;
}

int main()
{
    gen();
    while(cin >> N, N!=1){
        cout << N << ":";
        solve();
    }
    return 0;
}
