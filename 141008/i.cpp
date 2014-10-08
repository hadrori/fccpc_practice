#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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

using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;
int n;
string calc(vector<char> &v, int pos) {
    vector<char> stk;
    string s1, s2;
    rep(i, pos+1) s1 += v[i];
    rep(i, pos+1) {
        if(v[i] == '(') stk.pb(')');
        else if(v[i] == '[') stk.pb(']');
        else if(v[i] == ')') stk.pop_back();
        else if(v[i] == ']') stk.pop_back();
    }
    reverse(all(stk));
    rep(i, stk.size()) s2 += stk[i];

    string mid;
    int m = n-(stk.size() + pos+1);
    rep(i, m/2) mid += '(';
    rep(i, m/2) mid += ')';

    string ret = s1 + mid + s2;
    rep(i, ret.size()) {
        if(ret[i] == '(') ret[i] = 'a';
        if(ret[i] == ')') ret[i] = 'e';
        if(ret[i] == '[') ret[i] = 'i';
        if(ret[i] == ']') ret[i] = 'o';
    }

    return ret;
}

void solve() {
    string s;
    cin >> s;
    n = s.size();
    vector<char> v;
    rep(i, n) {
        if(s[i] == 'a') v.pb('(');
        else if(s[i] == 'e') v.pb(')');
        else if(s[i] == 'i') v.pb('[');
        else if(s[i] == 'o') v.pb(']');
    }

    vector<char> lst(n);
    vector<int> num(n);
    stack<char> stk;
    bool ok = true;
    rep(i, n) {
        if(stk.size()) lst[i] = stk.top();
        num[i] = stk.size();
        if(v[i] == '(') stk.push('(');
        else if(v[i] == '[') stk.push('[');
        else if(v[i] == ')') {
            if(stk.size() and stk.top() == '(') stk.pop();
            else { ok = false; break; }
        } else if(v[i] == ']') {
            if(stk.size() and stk.top() == '[') stk.pop();
            else { ok = false; break;}
        }
    }
    if(stk.size() > 0) ok = false;
    if(!ok) {
        cout << "INVALID" << endl;
        return;
    }

    string ans;
    bool ulti = true;
    repd(i, n-1, 0) {
        if(v[i] == '(') {
            if(lst[i] == '(') {
                v[i] = ')';
                ans = calc(v, i);
                ulti = false;
                break;
            }
            v[i] = '[';
            ans = calc(v, i);
            ulti = false;
            break;
        } else if(v[i] == ')') {
            if(n-i-1 >= num[i]+1) {
                v[i] = '[';
                ans = calc(v, i);
                ulti = false;
                break;
            }
        } else if(v[i] == '[') {
            if(lst[i] == '[') {
                v[i] = ']';
                ans = calc(v, i);
                ulti = false;
                break;
            }
        }
    }
    if(ulti) {
        cout << "ULTIMATE" << endl;
        return;
    }
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(i, T) solve();
    return 0;
}
