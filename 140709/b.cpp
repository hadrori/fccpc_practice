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

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

vector<int> ans, s;

void push(int n)
{
    while (s.size() >= 2 and max(s[int(s.size()) - 2], s.back()) < n) {
        ans.pb(s.back());
        s.pop_back();
    }
    s.pb(n);
}

int main()
{
    int n;
    while (cin >> n) push(n);
    while (not s.empty()) {
        ans.pb(s.back());
        s.pop_back();
    }
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }

    return 0;
}
