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
    int n;
    while(cin >> n, n){
        bool ontv[32][25] = {false};
        map<string,int> id;
        vector<string> v;
        rep(i,n){
            string name;
            int m;
            cin >> name >> m;
            id[name] = i;
            v.pb(name);
            rep(j,m){
                int d;
                cin >> d;
                ontv[d][i] = true;
            }
        }

        int point[25] = {0};
        rep(i,30){
            int cnt = 0;
            rep(j,n){
                if(ontv[i][j]) cnt++;
            }
            rep(j,n){
                if(ontv[i][j]) point[j] += (n-cnt+1); 
            }
        }
        string s;
        int ans = INF;
        rep(i,n){
            if(ans > point[i]){
                ans = point[i];
                s = v[i];
            }else if(ans == point[i] && v[i] < s){
                ans = point[i];
                s = v[i];
            }
        }
        cout << ans << ' ' << s << endl;
    }
    return 0;
}
