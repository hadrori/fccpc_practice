#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define all(c) begin(c),end(c)
#ifndef DEBUG
const string name = "headshot";
ifstream fin(name + ".in");
ofstream fout(name + ".out");
#define cin fin
#define cout fout
#endif

int k, n;
string s;

void input()
{
    cin >> s;
    k = count(all(s), '0');
    n = s.length();
    s.push_back(s[0]);
}

void solve()
{
    int safe = 0, total = 0;
    rep(i, n) {
        if (s[i] == '0') {
            if (s[i+1] == '0') ++safe;
            ++total;
        }
    }
    if (safe * n > total * k) {
        cout << "SHOOT" << endl;
    } else if (safe * n < total * k) {
        cout << "ROTATE" << endl;
    } else {
        cout << "EQUAL" << endl;
    }
}

int main()
{
    input();
    solve();
}
