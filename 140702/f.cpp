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
    PMA* next[256];    //0 is failure link
    vi matched;
    PMA(){memset(next, 0, sizeof(next));}
    ~PMA(){rep(i,256) if(next[i]) delete next[i];}
};
vi set_union(const vi &a,const vi &b){
    vi res;
    set_union(all(a), all(b), back_inserter(res));
    return res;
}
// patternからパターンマッチングオートマトンの生成
PMA *buildPMA(vector<string> pattern){
    PMA *root = new PMA, *now;
    root->next[0] = root;
    rep(i, pattern.size()){
        now = root;
        rep(j, pattern[i].size()){
            if(now->next[(int)pattern[i][j]] == 0)
                now->next[(int)pattern[i][j]] = new PMA;
            now = now->next[(int)pattern[i][j]];
        }
        now->matched.push_back(i);
    }
    queue<PMA*> que;
    repi(i,1,256){
        if(!root->next[i]) root->next[i] = root;
        else {
            root->next[i]->next[0] = root;
            que.push(root->next[i]);
        }
    }
    while(!que.empty()){
        now = que.front(); que.pop();
        repi(i,1,256){
            if(now->next[i]){
                PMA *next = now->next[0];
                while(!next->next[i]) next = next->next[0];
                now->next[i]->next[0] = next->next[i];
                now->next[i]->matched = set_union(now->next[i]->matched, next->next[i]->matched);
                que.push(now->next[i]);
            }
        }
    }
    return root;
}

vector<string> ps;
bool match(PMA* pma, const string s, vi &res){
    vector<int> done(s.size());
    rep(i,s.size()){
        int c = s[i];
        while(!pma->next[c])
            pma = pma->next[0];
        pma = pma->next[c];
        rep(j,pma->matched.size()) {
            repi(k, i-ps[pma->matched[j]].size()+1, i+1) done[k] += 1;
            res[pma->matched[j]] = 1;
        }
    }
    rep(i, s.size()) if(!done[i]) return false;
//    cout << "done: " << s << endl;
//    rep(i, s.size()) cout << done[i] << " ";
//    cout << endl;
    return true;
}

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.";
void gen(string s, set<string> &st) {
    int m = s.size();
    rep(ai, alpha.size()) {
        char c = alpha[ai];
        // insert
        rep(i, m) {
            string ts;
            rep(j, m) {
                if(j == i) ts += (char)c;
                ts += s[j];
            }
            st.insert(ts);
        }
        st.insert(s+(char)c);
    
        // delete
        rep(i, m) {
            string ts;
            rep(j, m) if(j != i) ts += (char)s[j];
            st.insert(ts);
        }

        // change
        rep(i, m) {
            string ts = s;
            ts[i] = (char)c;
            st.insert(ts);
        }
    }
}

int main()
{
    int n, d;
    string s;
    while(cin >> d >> n, n||d) {
        // input
        cin >> s;
        ps.clear();
        ps.resize(n);
        rep(i, n) {
            cin >> ps[i];
            //cout << "pattern: " << ps[i] << endl;
        }

        PMA *pma = buildPMA(ps);

        set<string> st;
        gen(s, st);
        //repit(itr, st) cout << *itr << endl;

        rep(i, d-1) {
            set<string> bst = st;
            repit(itr, bst) {
                gen(*itr, st);
            }
        }

        vector<string> ans;
        int cnt = 0;
        repit(itr, st) {
            vector<int> res(n);
            if(!match(pma, *itr, res)) continue;
            bool ok = true;
            if(ok) {
                cnt++;
                /*
                cout << *itr << endl;
                rep(i, n) cout << res[i] << " ";
                cout << endl;
                */
                if(ans.size() < 6) ans.pb(*itr);
            }
            
        }
        sort(all(ans));
        cout << cnt << endl;
        if(ans.size() <= 5) rep(i, ans.size()) cout << ans[i] << endl;
        
    }
    return 0;
}
