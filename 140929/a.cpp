#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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

using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef __float80 number;
typedef vector<number> vec;
typedef vector<vec> mat;

number det(mat A)
{
    const int n = A.size();

    number ret = 1.0;
    rep(i, n) {
        int pivot = i;
        repi(j, i + 1, n) {
            if (abs((long double) A[j][i]) > abs((long double) A[pivot][i])) pivot = j;
        }
        swap(A[i], A[pivot]);
        ret *= A[i][i] * (pivot != i ? -1 : 1);
        if (abs((long double) A[i][i]) < 1e-8) break;
        repi(j, i + 1, n) {
            for (int k = n - 1; k >= i; --k) {
                A[j][k] -= A[i][k] * A[j][i] / A[i][i];
            }
        }
    }
    return ret;
}

void solve(int n)
{
    const int m = n * n;

    vector<vec> A(m, vec(m));
    rep(i, n) rep(j, n) {
        const int p = i * n + j;
        rep(di, 3) rep(dj, 3) {
            const int ni = i + di - 1;
            const int nj = j + dj - 1;
            if (ni == i and nj == j) continue;
            if (ni < 0 or n <= ni or nj < 0 or n <= nj) continue;
            const int q = ni * n + nj;
            A[p][p] += 1.0;
            A[p][q] -= 1.0;
        }
    }
    vector<vec> B(m - 1, vec(m - 1));
    rep(i, m - 1) rep(j, m - 1) {
        B[i][j] = A[i + 1][j + 1];
    }
    number ans = det(B);
    printf("%.Lf\n", ans);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
