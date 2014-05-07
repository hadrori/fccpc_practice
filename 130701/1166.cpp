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
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool inrange(int y, int x){
    return y >= 0 && x >= 0 && x < w && y < h;
}
int wall[31][31][31][31];
struct node{
    int y;
    int x;
    int cst;
    bool operator<(const node &o)const{
        return cst > o.cst;
    }
};
int main() {
    while(cin >> w >> h, w){
        int tmp;
        memset(wall, 0, sizeof(wall));
        rep(i, h){
            rep(j, w-1){
                cin >> tmp;
                wall[i][j][i][j+1] = tmp;
                wall[i][j+1][i][j] = tmp;
            }
            if(i != h-1) {
                rep(j, w){
                    cin >> tmp;
                    wall[i][j][i+1][j] = tmp;
                    wall[i+1][j][i][j] = tmp;
                }
            }
        }
        int ans = 0;
        int done[31][31] = {0};
        priority_queue<node> pq;
        pq.push((node){0,0,1});
        while(!pq.empty()){
            int y = pq.top().y;
            int x = pq.top().x;
            int cst = pq.top().cst;
            pq.pop();
//            cout << x << " " << y << "  "<< cst << endl;
            if(x == w-1 && y == h-1){
                ans = cst;
                break;
            }
            if(done[y][x]) continue;
            done[y][x] = 1;
            rep(i, 4){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(inrange(ny, nx) && !wall[y][x][ny][nx]) pq.push((node){ny, nx, cst + 1});
            }
        }
        cout << ans << endl;
    }
    return 0;
}
