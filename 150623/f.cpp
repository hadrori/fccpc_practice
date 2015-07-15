#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

int n, m, q;

struct vertex {
    bool is_online;
    bool is_large;
    // <vertex, edge_id>
    vector<pair<int, int> > l_list;
    vector<pair<int, int> > s_list;
    int online_num;
    
    vertex() {
        is_online = false;
        online_num = 0;
    }
};

vector<vertex> vs;
struct query {
    char type;
    int u, v;
    query(char type, int u, int v) : type(type), u(u), v(v) {}
};
vector<query> qs;

bool edge_visible[500000];
map<pair<int, int>, int> edge_table;

int T;
void input() {
    scanf("%d %d %d", &n, &m, &q);
    vs.assign(n, vertex());
    memset(edge_visible, 0, sizeof(edge_visible));

    // online
    int o;
    scanf("%d", &o);
    rep(i, o) {
        int u;
        scanf("%d", &u);
        u--;
        vs[u].is_online = true;
    }
    
    // initial edge
    int id = 0;
    vector<vector<pair<int, int> > > E(n);
    rep(i, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        E[u].pb(mp(v, id));
        E[v].pb(mp(u, id));
        edge_table[mp(u, v)] = id;
        edge_table[mp(v, u)] = id;
        edge_visible[id] = true;
        id++;
        qs.pb(query('A', u, v));
    }
    // query
    rep(i, q) {
        char c;
        int u, v;
        scanf(" %c ", &c);
        if(string("OFC").find(c) != string::npos) {
            scanf("%d", &u);
            u--;
        } else {
            scanf("%d %d", &u, &v);
            u--; v--;
        }
        qs.push_back(query(c, u, v));
        if(c == 'A') {
            if(edge_table.find(mp(u, v)) != edge_table.end()) continue;
            E[u].pb(mp(v, id));
            E[v].pb(mp(u, id));
            edge_table[mp(u, v)] = id;
            edge_table[mp(v, u)] = id;
            id++;
        }
    }    
        
    T = sqrt(2*(id)) + 1;
    //T = 2;
    rep(i, n) {
        vs[i].is_large = ((int)E[i].size() > T);
    }
    rep(i, n) {
        for(pair<int, int> pr: E[i]) {
            int to = pr.first;
            if((int)E[to].size() > T) {
                vs[i].l_list.pb(mp(to, pr.second));
            } else {
                vs[i].s_list.pb(mp(to, pr.second));
            }
        }
    }
    
}

int count_online(int u) {
    int ret = vs[u].online_num;
    for(auto &p : vs[u].l_list) {
        ret += edge_visible[p.second] & vs[p.first].is_online;
    }
    return ret;    
}

void solve() {
    for(query nq : qs) {
        if(nq.type == 'O') {
            vertex& now = vs[nq.u];
            now.is_online = true;
            if(!now.is_large) {
                for(pair<int, int> pr : now.l_list) {
                    if(edge_visible[pr.second]) {
                        int to = pr.first;
                        vs[to].online_num++;
                    }
                }
                for(pair<int, int> pr : now.s_list) {
                    if(edge_visible[pr.second]) {
                        int to = pr.first;
                        vs[to].online_num++;
                    }
                }
            }
        } else if(nq.type == 'F') {
            vertex& now = vs[nq.u];
            now.is_online = false;
            if(!now.is_large) {
                for(pair<int, int> pr : now.l_list) {
                    if(edge_visible[pr.second]) {
                        int to = pr.first;
                        vs[to].online_num--;
                    }
                }
                for(pair<int, int> pr : now.s_list) {
                    if(edge_visible[pr.second]) {
                        int to = pr.first;
                        vs[to].online_num--;
                    }
                }
            }
        } else if(nq.type == 'A') {
            int edge_id = edge_table[mp(nq.u, nq.v)];
            edge_visible[edge_id] = true;
            int now = nq.u, to = nq.v;
            rep(_, 2) {
                if(!vs[now].is_large and vs[now].is_online) {
                    vs[to].online_num++;
                }
                swap(now, to);
            }            
        } else if(nq.type == 'D') {
            int edge_id = edge_table[mp(nq.u, nq.v)];
            edge_visible[edge_id] = false;
            int now = nq.u, to = nq.v;
            rep(_, 2) {
                if(!vs[now].is_large and vs[now].is_online) {
                    vs[to].online_num--;
                }
                swap(now, to);
            }
        } else if(nq.type == 'C') {
            printf("%d\n", count_online(nq.u));
        }
        
        //rep(i, n) cout << count_online(i) << ", ";
        //cout << endl;
    }
}

int main()
{
    input();
    solve();
    return 0;
}
