#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define long int64_t

long a, b;
string s;

bool input() {cin>>a>>b>>s;
}

const int N = 108;

const string dir = "UDLR";
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

bool field[2*N][2*N];

bool reach(long x, long y) { x+=N,y+=N; return 0 <= x and x < 2*N and 0 <= y and y < 2*N and field[x][y]; }

bool solve() {
    long x = N, y = N;
    for (char c : s) {
        field[x][y] = true;
        int i = dir.find(c);
        x += dx[i], y += dy[i];
    }
    long bx = x - N, by = y - N, t = 0;
    if (bx != 0) {
        t = a / bx;
        a -= t * bx;
        b -= t * by;
    } else if (by != 0) {
        t = b / by;
        a -= t * bx;
        b -= t * by;
    }
    repi(i,-N,N) {
        if (t-i>=0 and reach(a+i*bx,b+i*by)) return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    input();
    cout << (solve() ? "Yes" : "No") << endl;
    return 0;
}
