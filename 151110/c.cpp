#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define pb push_back
#define all(u) begin(u),end(u)
#define mp make_pair
#define long int64_t

const long mod = 1000000007;

string s, t;
int n;

string get() {
    string line;
    cin >> ws;
    getline(cin, line);
    string ret;
    for (char c : line) if (isgraph(c)) ret.push_back(c);
    return ret;
}

void input() {
    s = get();
    t = get();
    n = s.length();
}

long var[26];

long parseExpr(string& s, int& i);
long parseFactor(string& s, int& i) {
    if (s[i] == '(') {
        ++i;
        long ret = parseExpr(s, i);
        ++i;
        return ret;
    }
    if (isdigit(s[i])) return s[i++] - '0';
    if (islower(s[i])) return var[s[i++] - 'a'];
    if (isupper(s[i])) return var[s[i++] - 'A'];
    assert(false);
    return -1;
}

long parseTerm(string& s, int& i) {
    long ret = parseFactor(s, i);
    while (i < s.length() and s[i] == '*') {
        ++i;
        ret = ret * parseFactor(s, i) % mod;
    }
    return ret;
}

long parseExpr(string& s, int& i) {
    long ret = parseTerm(s, i);
    while (i < s.length() and (s[i] == '+' or s[i] == '-')) {
        if (s[i] == '+') {
            ++i;
            ret = (ret + parseTerm(s, i)) % mod;
        } else if (s[i] == '-') {
            ++i;
            ret = (ret - parseTerm(s, i) + mod) % mod;
        }
    }
    return ret;
}

bool solve() {
    rep(_, 1000) {
        rep(i, 26) var[i] = rand() % mod;
        int pos = 0, pos1 = 0;
        if (parseExpr(s, pos) != parseExpr(t, pos1)) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    int _; cin >> _;
    while(_--) {
        input();
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}
