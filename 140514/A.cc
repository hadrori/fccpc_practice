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
#define int long long
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

int sum, cur;
map<int,int> cnt;
string s;

int num(){
    int ret = 0;
    while(cur < s.size() and isdigit(s[cur]))
        ret = ret * 10 + s[cur++] - '0';
    return ret;
}

void expr(int d){
    if(isdigit(s[cur])){
        int k = num();
        k *= 1LL<<d;
        sum++;
        cnt[k]++;
        return;
    }
    cur++;
    expr(d+1);
    cur++;
    expr(d+1);
    cur++;
    return;
}


signed main()
{
    int T; cin >> T;
    while(T--){
        cin >> s;
        cnt.clear();
        cur = sum = 0;
        expr(0);
        int ans = sum;
        repit(it,cnt)
            ans = min(ans, sum-it->second);
        cout << ans << endl;
    }
    return 0;
}
