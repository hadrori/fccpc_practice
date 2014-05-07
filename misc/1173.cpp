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

int main() {
    string s;
    while(getline(cin, s), s != "."){
	stack<int> stk;
	string ans = "yes";
	rep(i, s.size()){
	    if(s[i] == '(') stk.push(0);
	    else if(s[i] == ')'){
		if(stk.empty() || stk.top() != 0) ans = "no";
		else stk.pop();
	    }
	    if(s[i] == '[') stk.push(1);
	    else if(s[i] == ']'){
		if(stk.empty() || stk.top() != 1) ans = "no";
		else stk.pop();
	    }
	}
	if(!stk.empty()) ans = "no";
	cout << ans << endl;
    }
    return 0;
}
