#include <bits/stdc++.h>
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

string line;

int config[3];

ll parse(int& pos, int prior)
{
    if (prior == 3) {
        if (line[pos] == '(') {
            ++pos;
            ll ret = parse(pos, 0);
            ++pos;
            return ret;
        }
        ll ret = 0;
        while (isdigit(line[pos])) {
            ret *= 10, ret += line[pos++] - 48;
        }
        return ret;
    }

    ll ret = parse(pos, prior + 1);
    while (pos < int(line.length())) {
        char op = line[pos];
        if (op == ')' or config[string("+-*").find(op)] < prior) break;
        ++pos;
        switch (op) {
        case '+':
            ret += parse(pos, prior + 1);
            break;
        case '-':
            ret -= parse(pos, prior + 1);
            break;
        case '*':
            ret *= parse(pos, prior + 1);
            break;
        }
    }
    return ret;
}

void solve()
{
    vector<ll> ret;
    rep(i, 27) {
        int tmp = i;
        rep(j, 3) {
            config[j] = tmp % 3;
            tmp /= 3;
        }

        int pos = 0;
        ret.pb(parse(pos, 0));
    }
    cout << *max_element(all(ret)) << endl;
}

int main()
{
    cin >> line;
    solve();

    return 0;
}
