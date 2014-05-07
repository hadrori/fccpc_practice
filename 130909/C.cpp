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

int HP, HPm;
int R, C, T, S, P;
vector<string> field;
vector<char> trap;
map<char,int> damage;
vector<pair<char,int> > move;
vi potion;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
string dir = "UDLR";

int main()
{
    while(cin >> HP >> HPm, HP || HPm){
	cin >> R >> C;
	field.resize(R);
	rep(i,R) cin >> field[i];
	cin >> T;
	trap.clear();
	rep(i,T){
	    char a;
	    int t;
	    cin >> a >> t;
	    trap.pb(a);
	    damage[a] = t;
	}
	sort(all(trap));
	cin >> S;
	move.clear();
	rep(i,S){
	    char a;
	    int t;
	    cin >> a >> t;
	    move.pb(mp(a,t));
	}
	cin >> P;
	potion.resize(P);
	rep(i,P) cin >> potion[i];
	sort(all(potion));
	int x = 0, y = 0;
	int cur = 0;
	rep(i,S){
	    int d = dir.find(move[i].first);
	    rep(j,move[i].second){
		x += dx[d]; y += dy[d];
		char c = field[y][x];
		vector<char>::iterator itr = lower_bound(all(trap),c);
		HP -= damage[*itr];
		while(potion.size() < P && HP <= 0){
		    vi::iterator itr = lower_bound(all(potion),-HP);
		    HP = min(HPm, HP + *itr);
		    potion.erase(itr);
		}
		if(HP <= 0) break;
	    }
	    if(HP <= 0) break;
	}
	cout << (HP>0? "YES\n": "NO\n");
    } 
    return 0;
}
