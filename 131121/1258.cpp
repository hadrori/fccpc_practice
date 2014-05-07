#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>

#define repi(i,a,b) for(int i = int(a); i < int(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = int(a); i >= int(b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);

using namespace std;

typedef long long ll;

int m, c, n;
signed main(){
    while(cin >> m >> c >> n, m||c||n) {
        vector<vector<int> > b(n);
        rep(i, n) {
            int k;
            cin >> k;
            b[i].resize(k);
            rep(j, k) cin >> b[i][j];
        }

        vector<int> book;
        queue<pair<int, int> > q;
        rep(i, n) q.push(mp(i, 0));
        while(!q.empty()) {
            int id = q.front().first;
            int index = q.front().second;
            q.pop();
            if(index == b[id].size()) continue;
            book.pb(b[id][index]);
            q.push(mp(id, index+1));
        }
        
        int ans = 0;
        vector<vector<int> > D(m);
        vector<int> place(101);
        rep(i, 101) place[i] = m;

        rep(i, book.size()) {
            int nbook = book[i];
            // take book
            ans += place[nbook] + 1;
            if(place[nbook] != m) {
                vector<int>::iterator itr = find(all(D[place[nbook]]), nbook);
                D[place[nbook]].erase(itr, itr+1);
            }
//            cout << "place of " << i << "th book : " << place[nbook] << endl;
            if(D[0].size() == c) {
                // 1
                int closest = -1;
                rep(j, m) if(D[j].size() < c) {
                    closest = j;
                    break;
                }
                if(closest >= 0) {
                    place[nbook] = closest;
                    ans += closest + 1;
                    D[closest].pb(nbook);
                } else {
                    place[nbook] = m;
                    ans += m+1;
                }
//                cout << i << ", 1 : " << ans << endl;
                
                // 2
                int oldest = D[0][0];
                D[0].erase(D[0].begin(), D[0].begin() + 1);
                ans++;
//                cout << i << ", 2 : " << ans << endl;

                // 3
                closest = -1;
                repi(j, 1, m) if(D[j].size() < c) {
                    closest = j;
                    break;
                }
                if(closest >= 0) {
                    place[oldest] = closest;
                    ans += closest + 1;
                    D[closest].pb(oldest);
                } else {
                    place[oldest] = m;
                    ans += m+1;
                }
//                cout << i << ", 3 : " << ans << endl;

                // 4
                ans += place[nbook] + 1;
                if(place[nbook] != m) {
                    vector<int>::iterator itr = find(all(D[place[nbook]]), nbook);
                    D[place[nbook]].erase(itr, itr+1);
                }
//                cout << i << ", 4 : " << ans << endl;

                // 5
                D[0].pb(nbook);
                place[nbook] = 0;
                ans++;
//                cout << i << ", 5 : " << ans << endl;
                
            } else {
                D[0].pb(nbook);
                place[nbook] = 0;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
