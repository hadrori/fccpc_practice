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

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
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
int dp[2048][103][103][2];

int main(){
    int loop;
    cin >> loop;
    rep(_, loop) {
	int r, s;
	cin >> r >> s;
	vector<int> x(r);
	vector<int> px(r);
	vector<int> y(s);
	vector<int> py(s);
	x.push_back(0);
	px.push_back(0);
	y.push_back(0);
	py.push_back(0);
	rep(i, r) cin >> x[i] >> px[i];
	rep(i, s) cin >> y[i] >> py[i];

	rep(i, r) rep(j, r-i-1) {
	    if(x[j] > x[j+1]) {
		swap(x[j], x[j+1]);
		swap(px[j], px[j+1]);
	    }
	}
	
	rep(i, s) rep(j, s-i-1) {
	    if(y[j] > y[j+1]) {
		swap(y[j], y[j+1]);
		swap(py[j], py[j+1]);
	    }
	}

	memset(dp, 0, sizeof(dp));
	int ans = 0;
	rep(i, 1001) rep(l, y.size()) rep(r, x.size()) rep(lr, 2) {
	    if(lr == 0) {
		int ni = i + y[l+1]-y[l];
		dp[ni][l+1][r][lr] = max(dp[ni][l+1][r][lr], dp[i][l][r][lr] + max(0, py[l+1] - ni));
		ni = i+y[l]+x[r+1];
		dp[ni][l][r+1][1-lr] = max(dp[ni][l][r+1][1-lr], dp[i][l][r][lr] + max(0, px[r+1] - ni));
	    }else {
		int ni = i + x[r+1]-x[r];
		dp[ni][l][r+1][lr] = max(dp[ni][l][r+1][lr], dp[i][l][r][lr] + max(0, px[r+1] - ni));
		ni = i+x[r]+y[l+1];
		dp[ni][l+1][r][1-lr] = max(dp[ni][l+1][r][1-lr], dp[i][l][r][lr] + max(0, py[l+1] - ni));
	    }
	    ans = max(ans, dp[i][l][r][lr]);
	}
		
	cout << "Case " << _+1 << ": " << ans << endl;
	cin >> ans;
    }
    return 0;
}
