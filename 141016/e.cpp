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

const int MAX = 6;
int a[MAX], b[MAX];
bool input() {
    rep(i, MAX) {
        cin >> a[i];
        if(a[i] == 0) return false;
    }

    rep(i, MAX) cin >> b[i];
    
    return true;    
}

vector<int> adj(int pos) {
    vector<int> ret;
    if(pos < 8) {
        if(pos%2 == 0) {
            ret.pb(pos-1);
            ret.pb(pos+1);
        } else {
            if(pos != 1) ret.pb(pos-1);
            if(pos != 7) ret.pb(pos+1);
            ret.pb(pos+8);
        }
    } else if(pos < 17) {
        if(pos%2 == 1) {
            ret.pb(pos-1);
            ret.pb(pos+1);
            ret.pb(pos-8);
        } else {
            if(pos != 8) ret.pb(pos-1);
            if(pos != 16) ret.pb(pos+1);
            ret.pb(pos+10);
        }        
    } else if(pos < 28) {
        if(pos%2 == 0) {
            ret.pb(pos-1);
            ret.pb(pos+1);
            ret.pb(pos-10);
        } else {
            if(pos != 17) ret.pb(pos-1);
            if(pos != 27) ret.pb(pos+1);
            ret.pb(pos+11);
        }        
    } else if(pos < 39) {
        if(pos%2 == 1) {
            ret.pb(pos-1);
            ret.pb(pos+1);
            ret.pb(pos+10);
        } else {
            if(pos != 28) ret.pb(pos-1);
            if(pos != 38) ret.pb(pos+1);
            ret.pb(pos-11);
        }           
    } else if(pos < 48) {
        if(pos%2 == 0) {
            ret.pb(pos-1);
            ret.pb(pos+1);
            ret.pb(pos+8);
        } else {
            if(pos != 39) ret.pb(pos-1);
            if(pos != 47) ret.pb(pos+1);
            ret.pb(pos-10);
        }        
    } else {
        if(pos%2 == 1) {
            ret.pb(pos-1);
            ret.pb(pos+1);
        } else {
            if(pos != 48) ret.pb(pos-1);
            if(pos != 54) ret.pb(pos+1);
            ret.pb(pos-8);
        }
    }
    return ret;
}

bool done[128];

bool check(vector<int> A, vector<int> B) {
    memset(done, 0, sizeof(done));
    rep(i, A.size()) done[A[i]] = true;
    rep(i, B.size()) done[B[i]] = true;
    rep(i, MAX) {
        vector<int> ad = adj(B[i]);
        bool ok = false;
        rep(j, ad.size()) {
            if(!done[ad[j]]) ok = true;
        }
        if(!ok) return true;
    }
    return false;
}

bool solve() {
    vector<int> A(MAX), B(MAX);
    rep(i, MAX) A[i] = a[i], B[i] = b[i];
    
    memset(done, 0, sizeof(done));
    rep(i, A.size()) done[A[i]] = true;
    rep(i, B.size()) done[B[i]] = true;
    
    rep(i, MAX) {
        vector<int> ad = adj(A[i]);
        rep(j, ad.size()) {
            if(done[ad[j]]) continue;
            vector<int> TA = A;
            TA[i] = ad[j];
            if(check(TA, B)) return true;
        }
    }
    
    return false;
}

int main()
{
    int cnt = 0;
    while(input()) {
        cout << ++cnt << ". ";
        if(solve()) cout << "TRAPPED" << endl;
        else cout << "FREE" << endl;
    }
    return 0;
}
