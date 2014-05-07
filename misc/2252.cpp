#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

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

bool lorr(char c){
    string left = "qwertasdfgzxcvb";
    return left.find(c) != string::npos;
}

int main(){
    string str;
    while(cin>>str,str!="#"){
        bool left = lorr(str[0]); 
        int ans = 0;
        repi(i,1,str.size()){
            if(left != lorr(str[i])){
                ans++;
                left = !left;
            }
        }
        cout << ans << endl;
    }
}
