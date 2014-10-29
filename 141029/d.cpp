#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

inline int lcm(int a, int b) { return a / __gcd(a, b) * b; }
/*
int simulate(int n, int x, int y) {
    int ret = 0, sx = x, sy = y;
    do {
        int tmp = (x + y) % n;
        y = (x + y + y) % n;
        x = tmp;
        ++ret;
    } while (x != sx or y != sy);
    return ret;
}
*/
int simulate(int n)
{
    int ret = 1, a = 1, b = 1;
    while (a != 1 or b != 0) {
        int c = (a + b) % n;
        b = (b + c) % n, a = c;
        ++ret;
    }
    return ret;
}

int main()
{
    int mx = 0;
    repi(i, 2, 40000) {
        int tmp = simulate(i);
        if (mx < tmp) {
            mx = tmp;
            cout << i << ' ' << tmp << endl;
        }
    }

    return 0;
}
