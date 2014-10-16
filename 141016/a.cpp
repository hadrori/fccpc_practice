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

int a, b;
string s, t;

string get()
{
    string ret;
    char c;
    scanf(" %c", &c);
    if (c == '"') {
        while (scanf("%c", &c), c != '"') {
            if (isupper(c)) c += 'a' - 'A';
            ret.pb(c);
        }
    } else {
        do {
            if (isupper(c)) c += 'a' - 'A';
            ret.pb(c);
        } while (scanf("%c", &c), c != ' ' and c != '\n');
    }
    return ret;
}

bool input()
{
    scanf("%d", &a);
    if (a == 0) return false;
    scanf("%d", &b);
    s = get(), t = get();
    return true;
}

void solve()
{
    cout << ((a - 1) / b & 1 ? t : s) << endl;
}

int main()
{
    int t = 0;
    while (input()) cout << ++t << ". ", solve();
}
