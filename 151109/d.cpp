#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define long int64_t

int n, m;
vector<long> atk, def, mine;
bool input() {
    cin >> n >> m;
    rep(i, n) {
        string s;
        long a;
        cin >> s >> a;
        if (s == "ATK") atk.pb(a);
        else def.pb(a);
    }
    rep(i, m) {
        long a;
        cin >> a;
        mine.pb(a);
    }
    sort(all(atk));
    sort(all(def));
    sort(all(mine));
}

long defeatAll() {
    int di = 0;
    bool dok = false;
    vector<bool> used(mine.size());
    if (def.size()) {
        rep(i, mine.size()) {
            if (mine[i] > def[di]) {
                used[i] = true;
                di++;
                if (di == def.size()) {
                    dok = true;
                    break;
                }                
            }
        }
    } else {
        dok = true;
    }

    if (dok) {
        int ai = 0;
        bool aok = false;
        long ret = 0;
        if (atk.size()) {
            rep(i, mine.size()) {
                if (!used[i] and mine[i] >= atk[ai]) {
                    ai++;
                    if (ai == atk.size()) {
                        aok = true;
                        break;
                    }                
                }
            }
        } else {
            aok = true;
        }
        if (aok) {
            rep(i, mine.size()) if (!used[i]) ret += mine[i];
            rep(i, atk.size()) ret -= atk[i];
        }
        return ret;
    } else {
        return 0;
    }
}

long defeatTo(long l) {
    vector<long> mv;
    repi(i, (int)mine.size() - l, mine.size())
        mv.pb(mine[i]);
    
    rep(i, mv.size()) 
        if (atk[i] > mv[i]) return 0;

    long ret = 0;
    rep(i, mv.size()) ret += mv[i];
    rep(i, mv.size()) ret -= atk[i];
    return ret;
}

void solve() {
    long ans = defeatAll();
    repi(l, 1, min(atk.size(), mine.size())+1) ans = max(ans, defeatTo(l));
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    input();
    solve();
    return 0;
}
