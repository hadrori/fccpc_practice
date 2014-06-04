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

const int score_table[] = {10, 8, 6, 5, 4, 3, 2, 1};

int n;
struct person {
    string a, b;
    int score;
    int place_count[8];
    person(){}
    person(string a, string b): a(a), b(b){
        score = 0;
        memset(place_count, 0, sizeof(place_count));
    }

    void calc(int pos) {
        place_count[pos-1]++;
        score += score_table[pos-1];
    }

    bool operator<(const person &o) const {
        if(score != o.score) return score > o.score;
        rep(i, 8) if(place_count[i] != o.place_count[i]) return place_count[i] > o.place_count[i];
        if(b != o.b) return b < o.b;
        return a < o.a;
    }
};

int main()
{
    int k = 0;

    string tmp;
    while (cin >> n and n) {
        map<pair<string, string>, person> ds;
        map<string, int> ts;

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
                if(ds.find(mp(b, a)) != ds.end()) {
                    ds[mp(b, a)].calc(pos);
                } else {
                    ds[mp(b, a)] = person(a, b);
                    ds[mp(b, a)].calc(pos);
                }
                ts[t] -= score_table[pos - 1];
            }
            cin >> tmp;
        }


        cout << "Season " << ++k << ":" << endl;
        cout << "Drivers Standing:" << endl;
        {
            vector<person> v;
            repit(it, ds) v.pb(it->second);
            sort(all(v));
            repit(it, v) {
                string name;
                name.insert(name.end(), all(it->a));
                name.pb(' ');
                name.insert(name.end(), all(it->b));
                name.resize(26, ' ');

                cout << name << it->score << endl;
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
