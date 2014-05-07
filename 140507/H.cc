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

typedef vector<int> arr;
typedef vector<arr> mat;

mat identity(int n) {
    mat A(n, arr(n));
    rep(i,n) A[i][i] = 1;
    return A;
}

arr mul(const mat &A, const arr &x) {
    arr y(A.size());
    rep(i,A.size()) rep(j,A[0].size())
        y[i] = A[i][j] * x[j];
    return y;
}

mat mul(const mat &A, const mat &B) {
    mat C(A.size(), arr(B[0].size()));
    rep(i,C.size()) rep(j,C[i].size()) rep(k,A[i].size())
        C[i][j] += A[i][k]*B[k][j];
    return C;
}

mat pow(const mat &A, int e) {
    return e == 0 ? identity(A.size())  :
           e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}
const int M = 26;
int T, N;
string s;
mat A, B;

void genA(){
    string t = s;
    int used[32] = {0};
    repi(i,1,N+1){
        int nxt = 0;
        rep(j,N) if(used[t[nxt]-'A'] > used[t[j]-'A'])
            nxt = j;
        used[t[nxt]-'A']++;
        rep(j,i){
            int p = (nxt+j)%N, q = (p+1)%N;
            if(q == 0) t = t.substr(N-1,1)+t.substr(0,N-1);
            else swap(t[p],t[q]);
        }
    }
    rep(i,N) A[s[i]-'A'][t[i]-'A'] = 1;
}

void genB(){
    string t = s;
    int used[32] = {0};
    repi(i,1,(T%N)+1){
        int nxt = 0;
        rep(j,N) if(used[t[nxt]-'A'] > used[t[j]-'A'])
            nxt = j;
        used[t[nxt]-'A']++;
        rep(j,i){
            int p = (nxt+j)%N, q = (p+1)%N;
            if(q == 0) t = t.substr(N-1,1)+t.substr(0,N-1);
            else swap(t[p],t[q]);
        }
    }
    rep(i,N) B[s[i]-'A'][t[i]-'A'] = 1;
}

void solve(){
    genA();
    genB();
    cerr << endl;
    mat C = mul(B,pow(A,T/N));

    string ans;
    rep(i,N)rep(j,M)
        if(C[s[i]-'A'][j]) ans.pb(j+'A');
    cout << ans << endl;
}

bool input(){
    cin >> T;
    if(T == 0) return 0;
    cin >> s;
    return 1;
}

void init(){
    N = s.size();
    A.clear(); B.clear();
    A.resize(M, arr(M,0));
    B.resize(M, arr(M,0));
}

int main()
{
    int c = 1;
    while(input()){
        init();
        cout << c++ << ". ";
        solve();
    }
    return 0;
}
