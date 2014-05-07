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

int n, m, k, l;
map<string, int> table;
vector<pair<int, string> > fav;
vector<pair<int, string> > cv;
bool C(int a){
    int tl = l;
    int bound = k-a;
    if(bound >= cv.size()) return true;
    rep(i, a){
        int tp = cv[bound].first;
        string name = fav[i].second;
        if(cv[bound] > fav[i]) continue;
        tl -= fav[i].first - tp;
        int rank = 214214;
        rank = lower_bound(all(cv), mp(tp, name)) - cv.begin();
        
        if(rank > bound) tl--;   
    }
    return (tl >= 0);
}
int main() {
    while(cin >> n >> m >> k >> l, n){
        table.clear();
        rep(i, n){
            char c[80];
            string name;
            int x;
            scanf("%s %d", c, &x);
            name = c;
            table[name] = x;
        }
        
        fav.clear();
        rep(i, m) {
            char c[80];
            string name;
            scanf("%s", c);
            name = c;
            fav.pb(mp(-table[name], name));
        }
        sort(all(fav));
        cv.clear();
        repit(itr, table) {
            pair<int, string> tpr = mp(-itr->second, itr->first);
            if(!binary_search(all(fav), tpr)) cv.pb(tpr);
        }
        sort(all(cv));

        int lower = 0;
        int upper = min(k, m) + 1;
        int mid;
        while(lower + 1 < upper){
            mid = (lower + upper)/2;
            if(C(mid)) lower = mid;
            else upper = mid;
        }
        cout << lower << endl;
    }
    
    return 0;
}
