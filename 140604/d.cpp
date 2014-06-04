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

struct node {
    int step;
    string state;

    node() {
        step = 0;
        state = "123456789";
    }
    
    void rotate(int a, int b, int c, int d) {
        char tmp_num = state[b];
        state[b] = state[a];
        state[a] = state[d];
        state[d] = state[c];
        state[c] = tmp_num;
    }
    
    void rotate(int pos, int rl) {
        if(pos == 0) {
            if(rl == 0) rotate(0, 1, 4, 3);
            else rotate(3, 4, 1, 0);
        } else if(pos == 1) {
            if(rl == 0) rotate(1, 2, 5, 4);
            else rotate(4, 5, 2, 1);
        } else if(pos == 2) {
            if(rl == 0) rotate(3, 4, 7, 6);
            else rotate(6, 7, 4, 3);
        } else {
            if(rl == 0) rotate(4, 5, 8, 7);
            else rotate(7, 8, 5, 4);
        }
    }
};

int n;

int solve(int d) {
    queue<node> q;
    q.push(node());
    string goal;
    rep(i, 9) {
        goal += (char)(d%10 + '0');
        d /= 10;
    }
    reverse(all(goal));
    set<string> st;
    while(q.size()) {
        node now = q.front(); q.pop();
        if(st.find(now.state) != st.end()) continue;
        st.insert(now.state);
        
        if(now.step > n) {
            return -1;
        }
        //cout << now.step << " " << now.state << " " << goal << endl;

        if(now.state == goal) return now.step;
        
        rep(i, 4) rep(j, 2) {
            node nxt = now;
            nxt.step++;
            nxt.rotate(i, j);
            q.push(nxt);
        }
    }
}

int main()
{
    char c;
    int d;
    int cnt = 0;
    while(cin >> c >> d, d != 0) {
        cnt++;
        n = c-'0';
        cout << cnt << ". " << solve(d) << endl;
    }
    return 0;
}
