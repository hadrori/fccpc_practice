#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(int)(b);++i)
#define all(c) begin(c),end(c)
#ifndef DEBUG
const string name = "funny"; // input filename here!!
ifstream fin(name + ".in");
ofstream fout(name + ".out");
#define cin fin
#define cout fout
#endif
#define pb push_back
#define mp make_pair
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > hist;
    set<string> used_words;
    rep(i, m) {
        string s;
        cin >> s;
        vector<int> h(26);
        rep(j, s.size()) h[s[j] - 'A']++;
        hist.pb(h);
        used_words.insert(s);
    }

    priority_queue<pair<int, vector<int> > > cand;
    rep(i, 26) {
        vector<int> tc(26);
        tc[i] = 1;
        int cnt = 0;
        for(const vector<int> &h : hist) {
            bool ok = true;
            rep(i, 26) if(h[i] < tc[i]) ok = false;
            if(ok) cnt++;
        }
        cand.push(mp(cnt, tc));
    }
    
    set<vector<int> > used;
    
    int ii = 0;
    while(ii < n) {
        vector<int> ans = cand.top().second;        
        cand.pop();
        string v;
        rep(i, 26) {
            rep(j, ans[i]) v.pb('A'+i);
        }
        sort(all(v));
 
        do {
            if(ii == n) break;
            if(used_words.find(v) != used_words.end()) continue;
            cout << v << endl;
            used_words.insert(v);
            ii++;
        } while(next_permutation(all(v)));
        
        rep(i, 26) {
            vector<int> tc = ans;
            tc[i]++;
            if(used.find(tc) != used.end()) continue;
            used.insert(tc);
            
            int cnt = 0;
            for(const vector<int> &h : hist) {
                bool ok = true;
                rep(i, 26) if(h[i] < tc[i]) ok = false;
                if(ok) cnt++;
            }
            
            cand.push(mp(cnt, tc));
        }
    }
    
}
