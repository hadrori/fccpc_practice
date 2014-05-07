#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

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


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int p, n, c;
int have[128];
int pay[128];
pii seq[128];

void solve(){
    c = n;
    memset(pay, 0, sizeof(pay));
    int sum = 0;
    
    rep(i, n) seq[i] = pii(-have[i],i);
    sort(seq, seq+n);
    while(p > 0){
        if(c == 0){
            puts("IMPOSSIBLE");
            return;
        }
        int cst = p / c;
        if(p < c) cst = 1;
        rep(i, n){
            if(have[seq[i].second] == 0) continue;
            int py = min(have[seq[i].second], cst);
            have[seq[i].second] -= py;
            pay[seq[i].second] += py;
            p -= py;
            if(have[seq[i].second] == 0) c--;
            if(p == 0) break;
        }
    }
    rep(i,n) cout << pay[i] << (i==n-1? '\n': ' ');
    return;
}

int main()
{
    int T; cin >> T;
    while(T--){
        cin >> p >> n;
        rep(i,n) cin >> have[i];
        solve();
    }
    return 0;
}
