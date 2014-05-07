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
int x, n, t;
int flip[1003][1003];
int main()
{
    bool flag = false;
    cin >> x;
    rep(_, x) {
	cin >> n >> t;
	memset(flip, 0, sizeof(flip));
	if(flag) cout << endl;
	flag = true;
	rep(i, t) {
	    char c;
	    cin >> c;
	    if(c == 'C') {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		repi(i, y1, y2+1) {
		    flip[x1][i] ^= 1;
		    flip[x2+1][i] ^= 1;
		}
	    } else {
		int x, y;
		cin >> x >> y;
		x--; y--;
		int ans = 0;
		rep(i, x+1) ans ^= flip[i][y];
		cout << ans << endl;
	    }

	}

    }
    return 0;
}
