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

const int score[] = {10, 8, 6, 5, 4, 3, 2, 1};

int n;
map<pair<string, string>, int> ds;
map<string, int> ts;

int main()
{
    int k = 0;

    string tmp;
    while (cin >> n and n) {
        ds.clear();
        ts.clear();

        rep(_, n) {
            getline(cin, tmp);
            getline(cin, tmp);
            getline(cin, tmp);
            rep(i, 8) {
                int pos; string a, b, t;
                cin >> pos >> a >> b;
                scanf(" ");
                getline(cin, t);

                t[t.length() - 1] = ' ';

                ds[mp(b, a)] -= score[pos - 1];
                ts[t] -= score[pos - 1];
            }
            cin >> tmp;
        }


        cout << "Season " << ++k << ":" << endl;
        cout << "Drivers Standing:" << endl;
        {
            vector<pair<int, pair<string, string> > > v;
            repit(it, ds) v.pb(mp(it->second, it->first));
            sort(all(v));
            repit(it, v) {
                string name;
                name.insert(name.end(), all(it->second.second));
                name.pb(' ');
                name.insert(name.end(), all(it->second.first));
                name.resize(26, ' ');

                cout << name << -it->first << endl;
            }
        }
        cout << endl;
        cout << "Teams Standing:" << endl;
        {
            vector<pair<int, string> > v;
            repit(it, ts) v.pb(mp(it->second, it->first));
            sort(all(v));
            repit(it, v) {
                string name;
                name.insert(name.end(), all(it->second));
                name.resize(26, ' ');

                cout << name << -it->first << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
