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

string s;
bool solve() {
    if(s.size() <= 1) return false;
    if(s[0] != '1' or s[s.size()-1] != '2') return false;
    if(count(all(s), '5') != count(all(s), '6')) return false;
    rep(i, s.size()-1) {
        char c = s[i], d = s[i+1];
        if(c == '1') {
            if(d != '4' and d != '5') return false;
        } else if(c == '2') {
            return false;
        } else if(c == '3') {
            if(d != '4' and d != '5') return false;
        } else if(c == '4') {
            if(d != '2' and d != '3') return false;
        } else if(c == '5') {
            if(d != '8') return false;
        } else if(c == '6') {
            if(d != '2' and d != '3') return false;
        } else if(c == '7') {
            if(d != '8') return false;
        } else if(c == '8') {
            if(d != '6' and d != '7') return false;
        }
    }
    
    return true;
    
}

int main()
{
    int cnt = 1;
    while(cin >> s, s != "0") {
        cout << cnt++ << ". ";
        if(solve()) cout << "VALID" << endl;
        else cout << "NOT" << endl;
    }
    return 0;
}
