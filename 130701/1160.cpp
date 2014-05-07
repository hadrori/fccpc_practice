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

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
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
int w, h;
int c[100][100];
bool inrange(int i, int j){
    return i >= 0 && j >= 0 && i < h && j < w;
}
int di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dj[] = {-1,-1,-1, 0, 0, 1, 1, 1};
void rec(int i, int j){
    c[i][j] = 0;
    rep(k, 8){
        int ni = i + di[k];
        int nj = j + dj[k];
        if(inrange(ni, nj) && c[ni][nj]) rec(ni, nj);
    }
}
int main() {
    while(cin >> w >> h, w){
        rep(i, h) rep(j, w) cin >> c[i][j];
        int cnt = 0;
        rep(i, h) rep(j, w){
            if(c[i][j]){
                rec(i, j);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
