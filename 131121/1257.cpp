#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>

#define repi(i,a,b) for(int i = int(a); i < int(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = int(a); i >= int(b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);

using namespace std;

typedef long long ll;

const int N = 10010;

int flg[N] = {1, 1}, ans[N] = {};

int cur[N], next[N];

int gen()
{
    memset(cur, 0, sizeof(cur));
    repi(i, 2, N) if (!flg[i]) {
        cur[0] = 1;
        memset(next, 0, sizeof(next));
        for (int j = i * i; j < N; j += i)
            flg[j] = 1;
        repi(j, i, N) {
            ans[j] += cur[j - i];
            next[j] += cur[j - i];
        }
        memcpy(cur, next, sizeof(cur));
    }
}

signed main()
{
    gen();

    for (int n; cin >> n && n; )
        cout << ans[n] << endl;

    return 0;
}
