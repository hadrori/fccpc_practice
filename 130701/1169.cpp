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
struct edge{
    int from, to;
    string s;
};
int n, a, s, g;
int main() {
    while(cin >> n >> a >> s >> g, n){
        vector<edge> E;
        rep(i, a){
            int from, to;
            string str;
            cin >> from >> to >> str;
            E.pb((edge){from, to, str});
        }
        vector<string> dp(n);
        vector<bool> done(n);
        bool end = false;
        done[g] = true;
        while(!end){
            end = true;
            rep(i, a){
                int from = E[i].from;
                int to = E[i].to;
                string str = E[i].s;
                if((dp[from] > str + dp[to] || !done[from]) && done[to] && dp[from].size() < 260){
                    end = false;
                    done[from] = true;
                    dp[from] = str + dp[to];
                }
            }
        }
        if(dp[s].size() < 250 && dp[s].size() > 0) cout << dp[s] << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
