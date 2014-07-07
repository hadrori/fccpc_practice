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

const int N = 1000000;

int p[N] = {1, 1}, a[N] = {};

void gen()
{
    for (int i = 2; i * i < N; ++i) {
        if (not p[i]) {
            for (int j = i * i; j < N; j += i) {
                p[j] = 1;
            }
        }
    }
    a[0] = 0;
    repi(i, 1, N) {
        a[i] = a[i - 1] + (1 - p[i]);
    }
}

int main()
{
    gen();

    int n;
    while (cin >> n and n) {
        int ans = a[2 * n] - a[n];
        cout << ans << endl;
    }

    return 0;
}
