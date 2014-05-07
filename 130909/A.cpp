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

int main()
{
    int N, Q;
    while(cin >> N >> Q, N || Q){
	string str;
	int n, m;
	vi years;
	map<int,pair<int,string> > name;
	rep(i,N){
	    cin >> str >> n >> m;
	    years.pb(m);
	    name[m] = mp(n,str);
	}
	sort(all(years));
	rep(i,Q){
	    int y;
	    cin >> y;
	    if(name.find(y) != name.end()) cout << name[y].second << ' ' << name[y].first << endl;
	    else{
		vi::iterator itr = lower_bound(all(years),y);
		if(itr == years.end()) cout << "Unknown\n";
		else{
		    if(*itr < y || *itr - name[*itr].first >= y){
			cout << "Unknown\n";
		    }
		    else cout << name[*itr].second << ' ' << name[*itr].first - *itr + y << endl;
		}
	    }
	}
    }
    return 0;
}
