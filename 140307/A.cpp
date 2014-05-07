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

string solve(){
    int N, R;
    string str;
    cin >> N >> R >> str;
    string ret = "";
    for(int i = 0; i< str.size(); i++)
        for(int j = 0; j < R; j++)
            ret.push_back(str[i]);
    return ret;
}

int main()
{
    int P;
    cin >> P;
    for(int i = 1; i <= P; i++){
        cout << i << " " << solve() << endl;;
        
    }
    return 0;
}
