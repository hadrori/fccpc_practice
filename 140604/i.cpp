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

const int CENTER = 400;
int idx[405][806];
int a[160006];
int sum[160006];
int n;

int solve() {
    sum[0] = a[0];
    rep(i, n*n-1) sum[i+1] = sum[i] + a[i+1];
    int ans = -1000000000;
    rep(i, n) repi(j, CENTER-i, CENTER+i+1) {
        int ti = i, cj = j, num = 1;
        int tmp = a[idx[i][j]];
        ans = max(ans, tmp);
        if((i+j)%2 == 0) {
            while(idx[ti+1][cj-num] != -1 && idx[ti+1][cj+num] != -1) {
                tmp -= sum[idx[ti+1][cj-num]-1];
                tmp += sum[idx[ti+1][cj+num]];
                ans = max(ans, tmp);
                ti++;
                num++;
            }
        } else {
//            cout << "a " << i << " " << j-CENTER << endl;
            while(ti >= 1 && idx[ti-1][cj-num] != -1 && idx[ti-1][cj+num] != -1) {
                tmp -= sum[idx[ti-1][cj-num]-1];
                tmp += sum[idx[ti-1][cj+num]];
//                cout << "b " << idx[ti-1][cj-num]-1 << " " << idx[ti-1][cj+num] << " " << tmp << endl;
                ans = max(ans, tmp);
                ti--;
                num++;
            }
        }
    }
    return ans;
}

void gen() {
    memset(idx, -1, sizeof(idx));
    int cnt = 0;
    rep(i, n) repi(j, CENTER-i, CENTER+i+1) {
        idx[i][j] = cnt++;
    }
}

int main()
{
    int cnt = 0;
    gen();
    while(cin >> n, n) {
        gen();
        rep(i, n*n) cin >> a[i];
        cnt++;
        cout << cnt << ". " << solve() << endl;
    }
    
    return 0;
}
