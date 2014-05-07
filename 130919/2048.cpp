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

const int N = 1<<20;

bool c[N] = {};
int sp[N] = {};
int lp[N] = {};

void gen()
{
    for (int i = 2; i < N; ++i) {
	if (!c[i]) {
	    for (int j = i; j < N; j += i) {
		c[j] = true;
		sp[j] += i;
		lp[j] = max(lp[j], i);
	    }
	}
    }
}

int key(int n)
{
    return 2 * lp[n] - sp[n];
}

int main()
{
    gen();

    int a, b;
    while (cin >> a >> b && a)
	cout << (key(a) > key(b) ? "a" : "b") << endl;

    return 0;
}
