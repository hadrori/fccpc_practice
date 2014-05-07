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
int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0,-1};
int h, w;
vector<string> wall;

struct node{
    int y, x, cst;
};
bool inrange(int y, int x){
    return y >= 0 & x >= 0 && y < h && x < w;
}

int cst[31][31];
int cst2[31][31];

int main() {
    while(cin >> h >> w, h){
	wall.resize(2*h-1);
	cin.ignore();
	rep(i, h*2-1) getline(cin, wall[i]);
	memset(cst, 0, sizeof(cst));
/*
	queue<node> q;
	int done[31][31] = {0};
	q.push((node){0, 0, 0});
	while(!q.empty()){
	    int y = q.front().y;
	    int x = q.front().x;
	    int cs = q.front().cst;
	    q.pop();
	    if(done[y][x]) continue;
	    done[y][x] = 1;
	    cst2[y][x] = cs;
	    rep(k, 4){
		int wy = 2*y + dy[k];
		int wx = 2*x + dx[k];
		if(inrange(y + dy[k], x + dx[k]) && wall[wy][wx] == '0'){
		    q.push((node){y+dy[k], x+dx[k], cs + 1});
		}
	    }
	}
*/
	bool reachable = true;
	rep(a, h*2-1) rep(b, wall[a].size()) if(wall[a][b] == '0') {
	    queue<node> q;
	    int done[31][31] = {0};
	    q.push((node){0, 0, 0});
	    bool flag = true;
	    wall[a][b] = '1';
	    while(!q.empty()){
		int y = q.front().y;
		int x = q.front().x;
		int cs = q.front().cst;
		q.pop();
		if(done[y][x]) continue;
		done[y][x] = 1;
		if(y == h-1 && x == w-1) {
		    flag = false;
		    break;
		}
		rep(k, 4){
		    int wy = 2*y + dy[k];
		    int wx = 2*x + dx[k];
		    if(inrange(y + dy[k], x + dx[k]) && wall[wy][wx] == '0'){
			q.push((node){y+dy[k], x+dx[k], cs + 1});
		    }
		}
	    }
	    wall[a][b] = '0';
	    if(flag) reachable = false;
	}
	
	if(!reachable){
	    cout << -1 << endl;
	    continue;
	}
	rep(a, h*2-1) for(int b = 1-a%2; b < wall[a].size(); b+=2) {
	    if(wall[a][b] == '0') {
		wall[a][b] = '1';
		int c1, c2;
		queue<node> q;
		int done[31][31] = {0};
		q.push((node){h-1, w-1, 0});
		while(!q.empty()){
		    int y = q.front().y;
		    int x = q.front().x;
		    int cs = q.front().cst;
		    q.pop();
		    if(done[y][x]) continue;
		    done[y][x] = 1;
		    cst[y][x] = max(cst[y][x], cs);
		    rep(k, 4){
			int wy = 2*y + dy[k];
			int wx = 2*x + dx[k];
			if(inrange(y + dy[k], x + dx[k]) && wall[wy][wx] == '0'){
			    q.push((node){y+dy[k], x+dx[k], cs + 1});
			}
		    }
		}
		wall[a][b] = '0';
	    }
	}
//	rep(i, h) rep(j, w) cout << cst2[i][j] << (j < w-1?" ":"\n");
	int lower = 0;
	int upper = 30*30+1;
	int mid;
	while(upper - lower > 1){
	    bool flag = false;
	    mid = (lower + upper) / 2;
	    queue<node> q;
	    int done[31][31] = {0};
	    q.push((node){0, 0, 0});
	    while(!q.empty()){
		int y = q.front().y;
		int x = q.front().x;
		int cs = q.front().cst;
		q.pop();
		if(done[y][x]) continue;
		done[y][x] = 1;
		if(y == h-1 && x == w-1) {
		    flag = true;
		    break;
		}
		rep(k, 4){
		    int wy = 2*y + dy[k];
		    int wx = 2*x + dx[k];
		    if(inrange(y + dy[k], x + dx[k]) && wall[wy][wx] == '0' && cst[y+dy[k]][x+dx[k]] + cs + 1 <= mid){
			q.push((node){y+dy[k], x+dx[k], cs + 1});
		    }
		}
	    }
	    if(!flag) lower = mid;
	    else upper = mid;
	}
	cout << upper << endl;
    }
    return 0;
}
