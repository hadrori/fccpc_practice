#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define all(c) begin(c),end(c)
#ifndef DEBUG
const string name = "kequiv"; // input filename here!!
ifstream fin(name + ".in");
ofstream fout(name + ".out");
#define cin fin
#define cout fout
#endif

#define long int64_t

int main()
{
    int n;
    cin >> n;
    rep(i, n) {
        long a, b;
        cin >> a >> b;
        
        long d = 1;
        set<int> st;
        rep(_, 19) {
            if(a > d and a%d != 0) {
                st.insert((a/d)%10);
            }
            if(b > d and b%d + 1 != d) {
                st.insert((b/d-1)%10);
            }
            if(a > d)
                st.insert((a/d-1)%10);
            if(b > d)
                st.insert((b/d)%10);
            d *= 10;
        }

        repi(i, 1, 10) {
            cout << i;
            if(i < 9 and st.find(i) != st.end())
                cout << endl;
        }
        cout << endl;
    }
}
