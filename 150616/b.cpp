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
  rep(_, n) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (min({a, b, c}) >= 1 and a + b + c == 180 ? "YES" : "NO") << endl;
  }
    return 0;
}
