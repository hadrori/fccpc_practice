#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
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

int main(){
    int n;
    while(cin>>n,n){
        vector<vi> t(n,vi(n+1));
        rep(i,n)rep(j,n+1) cin >> t[i][j];
        vi dp(1<<n,INF);
        dp[0] = 0;
        rep(i,1<<n){
            rep(v,n)if(!(i&(1<<v))){
                int mt = t[v][0];
                rep(u,n)if(i&(1<<u)){
                    mt = min(mt,t[v][u+1]);
                }
                dp[i|(1<<v)] = min(dp[i|(1<<v)], dp[i]+mt);
            }
        }
        cout << dp[(1<<n)-1] << endl;
    }
}
