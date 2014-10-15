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
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i = (int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i = (int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it = (u).begin(); it!=(u).end(); ++it)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;

int k, n;
string name[1010];
int table[1010][10];

bool input()
{
    cin >> k >> n;
    if (n == 0) return false;
    rep(i, n) {
        cin >> name[i];
        rep(j, k) cin >> table[i][j];
    }
    return true;
}

void solve()
{
    vector<int> problem(n);

    vector<int> cnt(n);
    rep(i, n) {
        sort(table[i], table[i] + k);
        rep(j, k) {
            int t = table[i][j] - 1;
            if (j < k - 1 and table[i][j] == table[i][j + 1]) {
                problem[t] = 1;
            }
            ++cnt[t];
            if (name[i] == name[t]) problem[t] = 1;
        }
    }
    rep(i, n) {
        if (cnt[i] != k) {
            problem[i] = 1;
        }
    }
    int ans = accumulate(all(problem), 0);
    if (ans == 0) cout << "NO";
    else cout << ans;
    cout << " PROBLEMS FOUND" << endl;
}

int main()
{
    while (input()) solve();

    return 0;
}
