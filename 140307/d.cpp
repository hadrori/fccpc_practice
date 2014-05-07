#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>ago
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

const string opcode("PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV");

struct entry
{
    int N, integ;
    string sgn, frac;
    entry(int N, char c, int d, char s) : N(N), sgn(), integ(0), frac(16, '0') {
        long b = opcode.find(c) << 12 | d << 1 | s == 'D';
        if (b == 1 << 16) {
            sgn = "-";
            integ = 1;
            frac = "0";
            return;
        }
        if (b >> 16) {
            sgn = "-";
            b = -b & (1 << 17) - 1;
        }
        rep(i, 16) b *= 5;
        rep(i, 16) {
            frac[15 - i] = '0' + b % 10;
            b /= 10;
        }
        int j = 16;
        while (j >= 2 and frac[j - 1] == '0') --j;
        frac = frac.substr(0, j);
    }
    bool operator <(const entry &t) const {
        return N < t.N;
    }
};

ostream & operator <<(ostream &out, const entry &t)
{
    return out << t.sgn << t.integ << '.' << t.frac;
}

int P;
vector<entry> V;

void input()
{
    cin >> P;
    rep(i, P) {
        int N, d;
        char c, s;
        cin >> N >> c >> d >> s;
        V.pb(entry(N, c, d, s));
    }
    sort(all(V));
}

void solve()
{
    rep(i, P) {
        cout << V[i].N << ' ' << V[i] << endl;
    }
}

int main()
{
    input();
    solve();

    return 0;
}
