#include <bits/stdc++.h>
using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) _repi(i,0,n)
#define _repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)

const int M = 15504;

int b[M];

int next(int S) {
    int foo = S & -S;
    int bar = S + foo;
    return bar | (S & ~bar) / foo >> 1;
}

void prepare()
{
    const int k = 15;
    const int n = 20;
    int *p = b;
    for (int i = (1<<k)-1; i < 1<<n; i = next(i)) {
        *p++ = i;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    prepare();
    int t = 0;
    char op;
    while (cin >> op, op != 'e') {
        cout << "Case " << ++t << ":";
        if (op == 'm') {
            int t = 0;
            rep(i, 6) {
                int b;
                cin >> b;
                t <<= b + 1;
                t |= (1<<b) - 1;
            }
            cout << ' ' << lower_bound(b, b + M, t) - b << endl;
        } else if (op == 'u') {
            int t;
            cin >> t;
            t = b[t];
            vector<int> ans;
            int b = 0;
            for (int i = 19; i >= 0; --i) {
                if (t>>i & 1) {
                    ++b;
                } else {
                    ans.push_back(b);
                    b = 0;
                }
            }
            ans.push_back(b);
            for (int e : ans) {
                cout << ' ' << e;
            }
            cout << endl;
        }
    }
}
