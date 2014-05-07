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

#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);--i)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();++i)

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

bool num[128][256];
int m, n;
map<string,pair<int,int> > bound;
string op = "+-*/";

int main()
{
    memset(num,0,sizeof(num));
    cin >> m;
    rep(i,m){
	string name;
	int lb, ub;
	cin >> name >> lb >> ub;
	bound[name] = mp(lb,ub);
    }    
    cin >> n;
    stack<int> st;
    rep(i,n){
	string e;
	cin >> e;
	if(op.find(e) == string::npos){
	    if(bound.find(e) != bound.end())
		for(int j = bound[e].first; j <= bound[e].second; j++)
		    num[i][j] = true;
	    else
		num[i][atoi(e.c_str()) & 255] = true;
	}else{
	    int b = st.top(); st.pop();
	    int a = st.top(); st.pop();
	    if(e == "+"){
		rep(j,256)rep(k,256){
		    num[i][(j + k) % 256] |= num[a][j] & num[b][k];
		}
	    }
	    if(e == "-"){
		rep(j,256)rep(k,256){
		    num[i][(j - k + 256) % 256] |= num[a][j] & num[b][k];
		}
	    }
	    if(e == "*"){
		rep(j,256)rep(k,256){
		    num[i][(j * k) % 256] |= num[a][j] & num[b][k];
		}
	    }
	    if(e == "/"){
		if(num[b][0]) {
		    cout << "error\n";
		    return 0;
		}
		rep(j,256)repi(k,1,256){
		    num[i][(j / k) % 256] |= num[a][j] & num[b][k];
		}
	    }
	}
	st.push(i);
    }
    cout << "correct\n";
    return 0;
}
