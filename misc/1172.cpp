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
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

bool p[300000];

void pcalc(){
    rep(i,300000) p[i] = i<2? false: true;
    rep(i,sqrt(300000))if(p[i])for(int j = i * 2; j < 300000; j += i)p[j] = false;
}

int main() {
    int n;
    pcalc();
    while(cin >> n, n){
	int ans = 0;
	repi(i,n+1,2*n+1)if(p[i]) ans++;
	cout << ans << endl;
    }
    return 0;
}
