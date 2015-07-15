#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define all(c) begin(c),end(c)
#ifndef DEBUG
const string name = "database"; // input filename here!!
ifstream fin(name + ".in");
ofstream fout(name + ".out");
#define cin fin
#define cout fout
#endif

#define ulong uint64_t
const ulong p = 9973;
ulong pow_p[100] = {1};
struct _{_(){
    rep(i, 99) pow_p[i+1] = pow_p[i] * p;
}}_;

const int N = 10005;
const int M = 10;
int n, m, len[N][M];
ulong hsh[N][M];

void input()
{
    cin >> n >> m >> ws;
    rep(i, n) {
        string line;
        getline(cin, line);
        int j = 0;
        for (char c : line) {
            if (c == ',') {
                ++j;
            } else {
                ++len[i][j];
                hsh[i][j] = hsh[i][j] * p + c;
            }
        }
    }
}

void solve()
{
    rep(i, m) repi(j, i+1, m) {
        unordered_map<ulong, int> mem;
        rep(k, n) {
            ulong t = hsh[k][i] * 1000000007 + hsh[k][j];
            if (mem.find(t) != mem.end()) {
                cout << "NO" << endl;
                cout << mem[t] << ' ' << k + 1 << endl;
                cout << i + 1 << ' ' << j + 1 << endl;
                return;
            }
            mem[t] = k + 1;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    input();
    solve();
}
