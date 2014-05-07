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

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a) ; i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i!= (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end)

#define pb push_back
#define mp makek_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
ll n, m, t;
vector<int> c;
struct customer{
    ll t;
    int p;
    ll w;
    ll e;
};
vector<customer> cv;

struct query{
    int kind; // 0: enter, 1: eat end, 
    int id;   
    ll time;
    int x, y;
    bool operator<(const query &o) const{
	return time > o.time;
    }
};

struct waiter{
    int id;
    ll time;
    bool operator<(const waiter &o) const {
	return cv[id].t > cv[o.id].t;
    }
};

struct cand{
    int sl, sr, x, y;
    bool operator<(const cand &o) const {
	if(min(sl, sr) != min(o.sl, o.sr)) return min(sl, sr) < min(o.sl, o.sr);
	if(max(sl, sr) != max(o.sl, o.sr)) return max(sl, sr) < max(o.sl, o.sr);
	if(x != o.x) return x > o.x;
	y > o.y;
    }
};

int main(){
    while(cin >> n >> m >> t, n) {
	// input
	c.resize(n);
	cv.resize(m);
	rep(i, n) cin >> c[i];
	rep(i, m) cin >> cv[i].t >> cv[i].p >> cv[i].w >> cv[i].e;
	
	priority_queue<query> pq;
	vector<vector<int> > SL(n), SR(n), seat(n);
	rep(i, n) {
	    SL[i].resize(m);
	    SR[i].resize(m);
	    seat[i].resize(m);
	}
	rep(i, n) rep(j, m) {
	    SL[i][j] = INF;
	    SR[i][j] = INF;
	}
	rep(i, n) {
	    pq.push((query){0, i, cv[i].t, 0, 0});
	}
	priority_queue<waiter> wpq;
	double ans = 0;
	while(!pq.empty()) {
	    int kind = pq.top().kind;
	    int id = pq.top().id;
	    ll time = pq.top().time;
	    int x = pq.top().x;
	    int y = pq.top().y;
	    pq.pop();
	    while(!wpq.empty() && wpq.top().time < time) {
		wpq.pop();
		ans -= 1.0;
	    }

	    if(kind == 0) { // enter
		vector<cand> cands;
		rep(i, n) rep(j, c[i] - cv[id].p){
		    bool flag = true;
		    repi(k, j, j + cv[id].p) if(seat[i][k]) flag = false;
		    if(flag) cands.pb((cand){SL[i][j], SR[i][j+cv[id].p], i, j});
		}
		if(cands.size() > 0) {
		    cand mc = *max_element(all(cands));
		    // renew seat
		    repi(i, mc.y, mc.y + cv[id].p) seat[mc.x][i] = 1;
		    
		    // renew SL, SR
		    int cnt = 0;
		    rep(i, c[mc.x]) {
			SL[mc.x][i] = cnt;
			if(seat[mc.x][i]){
			    cnt = 0;
			} else {
			    cnt++;
			}
		    }
		    cnt = 0;
		    repd(i, c[mc.x]-1, 0) {
			SR[mc.x][i] = cnt;
			if(seat[mc.x][i]){
			    cnt = 0;
			} else {
			    cnt++;
			}
		    }

		    ans += (double)(cv[id].w - (time - cv[id].t))/(cv[id].w);
		    pq.push((query){1, id, time + cv[id].e, mc.x, mc.y});
		} else {
		    wpq.push((waiter){id, cv[id].t + cv[id].w});
		}
	    } else if(kind == 1) { // leave
		// renew seat
		repi(i, y, y + cv[id].p) seat[x][i] = 0;

		// renew SL, SR
		int cnt = 0;
		rep(i, c[x]) {
		    SL[x][i] = cnt;
		    if(seat[x][i]){
			cnt = 0;
		    } else {
			cnt++;
		    }
		}
		cnt = 0;
		repd(i, c[x]-1, 0) {
		    SR[x][i] = cnt;
		    if(seat[x][i]){
			cnt = 0;
		    } else {
			cnt++;
		    }
		}

		while(!wpq.empty()) {
		    int wid = wpq.top().id;
		    wpq.pop();
		    pq.push((query){0, wid, time, 0, 0});
		}
	    }
	}
	ans /= m;
	cout << ans << endl;
    }
    return 0;
}
