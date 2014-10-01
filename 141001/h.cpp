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

struct person
{
    string name;
    int d, m, y;
    person(string name, int d, int m, int y) : name(name), d(d), m(m), y(y) {}
    bool operator <(const person& t) const {
        return mp(y, mp(m, d)) < mp(t.y, mp(t.m, t.d));
    }
};

int main()
{
    int n;
    cin >> n;
    vector<person> v;
    rep(i, n) {
        string name;
        int d, m, y;
        cin >> name >> d >> m >> y;
        v.pb(person(name, d, m, y));
    }
    sort(all(v));

    cout << v.back().name << endl;
    cout << v[0].name << endl;

    return 0;
}
