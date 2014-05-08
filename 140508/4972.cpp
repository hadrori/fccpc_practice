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
typedef pair<int,int> pii;
typedef complex<double> P;

int N, C;
pii pos[16];
int seq[16];
int cst[16][16];
pii edges[16];

double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c)>EPS)   return +1;       // +1 : 反時計回り
    if (cross(b, c)<-EPS)   return -1;       // -1 : 時計回り
    if (dot(b, c)<-EPS)     return +2;       // +2 : 線上(c--a--b)
    if (norm(c)>norm(b)+EPS) return -2;       // -2 : 線上(a--b--c)
    return 0;
}

bool intersect(pii p, pii q){
    if(p.first == q.first or p.first == q.second or p.second == q.first or p.second == q.second)
        return 0;
    P a = P(pos[p.first].first,pos[p.first].second);
    P b = P(pos[p.second].first,pos[p.second].second);
    P c = P(pos[q.first].first,pos[q.first].second);
    P d = P(pos[q.second].first,pos[q.second].second);
    return ccw(a,b,c)*ccw(a,b,d) < 0 and ccw(c,d,a)*ccw(c,d,b) < 0;
}

int main()
{
    int t = 1;
    while(cin >> N >> C, N){
        rep(i,N){
            int x, y; cin >> x >> y;
            pos[i] = pii(x, y);
        }
        rep(i,N)rep(j,N) cin >> cst[i][j];
        rep(i,N) seq[i] = i;
        int ans = INF;
        do{
            int sum = 0;
            rep(i,N){
                int a = seq[i], b = seq[(i+1)%N];
                sum += cst[a][b];
                edges[i] = pii(a,b);
            }
            rep(i,N) repi(j,i+1,N){
                if(intersect(edges[i],edges[j]))
                    sum += C;
            }
            ans = min(ans, sum);
            if(ans == 11){
                rep(i,N) cerr << seq[i] << " ";
                cerr << endl;
            }
        } while(next_permutation(seq,seq+N));
        cout << t << ". " << ans << endl;
        t++;
    }
    return 0;
}
