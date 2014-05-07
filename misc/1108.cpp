#include <cstring>
#include <iostream>
#include <vector>

#define rep(i,a) for(int i = 0; i < a; i++)

using namespace std;

const int N = 1000010;

int ns, nl;
int memo[1<<20];
int ans;
vector<int> ansv;
vector<int> vv;

struct edge{
    int id;
    int to;
    int cst;
};

vector<vector<edge> > G;

void rec(int station, int cst, int visited){
    if(memo[visited] >= cst) {
        //ansv.pop_back();
        return; 
    }
    ansv.push_back(station);
    //cout << station << " " << cst << " " << visited << endl;
    memo[visited] = cst;
    if(ans < cst){
        ans = cst;
        vv = ansv;
    }
    
    rep(i, G[station].size()){
        //cout << "b\n";
        if(!(visited & (1<<G[station][i].id))){
            visited |= (1<<G[station][i].id);
            rec(G[station][i].to, cst + G[station][i].cst, visited);
            visited &= ((1<<20)-1) - (1<<G[station][i].id);
        }
    }
    ansv.pop_back();
}

void solve() {
    ans = 0;
    rep(i, ns){
        memset(memo, -1, sizeof(memo));
        rec(i+1, 0, 0);
    }
    cout << ans << endl;
    rep(i, vv.size()) cout << vv[i] << (i < vv.size() - 1 ? " " : "\n");
}

int main(){
    while (cin >> ns >> nl, ns) {
        G.clear();
        G.resize(ns+1);
        int id = 0;
        rep(i, nl){
            int s1, s2, d;
            cin >> s1 >> s2 >> d;
            //cout << id << endl;
            G[s1].push_back((edge){id, s2, d});
            G[s2].push_back((edge){id, s1, d});
            id++;
        }
        //cout << "a" << endl;
        solve();
    }
    return 0;
}
