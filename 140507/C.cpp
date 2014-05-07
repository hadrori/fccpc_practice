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

string s;

bool solve(int a, int b, int all = 1)
{
    vector<bool> child;
    {
        int depth = 0, prev = -1;
        repi(i, a, b) {
            if (s[i] == 'T') {
                if (depth == 0) child.pb(true);
            } else if (s[i] == 'F') {
                if (depth == 0) child.pb(false);
            } else if (s[i] == '(') {
                if (depth == 0) prev = i;
                ++depth;
            } else if (s[i] == ')') {
                --depth;
                if (depth == 0) child.pb(solve(prev + 1, i, !all));
            }
        }
    }

    if (all) {
        bool ret = true;
        rep(i, int(child.size())) ret &= child[i];
        return ret;
    } else {
        bool ret = false;
        rep(i, int(child.size())) ret |= child[i];
        return ret;
    }
}

int height(int a, int b)
{
    vector<int> child;
    {
        int depth = 0, prev = -1;
        repi(i, a, b) {
            if (s[i] == '(') {
                if (depth == 0) prev = i;
                ++depth;
            } else if (s[i] == ')') {
                --depth;
                if (depth == 0) child.pb(height(prev + 1, i));
            }
        }
    }

    if (child.empty()) return 0;
    return *max_element(all(child)) + 1;
}

int main()
{
    int cnt = 0;
    while (cin >> s && s != "()") {
        cout << ++cnt << ". " << (solve(0, s.length(), ~height(0, s.length()) & 1) ? "true" : "false") << endl;
    }

    return 0;
}
