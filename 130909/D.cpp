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

string dice[6][3];

int main()
{
    while(true){
	cin >> dice[0][0];
	if(dice[0][0] == "#") break;
	cin >> dice[0][1] >> dice[0][2];
	rep(i,5)rep(j,3)cin >> dice[i+1][j];
	int ans = INF;
	bool exist1 = false, exist2 = false;
	rep(i,3)if(dice[0][2][i] == '*'){
	    exist1 = true;
	    break;
	}
	rep(i,3)if(dice[2][2][i] == '*'){
	    exist2 = true;
	    break;
	}
	if(exist1 && exist2) ans = min(ans, 0);
	
	exist1 = false, exist2 = false;
	rep(i,3)if(dice[0][0][i] == '*'){
	    exist1 = true;
	    break;
	}
	rep(i,3)if(dice[2][0][i] == '*'){
	    exist2 = true;
	    break;
	}
	if(exist1 && exist2) ans = min(ans, 2);

	exist1 = false, exist2 = false;
	rep(i,3)if(dice[0][i][0] == '*'){
	    exist1 = true;
	    break;
	}
	rep(i,3)if(dice[2][i][2] == '*'){
	    exist2 = true;
	    break;
	}
	if(exist1 && exist2) ans = min(ans, 1);

	exist1 = false, exist2 = false;
	rep(i,3)if(dice[0][i][2] == '*'){
	    exist1 = true;
	    break;
	}
	rep(i,3)if(dice[2][i][0] == '*'){
	    exist2 = true;
	    break;
	}
	if(exist1 && exist2) ans = min(ans, 1);

	exist1 = false, exist2 = false;
	rep(i,3)if(dice[1][i][0] == '*'){
	    exist1 = true;
	    break;
	}
	rep(i,3)if(dice[3][i][2] == '*'){
	    exist2 = true;
	    break;
	}
	if(exist1 && exist2) ans = min(ans, 2);

	exist1 = false, exist2 = false;
	rep(i,3)if(dice[1][i][2] == '*'){
	    exist1 = true;
	    break;
	}
	rep(i,3)if(dice[3][i][0] == '*'){
	    exist2 = true;
	    break;
	}
	if(exist1 && exist2) ans = min(ans, 2);

	exist1 = false, exist2 = false;
	rep(i,3)if(dice[1][0][i] == '*'){
	    exist1 = true;
	    break;
	}
	rep(i,3)if(dice[3][0][i] == '*'){
	    exist2 = true;
	    break;
	}
	if(exist1 && exist2) ans = min(ans, 3);

	exist1 = false, exist2 = false;
	rep(i,3)if(dice[1][2][i] == '*'){
	    exist1 = true;
	    break;
	}
	rep(i,3)if(dice[3][2][i] == '*'){
	    exist2 = true;
	    break;
	}
	if(exist1 && exist2) ans = min(ans, 3);

	exist1 = false, exist2 = false;
	rep(i,3)if(dice[4][2][i] == '*'){
	    exist1 = true;
	    break;
	}
	rep(i,3)if(dice[5][0][i] == '*'){
	    exist2 = true;
	    break;
	}
	if(exist1 && exist2) ans = min(ans, 1);

	exist1 = false, exist2 = false;
	rep(i,3)if(dice[4][0][i] == '*'){
	    exist1 = true;
	    break;
	}
	rep(i,3)if(dice[5][2][i] == '*'){
	    exist2 = true;
	    break;
	}
	if(exist1 && exist2) ans = min(ans, 1);

	exist1 = false, exist2 = false;
	rep(i,3)if(dice[4][i][0] == '*'){
	    exist1 = true;
	    break;
	}
	rep(i,3)if(dice[5][i][0] == '*'){
	    exist2 = true;
	    break;
	}
	if(exist1 && exist2) ans = min(ans, 2);

	exist1 = false, exist2 = false;
	rep(i,3)if(dice[4][i][2] == '*'){
	    exist1 = true;
	    break;
	}
	rep(i,3)if(dice[5][i][2] == '*'){
	    exist2 = true;
	    break;
	}
	if(exist1 && exist2) ans = min(ans, 2);
	cout << ans << endl;
    }
    return 0;
}
