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
    int N, code;
    bool valid;
    entry(int N, string D) : N(N), valid(true) {
        int s = D[0] == '-';
        int a = D[s] - '0';
        long b = 0;
        {
            string tmp = D.substr(2 + s);
            tmp.resize(16, '0');
            rep(i, 16) b *= 10, b += tmp[i] - '0';
        }

        if (a) valid = false;
        if (a == 1 and s and b == 0) {
            valid = true;
            code = 1 << 16;
            return;
        }

        rep(i, 16) b /= 5;
        if (s) b = -b;
        code = b & (1 << 17) - 1;
    }
    bool operator <(const entry &t) const {
        return N < t.N;
    }
};

ostream & operator <<(ostream &out, const entry &t)
{
    if (!t.valid) return out << "INVALID VALUE";

    int code = t.code;
    return out << opcode[code >> 12]
               << ' '
               << (code >> 1 & (1 << 11) - 1)
               << ' '
               << (code & 1 ? 'D' : 'F');
}

int P;
vector<entry> V;

void input()
{
    cin >> P;
    rep(i, P) {
        int N;
        string D;
        cin >> N >> D;
        V.pb(entry(N, D));
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
