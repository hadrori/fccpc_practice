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

int seg[] = {
    0x3f,
    0x0a,
    0x5d,
    0x4f,
    0x6a,
    0x67,
    0x77,
    0x0b,
    0x7f,
    0x6b
};

int value(int n)
{
    rep(i, 10) if (seg[i] == n) return i;
    return -1;
}

int get(string& s, int& i, char delim)
{
    int ret = 0;
    while (s[i] != delim) {
        int d = 0;
        (d *= 10) += s[i++] & 15;
        (d *= 10) += s[i++] & 15;
        (d *= 10) += s[i++] & 15;
        (ret *= 10) += value(d);
    }
    return ret;
}

void dump(int n)
{
    if (n) {
        dump(n / 10);
        printf("%03d", seg[n % 10]);
    }
}

int main()
{
    string s;
    while (cin >> s and s != "BYE") {
        int i = 0;
        int a = get(s, i, '+');
        ++i;
        int b = get(s, i, '=');

        cout << s;
        dump(a + b);
        cout << endl;
    }

    return 0;
}
