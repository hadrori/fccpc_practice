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
#include <sstream>

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
int n, m, S[128];

bool solve(){
    rep(ass, 1<<n){
        bool ok = 1;
        rep(i,m){
            if(__builtin_popcount(S[i]) <= 1) continue;
            int bl = ass&S[i];
            if(!bl or bl==S[i]) {
                ok = 0;
                break;
            }
        }
        if(ok) return 1;
    }
    return 0;
}

void input(){
    cin >> n >> m;
    cin.ignore();
    memset(S, 0, sizeof(S));
    rep(i,m){
        string s;
        getline(cin, s);
        stringstream ss(s);
        int t;
        while(ss >> t) S[i] |= 1<<(t-1);
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        input();
        cout << (solve()? 'Y': 'N');
    }
    return 0;
}
