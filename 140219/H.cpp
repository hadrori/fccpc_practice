#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>ago
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

int N;
vector<int> A, B;

void input()
{
    A.resize(N);
    B.resize(N);
    rep(i, N)
        cin >> A[i] >> B[i];
    rep(i, N) rep(j, N-1) {
        if(B[j] > B[j+1]) {
            swap(A[j], A[j+1]);
            swap(B[j], B[j+1]);
        }
    }
}



void solve()
{
    int ret = 0;
    rep(start, 5) {
        int tmp = 0;
        vector<bool> used(N);
        for(double t = start + 0.5; t < 1001; t += 5) {
            rep(i, N) {
                if(t > A[i] && t < B[i] && !used[i]) {
                    used[i] = true;
                    tmp++;
                    break;
                }
            }
        }
        ret = max(ret, tmp);
    }
    cout << ret << endl;
}

int main()
{
    while (cin >> N && N) {
        input();
        solve();
    }

    return 0;
}
