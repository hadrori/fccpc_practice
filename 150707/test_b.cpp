#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int memo[256][1024][2], k;

int solve(int n, int prev, int f)
{
    int &ret = memo[n][prev][f];
    if(~ret) return ret;
    if(f) { repi(i,1,n) if(!solve(n-i,i,0)) return ret = 1; }
    else {
        repi(i,1,k*prev+1) {
            if(n < i) break;
            if(!solve(n-i,i,0)) return ret = 1;
        }
    }
    return ret = 0;
}

int main()
{
    repi(j,1,11) {
        k = j;
        vector<int> loses;
        memset(memo,-1,sizeof(memo));
        repi(i,2,100) {
            if(!solve(i,i,1)) loses.push_back(i);
        }
        cout << k << " : ";
        for(auto &e: loses) cout << e << ' '; cout << endl;
    }
    return 0;
}
