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
#define printv(v) repit(i,v){ cout << *i << endl;}

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
int n, m, t;
char field[2][520][520];
int main()
{
    cin >> n;
    rep(_, n) {
	cin >> m >> t;
	rep(i, m) rep(j, m) cin >> field[0][i][j];
	int now = 0, nxt = 1;
	memcpy(field[1], field[0], sizeof(field[0]));
	const int dx[] = {-1,-1,-1, 0, 0, 0, 1, 1, 1};
	const int dy[] = {-1, 0, 1,-1, 0, 1,-1, 0, 1};
	rep(turn, t) {
	    repi(i, 1, m-1) repi(j, 1, m-1) {
		int b = 0, w = 0;
		rep(k, 9) if(field[now][i+dx[k]][j+dy[k]] == 'b') b++; else w++;
		if(b > w) field[nxt][i][j] = 'b';
		else field[nxt][i][j] = 'w';
	    }
	    swap(now, nxt);
	}
	int ab = 0, aw = 0;
	rep(i, m) rep(j, m) if(field[now][i][j] == 'b') ab++; else aw++;
	cout << ab << " " << aw << endl;
    }
    return 0;
}


