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

#define repi(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i =(a); i >= (b); i--)
#define repit(i,a) for(__typedef((a).begin()) i =(a); i != (a).end(); i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)), (u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
int n, W, h;
int main()
{
    while(cin >> n >> W >> h) {
	//W++; h++;
	vector<int> x(n);
	vector<int> y(n);
	vector<int> w(n);
	rep(i, n) {
	    cin >> x[i] >> y[i] >> w[i];
	}
	
	vector<int> dx(W), dy(h);
	// yoko
	rep(i, n) {
	    dx[max(x[i]-w[i], 0)]++;
	    if(x[i]+w[i] < W) dx[x[i]+w[i]]--;
	}
        // tate
	rep(i, n) {
	    dy[max(y[i]-w[i], 0)]++;
	    if(y[i]+w[i] < h) dy[y[i]+w[i]]--;
	}

	bool xok = true, yok = true;
	//yoko
	int tmp = 0;
	rep(i, W) {
	    tmp += dx[i];
	    if(tmp == 0) xok = false;
	}
	//tate
	tmp = 0;
	rep(i, h) {
	    tmp += dy[i];
	    if(tmp == 0) yok = false;
	}
	if(xok || yok) cout << "Yes\n";
	else cout << "No\n";
	
    }
    return 0;
}
