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

int n, m, w[32], done[32], dp[1<<18];
vector<int> G[32];
vector<int> vs;
map<string, int> id;

inline void chmax(int &x, int y) { x = max(x,y);}

bool ok(int i, int s)
{
  if(dp[s]<0) return 0;
  for(auto &e: G[i]) if(~s>>e&1) return 0;
  return ~s>>i&1;
}

int solve()
{
  dp[0] = 0;
  rep(i,1<<n) {
    rep(j,n) {
      int k = __builtin_popcount(i)+1;
      if(ok(j,i)) chmax(dp[1<<j|i],dp[i]+k*w[j]);
    }
  }
  return max(0, dp[(1<<n)-1]);
}

void init()
{
  id.clear();
  vs.clear();
  rep(i,20) G[i].clear();
  memset(dp, -1, sizeof(dp));
}

void input()
{
  init();
  cin >> n >> m;
  cin.ignore();
  rep(i,n) {
    string s;
    getline(cin, s);
    while(s.size() and s.back() == ' ') s.pop_back();
    int k = s.find_last_of(' ');
    string title = s.substr(0, k);
    int val = atoi(s.substr(k+1).c_str());
    id[title] = i;
    w[i] = val;
  }

  rep(i,m) {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string a, b;
    ss >> a;
    while(ss >> s, s != "-->") a += " "+s;
    ss >> b;
    while(ss >> s) b += " "+s;
    G[id[b]].pb(id[a]);
  }
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    input();
    cout << solve() << endl;
  }
  return 0;
}
