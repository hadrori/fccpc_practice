#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

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

int t, n;
int dx[] = {0, 1, 1, 0, -1, -1};
int dy[] = {1, 1, 0, -1, -1, 0};
struct node{
    int x;
    int y;
    int step;
};
bool inrange(int x, int y){
    return x >= 0 && y >= 0 && x <= 200 && y <= 200;
}
bool jam[201][201];
int main(){
    while(cin >> t >> n, t||n){
        memset(jam, 0, sizeof(jam));
        rep(i, n){
            int bx, by;
            cin >> bx >> by;
            bx += 100;
            by += 100;
            jam[bx][by] = true;
        }
        int sx, sy;
        cin >> sx >> sy;
        sx += 100;
        sy += 100;
        queue<node> q;
        set<pair<int, int> > st;
        q.push((node){sx, sy, 0});
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int step = q.front().step;
            q.pop();
            //      cout << x << " " << y << " " << step << endl;
            if(st.find(mp(x, y)) != st.end()) continue;
            if(step >= t+1) break;
            st.insert(mp(x, y));
            rep(i, 6){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(inrange(nx, ny) && !jam[nx][ny]){
                    q.push((node){nx, ny, step+1});
                }
            }
            
        }
        cout << st.size() << endl;
    }
}
