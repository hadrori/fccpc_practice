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
string s;
int pos;
int and2(int a, int b) {
    if( a==2 and b == 2) return 2;
    if(a == 0 or b == 0) return 0;
    return 1;
}

int or2(int a, int b) {
    if(a==2 or b==2) return 2;
    if(a==0 and b==0) return 0;
    return 1;
}

int form() {
    if(s[pos] == '-') {
        pos++;
        return 2 - form();
    } else if(s[pos] == '(') {
        pos++;
        int a = form();
        char ope = s[pos];
        pos++;
        int b = form();
        pos++;
        if(ope == '*') return and2(a, b);
        else return or2(a, b);
    } else {
        return s[pos++] - '0';
    }
}

int main()
{
    string rs;
    while(getline(cin, rs), rs != ".") {
        int ans = 0;
        rep(p, 3) rep(q, 3) rep(r, 3) {
            pos = 0;
            s = rs;
            rep(i, s.size()) {
                if(rs[i] == 'P') s[i] = p + '0';
                else if(rs[i] == 'Q') s[i] = q + '0';
                else if(rs[i] == 'R') s[i] = r + '0';
            }
            if(form() == 2) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
