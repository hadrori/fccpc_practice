#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>

#define repi(i,a,b) for(int i = int(a); i < int(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = int(a); i >= int(b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);

using namespace std;

typedef long long ll;

void swap4(int &a, int &b, int &c, int &d) {
    int tmp = a;
    a = b;
    b = c;
    c = d;
    d = tmp;
}

void up(vector<int> &d) {
    swap4(d[0], d[2], d[5], d[4]);
}

void right(vector<int> &d) {
    swap4(d[4], d[3], d[2], d[1]);
}


void next_dice(vector<int> &d, int k) {
    up(d);
    if(k % 4 == 3) right(d);
    if(k == 15) {
        up(d);
        right(d);
    } else if(k == 19) right(d);
}


int n;
signed main(){
    while(cin >> n, n) {
        vector<vector<int> > d(4);
        map<string, int> table;
        int id = 0;
        rep(i, 4) d[i].resize(6);

        rep(i, n) {
            string ts;
            rep(j, 6) {
                cin >> ts;
                if(table.find(ts) == table.end()) table[ts] = id++;
                d[i][j] = table[ts];
            }
            swap(d[i][3], d[i][4]);
        }

        if(n == 1) {
            cout << 0 << endl;
            continue;
        }

        int ans = 1000;
        rep(i1, 24) {
            rep(i2, 24) {
                rep(i3, 24) {
                    int tmp = 0;
                    rep(k, 6) {
                        vector<int> cnt(id);
                        rep(i, n) {
                            cnt[d[i][k]]++;
                        }
                        tmp += n - *max_element(all(cnt));
                    }
                    ans = min(ans, tmp);
                    next_dice(d[3], i3);
                    if(n <= 3) break;
                }
                next_dice(d[2], i2);
                if(n <= 2) break;
            }
            next_dice(d[1], i1);
            if(n <= 1) break;
        }

        cout << ans << endl;
    }
    return 0;
}
