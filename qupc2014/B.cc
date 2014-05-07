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

int N, len;
int seq[8];
const string a[10] = {"nil", "un", "bi", "tri", "quad", "pent", "hex", "sept", "oct", "enn"};
const string b[10] = {"nilium", "unium", "bium", "trium", "quadium", "pentium", "hexium", "septium", "octium", "ennium"};

int main()
{
    cin >> N;
    for(len = 0; N > 0; len++, N/=10)
        seq[len] = N % 10;
    reverse(seq, seq+len);
    string ans = "";
    rep(i,len-1){
        if(seq[i] == 9 and seq[i+1] == 0)
            ans += "en";
        else ans += a[seq[i]];
    }
    ans += b[seq[len-1]];
    ans[0] += 'A' - 'a';
    cout << ans << endl;
    return 0;
}
