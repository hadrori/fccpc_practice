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

bool solve(string s) {
    stack<char> stk;
    rep(i, s.size()) {
        if(s[i] == '[') stk.push('[');
        if(s[i] == '(') stk.push('(');
        if(s[i] == ']') {
            if(stk.empty() or stk.top() != '[') return false;
            stk.pop();
        }
        if(s[i] == ')') {
            if(stk.empty() or stk.top() != '(') return false;
            stk.pop();
        }
    }
    return stk.empty();
}

int main()
{
    string s;
    while(getline(cin, s), s != ".") {
        if(solve(s)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
