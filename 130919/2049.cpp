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
#define repd(i,a,b) for(int i = (a) ; i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i!= (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end)

#define pb push_back
#define mp makek_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int x, y;
int done[1000003];
int main(){
    while(cin >> x >> y, x) {
	memset(done, -1, sizeof(done));
	int cnt = 0;
	while(true) {
	    x -= y*(x/y);
	    
	    if(x == 0) {
		cout << cnt << " " << 0 << endl;
		break;
	    }
//	    cout << x << endl;
	    if(done[x] != -1) { // end
		cout << done[x] << " " << cnt - done[x] << endl;
		break;
	    }
	    done[x] = cnt;
	    x *= 10;

	    cnt++;
	}

    }
    return 0;
}
