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

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e18
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll n, w[5000], memo[5000][5000];

ll rec(int left, int right){
    if(memo[left][right] >= 0) return memo[left][right];

    ll ret = INF;
    repi(i, left, right){
	ret = min(ret, rec(left, i) + rec(i+1,right));
    }
    ret += w[right+1] - w[left];
    return memo[left][right] = ret;
}

int main() {
    cin >> n;
    rep(i,n) cin >> w[i+1];
    repi(i,1,n+1) w[i] += w[i-1];
    rep(i,n)rep(j,n) memo[i][j] = (i==j)? 0: -1;
    cout << rec(0, n-1) << endl;
    return 0;
}
