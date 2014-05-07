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

int A, B, C, D;
int E[16][16];
int cnt[16];
int passed;
vector<pii> seq;

int main()
{
    cin >> A >> B >> C >> D;
    rep(i,C){
        rep(j,A){
            cin >> E[i][j];
            seq.pb(pii(E[i][j],i));
        }
    }
    sort(rall(seq));
    int ans = 0;
    rep(i,seq.size()){
        if(cnt[seq[i].second] == B) continue;
        if(cnt[seq[i].second] == B-1) passed++;
        cnt[seq[i].second]++;
        if(passed == D){
            ans = seq[i].first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
