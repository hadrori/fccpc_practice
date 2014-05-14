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
    node *par, *l, *r;
    int val, id, isleaf;
    node(node *par, int val, int id):
        par(par),val(val),id(id){isleaf = 1;}
    node(int id):id(id){isleaf = 0;}
};

string s;
node *root;
int md, cur;
vector<node*> cand;

int num(){
    int ret = 0;
    while(cur < s.size() and isdigit(s[cur]))
        ret = ret * 10 + s[cur++] - '0';
    return ret;
}

node* expr(int &id, node *par, int d){
    if(isdigit(s[cur])){
        if(md < d) cand.clear();
        md = max(md, d);
        node *v = new node(par,num(),id++);
        if(d == md) cand.pb(v);
        return v;
    }
    node *v = new node(id++);
    v->par = par;
    cur++;
    v->l = expr(id, v, d+1);
    cur++;
    v->r = expr(id, v, d+1);
    cur++;
    return v;
}

bool done[];

int rec(node *v, int k){
    done[v->id] = 1;
    if(v->isleaf) return (v->val) != k;
    int ret = 0;
    if(!done[v->l->id]) ret += rec(v->l, k/2);
    if(!done[v->r->id]) ret += rec(v->r, k/2);
    if(v == root) return ret;
    if(!done[v->par->id]) return ret + rec(v->par, k*2);
    return ret;
}

        
int main()
{
    int T; cin >> T;
    while(T--){
        cin >> s;
        cur = md = 0;
        int id = 0;
        cand.clear();
        root = expr(id, 0, 0);
        int ans = INF;
        rep(i,cand.size()){
            if(cand[i] == root){
                ans = 0;
                break;
            }
            memset(done, 0, sizeof(done));
            ans = min(ans, rec(cand[i]->par, 2*cand[i]->val));
        }
        cout << ans << endl;
    }
    return 0;
}
