#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

int main()
{
  int n;
  cin >> n;
  cout << boolalpha;
  rep(_, n) {
    int x, y; string op;
    cin >> x >> op >> y;
    if (op == "!=") {
      cout << (x != y) << endl;
    } else if (op == "==") {
      cout << (x == y) << endl;
    } else if (op == "<") {
      cout << (x < y) << endl;
    } else if (op == "<=") {
      cout << (x <= y) << endl;
    } else if (op == ">") {
      cout << (x > y) << endl;
    } else if (op == ">=") {
      cout << (x >= y) << endl;
    }
  }
    return 0;
}
