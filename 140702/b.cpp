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

const int MAX = 32;
int h, w;
bool inrange(int x, int y){
    return x >= 0 && y >= 0 && x < w && y < h;
}
int wall[4][MAX][MAX], done[MAX][MAX];
const int dx[] = {0, 1, 0,-1};
const int dy[] = {-1, 0, 1, 0};
struct node {
    int x, y, step;
};
int main()
{
    while(cin >> w >> h, w||h) {
        memset(wall, 0, sizeof(wall));
        // input
        rep(j, w) wall[0][0][j] = wall[2][h-1][j] = 1;
        rep(i, h) {
            wall[1][i][w-1] = wall[3][i][0] = 1;
            rep(j, w-1) {
                cin >> wall[1][i][j];
                wall[3][i][j+1] = wall[1][i][j];
            }
            if(i == h-1) break;
            rep(j, w) {
                cin >> wall[2][i][j];
                wall[0][i+1][j] = wall[2][i][j];
            }
        }

        queue<node> q;
        memset(done, 0, sizeof(done));
        q.push((node){0, 0, 0});
        int ans = 0;
        while(q.size()) {
            int x = q.front().x;
            int y = q.front().y;
            int step = q.front().step;
            q.pop();
            if(done[x][y]) continue;
            done[x][y] = 1;
            if(x == w-1 && y == h-1) {
                ans = step+1;
                break;
            }
            rep(i, 4) if(!wall[i][y][x]) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(inrange(nx, ny)) q.push((node){nx, ny, step+1});
            }
        }
        cout << ans << endl;

    }
    return 0;
}
