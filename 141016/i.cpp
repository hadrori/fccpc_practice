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

const int N = 1000010;
char buf[N];

int get()
{
    int ret = 0;
    scanf("%[^+*=.]", buf);
    char *p = buf;
    while (*p != 0) {
        ret += *p & 15;
        if (ret >= 9) ret -= 9;
        ++p;
    }
    return ret;
}

int a, b, c;
char op;

bool input()
{
    char tmp;
    a = get();
    scanf("%c", &op);
    b = get();
    scanf("%c", &tmp);
    c = get();
    return ~scanf("%c ", &tmp);
}

bool solve()
{
    if (op == '+') {
        return (a + b) % 9 == c;
    } else {
        return (a * b) % 9 == c;
    }
}

int main()
{
    int t = 0;
    while (input()) {
        cout << ++t << ". ";
        cout << (solve() ? "PASS" : "NOT!") << endl;
    }

    return 0;
}
