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

string s;

struct node{
    int step;
    int cst;
    int lr;
    bool operator<(const node &o) const{
	return cst > o.cst;
    }
};
bool done[100005][2];
int main()
{
    while(cin >> s, s != "#") {
	vector<int> v;
	rep(i, s.size()) v.pb(s[i]-'0'-1);
	priority_queue<node> pq;
	pq.push((node){0, 0, 0});
	pq.push((node){0, 0, 1});
	memset(done, 0, sizeof(done));
	int ans = 10000000;
	while(!pq.empty()) {
	    int step = pq.top().step;
	    int cst = pq.top().cst;
	    int lr = pq.top().lr;
	    pq.pop();
	    if(done[step][lr]) continue;
	    done[step][lr] = true;
	    if(step == s.size()-1) {
		ans = min(ans, cst);
		continue;
	    }
	    if(v[step]%3 < v[step+1]%3) {
		if(lr == 1) pq.push((node){step+1, cst+1 ,1});
		else pq.push((node){step+1, cst ,1});
	    } else if(v[step]%3 > v[step+1]%3) {
		if(lr == 0) pq.push((node){step+1, cst+1 ,0});
		else pq.push((node){step+1, cst ,0});
	    } else {
		if(lr == 0) {
		    pq.push((node){step+1, cst+1 ,0});
		    pq.push((node){step+1, cst ,1});
		} else {
		    pq.push((node){step+1, cst ,0});
		    pq.push((node){step+1, cst+1 ,1});
		}
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
