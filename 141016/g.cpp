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
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

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

struct disjoint_set {
    vector<int> p;
    disjoint_set(int n) : p(n, -1) {}
    int root(int i) { return p[i] >= 0 ? p[i] = root(p[i]) : i; }
    void merge(int i, int j) {
        i = root(i), j = root(j);
        if (i == j) return;
        if (p[i] > p[j]) swap(i, j);
        p[i] += p[j], p[j] = i;
    }
    bool same(int i, int j) { return root(i) == root(j); }
};

const int N = 1024;

int n, A[N][N];

bool input()
{
    cin >> n;
    if (n == 0) return false;
    rep(i, n) repi(j, i + 1, n) {
        cin >> A[i][j];
        A[j][i] = A[i][j];
        if (A[i][j] == 0) {
            A[j][i] = A[i][j] = 10000000;
        }
    }
    return true;
}

int t = 0;

bool flg;
string line;

int parse(int& pos, int p, vector<int>& done)
{
    int ret = 0;
    if (line[pos] == '(') {
        ++pos;
        int v = 0;
        while (isdigit(line[pos])) {
            v *= 10, v += line[pos++] & 15;
        }
        --v;
        if (v < 0 or n <= v) {
            flg = false;
            return 0;
        }
        done[v] = 1;
        if (p >= 0) ret += A[p][v];
        while (line[pos] != ')') {
            ++pos;
            ret += parse(pos, v, done);
        }
        ++pos;
    } else {
        int v = 0;
        while (isdigit(line[pos])) {
            v *= 10, v += line[pos++] & 15;
        }
        --v;
        if (v < 0 or n <= v) {
            flg = false;
            return 0;
        }
        done[v] = 1;
        if (p >= 0) ret += A[p][v];
    }
    return ret;
}

void solve()
{
    ++t;

    int mst = 0;
    vector<pair<int, pair<int, int> > > v;
    rep(i, n) repi(j, i + 1, n) {
        v.pb(mp(A[i][j], mp(i, j)));
    }
    sort(all(v));
    disjoint_set uf(n);
    rep(i, v.size()) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        if (not uf.same(a, b)) {
            mst += v[i].first;
            uf.merge(a, b);
        }
    }
    int q;
    cin >> q;
    getline(cin, line);
    rep(i, q) {
        getline(cin, line);
        int pos = 0, p = -1;
        flg = true;
        vector<int> done(n);
        int cur = parse(pos, p, done);
        cout << t << "." << i + 1 << " ";
        cout << (cur == mst and accumulate(all(done), 0) == n ? "YES" : "NO") << endl;
    }
}

int main()
{
    while (input()) solve();

    return 0;
}
