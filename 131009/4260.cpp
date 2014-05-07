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
#define MAX 820
int n, c;
string s;
int dp[153][MAX*5+5];
int main(){
    cin >> n;
    rep(_, n) {
	cin >> c;
	vector<vector<int> > G(MAX*5);
	vector<int> lst(MAX*5);
	rep(i, c) {
	    int num, to;
	    char tc;
	    cin >> num >> tc >> to;
	    G[(tc-'A')*MAX+num].pb(to);
	    lst[(tc-'A')*MAX+num] = max(lst[(tc-'A')*MAX+num], to);
	}
	cin >> s;
	memset(dp, 0, sizeof(dp));
	rep(i, s.size()+1) rep(j, G.size()) dp[i][j] = -INF;
	dp[0][(s[0]-'A')*MAX+1] = 0;

	rep(i, s.size()-1) rep(j, G.size()) rep(k, G[j].size()) {
//	    if(dp[i+1][(s[i+1]-'A')*MAX+G[j][k]] < dp[i][j]+G[j][k])
	    //	cout << i+1 << " : " << s[i+1] << ", from:" << j << " to " << (s[i+1]-'A')*MAX+G[j][k]<< " , " << dp[i][j]+G[j][k] << endl;	    
	    dp[i+1][(s[i+1]-'A')*MAX+G[j][k]] = max(dp[i+1][(s[i+1]-'A')*MAX+G[j][k]], dp[i][j]+G[j][k]);
	    
	}
	int ans = 0;
	rep(i, G.size()) ans = max(dp[s.size()-1][i] + lst[i], ans);
	cout << ans << endl;
	
    }
    return 0;
}
