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

int T, N;


int calc(int X, int Y) {
    if(Y == 0) {
        if(X == 0) return 1;
        return 0;
    }
    int sum = Y*(Y+1)/2;
    if(sum > X) return 0;
    if(sum+1 < X) return 2;
    return 1;
}

int main()
{
    cin >> T;
    for(int _ = 0; _ < T; _++){
        int n, k;
        cin >> n >> k;
        vector<int> a(k+1);
        rep(i, k+1) cin >> a[i];
              
        int Z = a[k-1] - a[k];
        set<int> st;
        rep(i, k) st.insert(a[i]-a[i+1]);
        int Y = n - st.size();
        int cnt = 0;
        int pos = 0;
        int AX;
        if(Z < 0) {
            stack<int> stk;
            while(true) stk.push(0);
            cout << "No Solution" << endl; continue;
        } else if(Z == 0) {
            if(Y == 0) cnt = 1;
        } else if(Y >= 0) {
            for(int X = a[k]; X >= 0; X -= Z){
                cnt += calc(X, Y);
                if(cnt == 0) {
                    pos++;
                    AX = X;
                }
            }
            AX -= Z;
        }
        cout << "Case #" << _+1 << ": " << endl;
        if(cnt == 0) {
            cout << "No Solution" << endl;
        } else if(cnt == 1) {
            cout << "Unique Solution" << endl;
            if(Z > 0) {
                int bf = -1;
                int s = 0;
                rep(i, k) {
                    if(bf != a[i]-a[i+1]){
                        if(bf != -1) cout << i << " " << bf-(a[i]-a[i+1]) << endl;
                    }
                    bf = a[i]-a[i+1];
                }

                int lst = k+pos;
                cout << lst << " " << bf << endl;
                int sum = a[k] - pos*Z;
                int i;
                if(sum) {
                    for(i = 1; sum - i > 1; i++) {
                        cout << lst + i << " " << 1 << endl;
                        sum -= i;
                    }
                    cout << lst + i + sum << " " << 1 << endl;
                }
            } else {
                int bf = -1;
                rep(i, k) {
                    if(bf != a[i]-a[i+1]) {
                        if(bf != -1 && bf-(a[i]-a[i+1])) cout << i << " " << bf-(a[i]-a[i+1]) << endl;
                    }
                    bf - a[i]-a[i+1];
                }
            }
        } else {
            cout << "Multiple Solutions" << endl;
        }
        
    }
    return 0;
}
