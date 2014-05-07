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

#define repi(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) repi(i, 0, a)
#define repd(i, a, b) for(int i = (a); i >= (b); i--)
#define repit(i, a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

#define all(u) (u).begin(), (u).end()
#define rall(u) (u).rbegin(), (u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)), (u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int N = 1200;

int dp[N][16] = {1}, c[N] = {1, 1};

void gen()
{
    for (int i = 2; i < N; ++i) {
	if (!c[i]) {
	    for (int j = N - 2; j >= i; --j) {
		for (int k = 1; k < 16; ++k) {
		    dp[j][k] += dp[j - i][k - 1];
		}
	    }
	    for (int j = i + i; j < N; j += i) {
		c[j] = 1;
	    }
	}
    }
}

int main(){
    gen();

    int n, k;
    while (cin >> n >> k && n) {
	cout << dp[n][k] << endl;
    }

    return 0;
}
