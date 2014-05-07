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

#define repi(i,a,b) for(int i=(a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a); i>=(b); i--)
#define repit(i,a) for(typeof((a).begin()) i=(a).begin(); i != (a).end(); i++)

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

int main()
{
    int t;
    cin >> t;
    while(t--) {
	int n;
	cin >> n;
	vector<int> d(30010);
	rep(i, n) {
	    int s, f;
	    cin >> s >> f;
	    d[s]++;
	    d[f+1]--;
	}
	int ans = 0, now = 0;
	rep(i, 30010) {
	    now += d[i];
	    ans = max(ans, now);
	}
	cout << ans << endl;
    }
    return 0;
}
