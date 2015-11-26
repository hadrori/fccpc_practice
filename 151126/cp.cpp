#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
#define long int64_t

const int MAX = 1024;
char D[MAX];
int L[MAX];
int n;
void input() {
  cin >> n;
  rep(i, n) cin >> D[i] >> L[i];  
}

int dp[MAX][MAX];
void solve() {
  const int inf = 1e9;
  rep(i, MAX) dp[0][i] = inf;

  int minv = 0;
  rep(i, n) {    
    rep(j, MAX) minv = min(minv, dp[i][j]);
    if (D[i] == 'n') {
      repi(j, L[i]+1, MAX) dp[i+1][j] = dp[i][j];
      rep(j, L[i]+1) dp[i+1][j] = inf;
    } else {
      minv++;
      rep(j, L[i]+1) dp[i+1][j] = min(minv, dp[i][j]);
      repi(j, L[i]+1, MAX) dp[i+1][j] = inf;      
    }    
    //cout << minv << endl;
    //rep(j, 10) cout << dp[i+1][j] << " ";
    //cout << endl;
  }
  int ans = minv;
  rep(i, MAX) ans = min(ans, dp[n][i]);
  cout << ans << endl;
}

void solve_naive() {
  //const int inf = 1e9;
  vector<pair<int, int> > v;
  rep(i, n) if (D[i] == 'y') v.pb(mp(L[i], i));
  sort(all(v));
  
  int ans = 0;
  vector<bool> done(n, false);
  for (pair<int, int> p: v) {
    int pos = p.second;
    int lim = L[pos];
    if (done[pos]) continue;
    ans++;
    while (pos >= 0) {
      if (D[pos] == 'n' and L[pos] >= lim) break;
      done[pos] = true;
      pos--;
    }
    pos++;

    while (pos < n) {
      if (D[pos] == 'n' and L[pos] >= lim) break;
      done[pos] = true;
      pos++;
    }
  }
  cout << ans << endl;
  
}


void gen(int n) {
  cout << n << endl;
  rep(i, n) {
    cout << (rand()%2?'y':'n') << " " << rand()%100 << endl;
  }
}

int main() {
  //srand(time(NULL));
  //gen(10);
  //return 0;
  
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  input();
  //solve();
  solve_naive();
  return 0;
}
