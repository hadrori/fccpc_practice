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

using namespace std;

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

typedef long long ll;
typedef vector<int> vi;

struct event
{
    bool buy;
    int num, price;
    event(bool buy, int num, int price) : buy(buy), num(num), price(price) {}
};

int n;
vector<event> v;

void input()
{
    v.clear();

    cin >> n;
    rep(i, n) {
        string type, dummy;
        int num, price;
        cin >> type >> num >> dummy >> dummy >> price;
        v.pb(event(type == "buy", num, price));
    }
}

void solve()
{
    map<int, int> ask, bid;
    int stock = -1;
    rep(i, n) {
        if (v[i].buy) {
            bid[v[i].price] += v[i].num;
        } else {
            ask[v[i].price] += v[i].num;
        }

        while (!ask.empty() and !bid.empty() and bid.rbegin()->first >= ask.begin()->first) {
            stock = ask.begin()->first;
            const int diff = min(bid.rbegin()->second, ask.begin()->second);
            bid.rbegin()->second -= diff;
            ask.begin()->second -= diff;
            if (bid.rbegin()->second == 0) {
                map<int, int>::iterator it = bid.end();
                bid.erase(--it);
            }
            if (ask.begin()->second == 0) {
                ask.erase(ask.begin());
            }
        }

        if (!ask.empty()) cout << ask.begin()->first;
        else cout << '-';

        cout << ' ';

        if (!bid.empty()) cout << bid.rbegin()->first;
        else cout << '-';

        cout << ' ';

        if (stock >= 0) cout << stock;
        else cout << '-';

        cout << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        input();
        solve();
    }

    return 0;
}
