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

#define repi(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) repi(i, 0, a)
#define repd(i, a, b) for(int i = (a); i >= (b); i--)
#define repit(i, a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

#define all(u) (u).begin(), (u).end()
#define rall(u) (u).rbegin(), (u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)), (u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<string> > vvs;
pair<int,int> E;
vvs table;
char goal[3][3];
set<int> done;
map<string,int> id;
string hoge[6];
int ans;
int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};

string rot(string board, int dir){
    string ret = board;
    if(dir%2) {
	swap(ret[0], ret[1]);
    }
    else swap(ret[0], ret[2]);
    return ret;
}

int ton(vvs table){
    int ret = 0;
    int cnt = 0;
    rep(i,3)rep(j,3){
	if(table[i][j] == "EEE") ret += i*4+j;
	else {
	    ret += id[table[i][j].substr(0,2)] << (4+cnt*3);
	    cnt++;
	}
    }
    return ret;
}

vvs tot(int state){
    int ei = (state & 12) / 4;
    int ej = state & 3;
    vvs board(3,vector<string> (3));
    int j = 0;
//    cerr << state << endl;
    rep(i,9){
	if(i/3 != ei || i%3 != ej){
	    int tmp = (state >> (j*3+4)) & 7;
	    board[i/3][i%3] = hoge[tmp];
//  cerr << tmp << ' ' << hoge[tmp] << (i%3==2?'\n': ' ');
	    j++;
	}
    }
//  cerr << endl;
    board[ei][ej] = "EEE";
//  rep(i,3)rep(j,3) cout << board[i][j] << (j!=2? " ": "a\n");
    return board;
}

bool check(){
    rep(i,3)rep(j,3) {
	if(table[i][j][0] != goal[i][j]) return false;
    }
    return true;
}

bool inrange(int i, int j){return i >= 0 && i < 3 && j >= 0 && j < 3 && 1 > 0;}

struct node{
    int k;
    int state;
};
int gi, gj;
void bfs(int k) {
    queue<node> que;
    que.push((node){0, ton(table)});
    done.clear();
    while(!que.empty()){
	k = que.front().k;
	int state = que.front().state;
	que.pop();
	if(k > 30) continue;
	if(done.find(state) != done.end()) continue;
	done.insert(state);
	table = tot(state);
	if(check()){
	    ans = k;
	    break;
	}
	/*
	cout << k << endl;
	rep(i, 3) rep(j, 3) cout << table[i][j][0] << (j<2?" ": "\n");
	cout << endl;
	*/
	int ei = (state & 12) / 4;
	int ej = state & 3;
	if(abs(ei-gi) + abs(ej-gj) + k > 30) continue;
	int cnt = 0;
	rep(i,3)rep(j,3) if(table[i][j][0] != goal[i][j]) cnt++;
	if(cnt + k > 30) continue;
	rep(i,4)if(inrange(ei+di[i],ej+dj[i])){
	    int ni = ei+di[i], nj = ej+dj[i];
	    node tmp;
	    vvs ntab = table;
	    ntab[ei][ej] = rot(table[ni][nj], i);
	    ntab[ni][nj] = "EEE";
	    tmp.state = ton(ntab);
	    tmp.k = k+1;
	    que.push(tmp);
	}
    }
    return;
}

int main(){
    id["WR"] = 0;
    id["WB"] = 1;
    id["RW"] = 2;
    id["RB"] = 3;
    id["BW"] = 4;
    id["BR"] = 5;
    hoge[0] = "WRB";
    hoge[1] = "WBR";
    hoge[2] = "RWB";
    hoge[3] = "RBW";
    hoge[4] = "BWR";
    hoge[5] = "BRW";
    table.resize(3);
    rep(i, 3) table[i].resize(3);
    while(cin >> E.second >> E.first, E.first){
	E.first--; E.second--;
	rep(i,3)rep(j,3) cin >> goal[i][j];
	rep(i,3)rep(j,3){
	    if(i == E.first && j == E.second) {
		table[i][j] = "EEE";
		gi = i;
		gj = j;
	    }else table[i][j] = "WBR";
	}
	ans = -1;
	bfs(0);
	cout << ans << endl;
    }
    return 0;
}
