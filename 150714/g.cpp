#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define all(c) begin(c),end(c)
#ifndef DEBUG
const string name = "garbling"; // input filename here!!
ifstream fin(name + ".in");
ofstream fout(name + ".out");
#define cin fin
#define cout fout
#endif

const int N = 314;
const int N2 = N * N;

int r, c;
string n, rot[N];

void input()
{
    cin >> r >> c >> n;
    rep(i, r-1) cin >> rot[i];
}

pair<string, int> divide(const string& a, int b) {
    string q; int r = 0;
    for (char c : a) {
        int d = c - '0';
        r = r * 10 + d;
        q.push_back('0' | r / b);
        r %= b;
    }
    return make_pair(q, r);
}

int table[N][N], annual[N2];

const int mod = 100000;

vector<int> k_slide_sum(const vector<int> vec, int k) {
    const int n = vec.size();
    vector<int> ret(n);
    if (k == 0) return ret;
    int t = 0;
    rep(i, n+k-1) {
        t = (t + vec[i%n]) % mod;
        if (i >= k - 1) {
            ret[i%n] = t;
            t = (t - vec[i-k+1] % mod + mod) % mod;
        }
    }
    return ret;
}

bool done[N2];
int ans[N2];

void solve()
{
    rep(i, r) rep(j, c) {
       table[i][j] = i * c + j;
    }
    rep(i, r-1) rep(j, c-1) {
        ++annual[table[i][j]];
        if (rot[i][j] == 'L') {
            swap(table[i][j], table[i][j+1]);
            swap(table[i][j+1], table[i+1][j+1]);
            swap(table[i+1][j+1], table[i+1][j]);
        } else if (rot[i][j] == 'R') {
            swap(table[i][j], table[i+1][j]);
            swap(table[i+1][j], table[i+1][j+1]);
            swap(table[i+1][j+1], table[i][j+1]);
        }
    }
    auto pp = divide(n, (r-1)*(c-1));
    const string loop = pp.first;
    rep(i, r*c) if (not done[i]) {
        vector<int> orbit;
        int j = i;
        do {
            done[j] = true;
            orbit.push_back(j);
            j = table[j / c][j % c];
        } while (not done[j]);
        const int len = orbit.size();
        vector<int> vec;
        rep(i, len) {
            vec.push_back(annual[orbit[i]]);
        }
        int uniform_d = accumulate(all(vec), 0LL) % mod;
        int rem = 0;
        auto ppp = divide(loop, len);
        {
            int looppp = ppp.first.length();
            repi(i, max(0, looppp - 5), looppp) {
                rem = rem * 10 + ppp.first[i] - '0';
            }
        }
        uniform_d = (long long) uniform_d * rem % mod;
        vector<int> k_sum = k_slide_sum(vec, ppp.second);
        rep(i, len) {
            ans[orbit[i]] += uniform_d;
            ans[orbit[i]] += k_sum[i];
            while (ans[orbit[i]] >= mod) ans[orbit[i]] -= mod;
        }
        rep(i, len) {
            int u = orbit[i], v = orbit[(i + ppp.second) % len];
            table[u / c][u % c] = v;
        }
    }
    rep(iii, pp.second) {
        const int i = iii / (c - 1);
        const int j = iii % (c - 1);
        ++ans[table[i][j]];
        if (rot[i][j] == 'L') {
            swap(table[i][j], table[i][j+1]);
            swap(table[i][j+1], table[i+1][j+1]);
            swap(table[i+1][j+1], table[i+1][j]);
        } else if (rot[i][j] == 'R') {
            swap(table[i][j], table[i+1][j]);
            swap(table[i+1][j], table[i+1][j+1]);
            swap(table[i+1][j+1], table[i][j+1]);
        }
    }
    rep(i, r*c) cout << ans[i] << endl;
}

int main()
{
    input();
    solve();
}
