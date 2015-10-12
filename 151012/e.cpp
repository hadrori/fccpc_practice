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
#define long int64_t

void gen() {
    int n = 1;
    int m = 1000000;
    rep(i, n) cout << (char)('a' + (rand()%26));
    cout << endl;
    cout << m << endl;
    rep(i, m) {
        int d = rand()%n + 1;
        int k = rand()%n + 1;
        cout << min(d, k) << " " << max(d, k) << endl;
    }
}

int main()
{
    
    // gen();
    // return 0;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int m;
    cin >> m;
    int n = s.size();
    rep(_, m) {
        int k, d;
        cin >> k >> d;

        vector<int> u;
        rep(rem, d) {
            for (int num = rem; num < k; num += d) {
                u.push_back(num);
            }
        }
        /*
        cout << "u: " << endl;
        rep(i, u.size()) cout << u[i] << " ";
        cout << endl;
        */
        
        if ((int) u.size() != k) {
            cerr << "error" << endl;
            return 1;
        }
        
        vector<int> dif(k);
        rep(i, u.size()) {
            dif[u[i]] = i - u[i] - 1;
        }
        /*
        cerr << "dif" << endl;
        rep(i, dif.size()) cout << dif[i] << " ";
        cout << endl;
        */
        
        const int off = n + 2;
        vector<int> next(2*n +3);
        repi(i, -n, n+1) {
            int to;
            if (i >= 0 and i < k) {
                to = i + dif[i];
            } else if (i == -n) {
                to = n;
            } else {
                to = i-1;
            }
            next[i + off] = to;
        }

        vector<vector<int> > loops;
        vector<bool> done(next.size());
        rep(i, n) {
            if (!done[i + off]) {
                vector<int> loop;
                int now = i;
                while (!done[now + off]) {                    
                    done[now + off] = true;
                    loop.push_back(now);
                    
                    now = next[now + off];
                }
                loops.push_back(loop);
            }
        }

        vector<int> li(next.size());
        vector<int> lj(next.size());
        rep(i, loops.size()) {
            rep(j, loops[i].size()) {
                li[loops[i][j] + off] = i;
                lj[loops[i][j] + off] = j;
            }
        }

        /*
        cout << "loops" << endl;
        rep(i, loops.size()) {
            rep(j, loops[i].size()) cout << loops[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        */
        
        int num = n - k + 1;
        string t = s;
        rep(i, n) {
            vector<int> &loop = loops[li[i+off]];
            int nxt = loop[(lj[i+off]+num) % loop.size()] + num;
            t[nxt] = s[i];
        }
        printf("%s\n", t.c_str());
        s = t;
    }
    return 0;
}
