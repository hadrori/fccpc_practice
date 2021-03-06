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

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
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
bool check(string s){
    int nf = 0;
//    cout << s << endl;
    map<char, int> table;
    rep(i, s.size()){
        if(s[i] == '~') nf = 1;
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')){
            if(table.find(s[i]) != table.end() && table[s[i]] != nf) return false;
            table[s[i]] = nf;
            nf = 0;
        }
    }
    return true;
}

int main() {
    string s;
    while(cin >> s, s != "#"){
        int bf = -1;
        bool ans = false;
        rep(i, s.size()){
            if(s[i] == '|'){
                ans |= check(s.substr(bf+2, i-bf-3));
                bf = i;
            }
        }
        ans |= check(s.substr(bf+2, s.size()-bf-3));
        cout << (ans?"yes":"no") << endl;        
    }

    return 0;
}
