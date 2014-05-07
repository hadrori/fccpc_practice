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

int main()
{
    int n, m, q;
    map<char, int> x, y;
    cin >> n >> m >> q;
    rep(i, n) rep(j, m) {
        char c;
        cin >> c;
        if(c != '*') {
            x[c] = i+1;
            y[c] = j+1;
        }
    }
    rep(i, q) {
        char c;
        cin >> c;
        if(x.find(c) == x.end()) {
            cout << "NA" << endl;
        } else {
            cout << x[c] << " " << y[c] << endl;
        }
        
    }
    return 0;
}
