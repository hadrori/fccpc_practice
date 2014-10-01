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
#include <ext/rope>

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
typedef __gnu_cxx::crope rope;

const int N = 1000010;

char buffer[N];

int d = 0;

int main()
{
    rope now;

    int n;
    scanf("%d", &n);
    rep(i, n) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int p;
            scanf("%d%s", &p, buffer);
            p -= d;
            now.insert(p, buffer);
        } else if (type == 2) {
            int p, c;
            scanf("%d%d", &p, &c);
            p -= d, c -= d;
            now.erase(p, c);
        } else if (type == 3) {
            int v, p, c;
            scanf("%d%d%d", &v, &p, &c);
            v -= d, p -= d, c -= d;
            repi(i, p, p + c) {
                char tmp = now.substr(i, 1)[0];
                putchar(tmp);
                d += tmp == 'c';
            }
        }
    }

    return 0;
}
