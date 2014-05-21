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
#include <cstdlib>
#include <ctime>
#define int long long
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

int N;
int s[1024][1024], t[1024][1024];
int a[1024], b[1024], c[1024], d[1024];

string solve(){
    int r = 123, q = 13;
    rep(_,min<int>(10,N)){
        rep(i,N){
            a[i] = r;
            r *= r;
            r += q;
            r %= 1000;
            a[i] = r;
        }
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        rep(i,N)rep(j,N)
            b[i] += s[i][j]*a[j];        
        rep(i,N)rep(j,N)
            d[i] += s[i][j]*b[j];
        rep(i,N)rep(j,N)
            c[i] += t[i][j]*a[j];
        
        rep(i,N) if(c[i] != d[i])
            return "NO";
    }
    return "YES";
}

bool input(){
    cin >> N;
    if(!N) return 0;
    rep(i,N)rep(j,N)
        cin >> s[i][j];
    rep(i,N)rep(j,N)
        cin >> t[i][j];
    return 1;
}

signed main()
{
    while(input()) cout << solve() << endl;
    return 0;
}
