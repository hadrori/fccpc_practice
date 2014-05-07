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
typedef complex<double> P;
typedef vector<P> G;

/* 円 */
struct C {
    P p; double r;
    C() : p(0), r(0) {}
    C(const P &p, double r) : p(p), r(r) { }
};

bool intersectCC(const C &c, const C &d){
    return (norm(c.p - d.p) - (c.r + d.r)*(c.r + d.r) < -EPS);
}

int ans, n;
set<int> done;
vi E[32];
vector<C> cir;
vi col;

void input(){
    rep(i,n){
	int x, y, r, c;
	cin >> x >> y >> r >> c;
	cir.pb(C(P(x,y),r));
	col.pb(c);
    }
}

void init(){
    ans = 0;
    done.clear();
    cir.clear();
    col.clear();
    rep(i,32) E[i].clear();
    return;
}

void make_edge(){
    rep(i,n)repi(j,i+1,n)
	if(intersectCC(cir[i],cir[j])){
//	    cerr << i << ' ' << j << endl;
	    E[j].pb(i);
	}
    return;
}

void saiki(int S){
    if(done.find(S) != done.end()) return;
    done.insert(S);
    bool naiyo = true;
    rep(i,n)repi(j,i+1,n)if(((S>>i)&1) && ((S>>j&1)) && (col[i] == col[j])){
	bool ok = true;
	rep(a,E[i].size())if((S>>E[i][a])&1){
	    ok=false;
	    break;
	}
	if(!ok) continue;
	ok = true;
	rep(a,E[j].size())if((S>>E[j][a])&1){
	    ok=false;
	    break;
	}
	if(!ok) continue;
/*
	cerr << "hoge\n";
	cerr << i << " " << j << endl;
*/
	saiki(S^(1<<i)^(1<<j));
	naiyo = false;
    }
    if(naiyo){
	int cnt = 0;
	rep(i,n)if((S>>i)&1)cnt++;
	ans = max(ans, n-cnt);
    }
    return;
}

int main() {
    while(cin >> n, n){
	init();
	input();
	make_edge();
	saiki((1<<n)-1);
	cout << ans << endl;
    }
    return 0;
}
