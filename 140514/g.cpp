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

const int stick[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int dp[51][10][110] = {1};

void prepare()
{
    rep(i, 50) rep(d, 10) rep(s, 101) {
        if (dp[i][d][s]) {
            rep(nd, 10) {
                dp[i + 1][nd][s + stick[nd]] |= 1 << d;
            }
        }
    }
}

void mn(int n)
{
    repi(i, 1, 50) repi(d, 1, 10) {
        if (dp[i][d][n]) {
            while (i) {
                int j;
                for (j = 0; j < 10; ++j) {
                    if (dp[i][d][n] >> j & 1) break;
                }
                cout << d;
                --i, n -= stick[d], d = j;
            }
            return;
        }
    }
}

void mx(int n)
{
    for (int i = 50; i >= 1; --i) {
        for (int d = 9; d >= 1; --d) {
            if (dp[i][d][n]) {
                while (i) {
                    int j;
                    for (j = 9; j >= 0; --j) {
                        if (dp[i][d][n] >> j & 1) break;
                    }
                    cout << d;
                    --i, n -= stick[d], d = j;
                }
                return;
            }
        }
    }
}

void solve(int n)
{
    mn(n);
    cout << ' ';
    mx(n);
    cout << endl;
}

int main()
{
    prepare();

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
