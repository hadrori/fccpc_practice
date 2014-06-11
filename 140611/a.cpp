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

vector<int> v;

int main()
{
    rep(i, 4) {
        string s;
        cin >> s;
        v.pb(s.length() - 2);
    }

    vector<int> g;
    rep(i, 4) {
        bool s = true, l = true;
        rep(j, 4) if (j != i) {
            if (2 * v[i] > v[j]) s = false;
            if (v[i] < 2 * v[j]) l = false;
        }
        if (s or l) g.pb(i);
    }

    if (g.size() == 1) {
        cout << (char) ('A' + g[0]) << endl;
    } else {
        cout << 'C' << endl;
    }

    return 0;
}
