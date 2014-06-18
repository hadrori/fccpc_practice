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

struct node {
    int cst;
    int x, y;
    int dir;
    bool operator<(const node &o) const {
        return cst > o.cst;
    }
};
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int w, h;
int f[32][32];
bool inrange(int x, int y) {
    return x >= 0 and y >= 0 and x < w and y < h;
}
int main()
{
    while(cin >> w >> h, w||h) {
        rep(i, h) rep(j, w) cin >> f[j][i];
        vector<int> c(4);
        rep(i, 4) cin >> c[i];

        bool done[32][32][4] = {0};        
        priority_queue<node> pq;
        pq.push((node){0, 0, 0, 1});
        while(pq.size()) {
            int cst = pq.top().cst;
            int x = pq.top().x;
            int y = pq.top().y;
            int dir = pq.top().dir; pq.pop();
            if(done[x][y][dir]) continue;
            done[x][y][dir] = true;

            if(x == w-1 and y == h-1) {
                cout << cst << endl;
                break;
            }
            rep(i, 4) {
                int df = c[i];
                int ndir = (dir + i) % 4;
                if(f[x][y] == i) df = 0;
                int nx = x + dx[ndir];
                int ny = y + dy[ndir];
                if(inrange(nx, ny))
                    pq.push((node){cst+df, nx, ny, ndir});
            }
        }
    }
    return 0;
}
