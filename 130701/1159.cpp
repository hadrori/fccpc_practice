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

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
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

int main() {
    int n, p;
    while(cin >> n >> p, n || p){
        vi cand(n,0);
        int turn = 0;
        int st = p;
        while(1){
            if(st == 1 && cand[turn%n] == p-1){
                cout << turn%n << endl;
                break;
            }
            if(st == 0){
                st = cand[turn%n];
                cand[turn%n] = 0;
            }
            else{
                st--;
                cand[turn%n]++;
            }
            turn++;
        }
    }
    return 0;
}
