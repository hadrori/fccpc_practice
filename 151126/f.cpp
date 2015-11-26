#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
#define long int64_t

int n, A, B, C, m;

const int MAX = 10005;
int a[MAX], b[MAX], c[MAX];
int mina, minb, minc;
int comp;
vector<pair<int, int> > E[MAX];
bool ab, bc, ac;
bool ign[MAX];

void input() {
  rep(i, MAX) E[i].clear();
  
  cin >> n >> A >> B >> C;
  rep(i, A) cin >> a[i];
  rep(i, B) cin >> b[i];
  rep(i, C) cin >> c[i];
  
  mina = a[0], minb = b[0], minc = c[0];
  rep(i, A) mina = min(mina, a[i]);
  rep(i, B) minb = min(minb, b[i]);
  rep(i, C) minc = min(minc, c[i]);
  
  map<int, int> zip;
  rep(i, n+1) zip[i] = i;
  rep(i, A) zip[a[i]] = mina;
  rep(i, B) zip[b[i]] = minb;
  rep(i, C) zip[c[i]] = minc;

  cin >> m;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x = zip[x];
    y = zip[y];
    //cout << "edge: " << x << " " << y << endl;    
    E[x].pb(mp(y, 1));
    E[y].pb(mp(x, 1));
  }

  rep(i, n+1) ign[i] = (zip[i] != i);
  
  ab = (find(all(E[mina]), mp(minb, 1)) != E[mina].end());
  bc = (find(all(E[minb]), mp(minc, 1)) != E[minb].end());
  ac = (find(all(E[minc]), mp(mina, 1)) != E[minc].end());

  if (!ab and !bc and !ac) {
    comp = 3;   
  } else if (ac and !ab and !bc) {
    comp = 2;
    E[mina].pb(mp(minc, 0));
    E[minc].pb(mp(mina, 0));
  } else if (bc and !ab and !ac) {
    comp = 2;
    E[minb].pb(mp(minc, 0));
    E[minc].pb(mp(minb, 0));
  } else if (ab and !bc and !ac) {
    comp = 2;
    E[mina].pb(mp(minb, 0));
    E[minb].pb(mp(mina, 0));
  } else {
    comp = 1;
    E[mina].pb(mp(minc, 0));
    E[minc].pb(mp(mina, 0));
    E[mina].pb(mp(minb, 0));
    E[minb].pb(mp(mina, 0));
  }
  //if 
    
}

int dstA[MAX], dstB[MAX], dstC[MAX];
int idA[MAX], idB[MAX], idC[MAX];

void calcDst(int dst[MAX], int ids[MAX], int root) {
  memset(dst, -1, sizeof(int)*MAX);
  priority_queue<pair<pair<int, int> , int> > q;  
  q.push(mp(mp(0, -root), root));
  while (q.size()) {
    int now = q.top().second;
    int cst = -q.top().first.first;
    int id = -q.top().first.second;
    q.pop();
    if (dst[now] != -1) continue;
    dst[now] = cst;
    ids[now] = id;
    for (auto e: E[now]) {
      q.push(mp(mp(-(cst+e.second), -min(id, e.first)), e.first));
    }
  }
}

void solve() {  
  calcDst(dstA, idA, mina);
  calcDst(dstB, idB, minb);
  calcDst(dstC, idC, minc);
  
  const int inf = 1e9;
  int mindst = inf;
  int ans = -1;
  repi(i, 1, n+1) {
    if (ign[i]) continue;
    int val;
    if (comp == 1) val = dstA[i];
    else if (comp == 2) {
      if (ab) val = dstA[i] + dstC[i];
      else if (bc) val = dstA[i] + dstB[i];
      else val = dstA[i] + dstB[i];
    } else {
      val = dstA[i] + dstB[i] + dstC[i];
    }    
    
    if (mindst > val) {
      mindst = val;      
      ans = min(idA[i], min(idB[i], idC[i]));
    }
  }

  if (comp == 1) mindst += 2;
  else if (comp == 2) mindst += 1;  
  cout << mindst << " " << ans << endl;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  input();
  solve();
  return 0;
}
