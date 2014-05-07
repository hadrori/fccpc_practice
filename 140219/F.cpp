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

struct PMA{
    PMA* next[256];
    vector<int> matched;
    PMA(){memset(next, 0, sizeof(next));}
    ~PMA(){for(int i = 0; i < 256; i++) if(next[i]) delete next[i];}
};

vector<int> set_union(const vector<int> &a, const vector<int> &b){
    vector<int> res;
    set_union(all(a), all(b), back_inserter(res));
    return res;
}

PMA *buildPMA(vector<string> pattern){
    PMA *root = new PMA, *now;
    root->next[0] = root;
    for(int i = 0; i < pattern.size(); i++){
        now = root;
        for(int j = 0; j < pattern[i].size(); j++){
            if(now->next[(int)pattern[i][j]] == 0)
                now->next[(int)pattern[i][j]] = new PMA;
            now = now->next[(int)pattern[i][j]];
        }
        now->matched.push_back(i);
    }
    queue<PMA*> que;
    for(int i = 1; i < 256; i++)
        if(!root->next[i]) root->next[i] = root;
        else{
            root->next[i]->next[0] = root;
            que.push(root->next[i]);
        }
    while(!que.empty()){
        now = que.front(); que.pop();
        for(int i = 1; i < 256; i++)
            if(now->next[i]){
                PMA *next = now->next[0];
                while(!next->next[i]) next = next->next[0];
                now->next[i]->next[0] = next->next[i];
                now->next[i]->matched = set_union(now->next[i]->matched, next->next[i]->matched);
                que.push(now ->next[i]);
            }
    }
    return root;
}

void match(PMA* &pma, const string s, vector<int> &res){
    for(int i = 0; i < s.size(); i++){
        int c = s[i];
        while(!pma->next[c])
            pma = pma->next[0];
        pma = pma->next[c];
        for(int j = 0; j < pma->matched.size(); j++)
            res[pma->matched[j]] = true;
    }
}

int n, T;
vector<string> pat;
string prg;

void init(){
    pat.clear();
    prg = "";
}

inline bool isNum(char c){ return c >= '0' && c <= '9';}

void decode(string str){
    int cur = 0;
    while(cur < str.size()){
        if(str[cur] == '['){
            string st = "";
            cur++;
            while(isNum(str[cur])) st.push_back(str[cur++]);
            prg += string(atoi(st.c_str()),str[cur]);
            cur++;
        }
        else prg.push_back(str[cur]);
        cur++;
    }
}

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string inp; cin >> inp;
        pat.push_back(inp);
        reverse(all(inp));
        pat.push_back(inp);
    }
    string tmp;
    cin >> tmp;
    decode(tmp);
}

void solve(){
    PMA* s = buildPMA(pat);
    vector<int> exist(2*n);
    match(s, prg, exist);
    int ans = 0;
    for(int i = 0; i < 2*n; i+=2)
        ans += exist[i] | exist[i+1];
    cout << ans << endl;
}

int main()
{
    cin >> T;
    while(T--){
        init();
        input();
        solve();
    }
    return 0;
}
