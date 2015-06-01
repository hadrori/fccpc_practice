#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;

int m;
vector<int> seq;
vector<char> ops;

inline int eval(int x, int y, char op)
{
  if(op == '+') return x+y;
  if(op == '-') return x-y;
  if(op == '*') return x*y;
  assert(0);
}

void dump(const vector<int> &s)
{
  cerr << "size : " << s.size() << endl;
  for (int i = 0; i < (int)s.size(); i++) cerr << s[i] << ' '; cerr << endl;
}

pair<int,int> dfs(int d, int p)
{
  const int USED = -10000000;
  if(d == m) {
    for(int i = 0; i < m+1; i++)
      if(seq[i] != USED)
        return make_pair(-1,seq[i]);
  }
  
  pair<int,int> ret = make_pair(-1,p? inf: -inf);
  int bf = 0;
  if(seq[0] == USED) bf++;
  for (int i = 0; i < m; i++) {
    if(seq[i+1] == USED) {
      bf++;
      continue;
    }
    if(i-bf < 0) {
      bf = 0;
      continue;
    }
    int tmp1 = seq[i+1];
    int tmp2 = seq[i-bf];
    seq[i+1] = eval(seq[i-bf],seq[i+1],ops[i-bf]);
    seq[i-bf] = USED;
    pair<int,int> res = dfs(d+1, 1-p);
    if(p and res.second < ret.second) {
      ret = res;
      ret.first = i - bf;
    }
    else if(!p and res.second > ret.second) {
      ret = res;
      ret.first = i - bf;
    }
    seq[i+1] = tmp1;
    seq[i-bf] = tmp2;
    bf = 0;
  }
  return ret;
}

void solve()
{
  pair<int,int> a1 = dfs(0,0);
  pair<int,int> a2 = dfs(0,1);
  cout << "Player 1 " << "(" << seq[a1.first] << ops[a1.first] << seq[a1.first+1] << ") leads to " << a1.second << endl;
  cout << "Player 2 " << "(" << seq[a2.first] << ops[a2.first] << seq[a2.first+1] << ") leads to " << a2.second << endl;

  if(a1.second > -a2.second) cout << "Player 1 wins" << endl;
  else if(a1.second < -a2.second) cout << "Player 2 wins" << endl;
  else cout << "Tie" << endl;
}

void input()
{
  cin >> m;
  seq.clear();
  ops.clear();
  for (int i = 0; i < m; i++) {
    int a; string s;
    cin >> a >> s;
    seq.push_back(a);
    ops.push_back(s[0]);
  }
  int a; cin >> a;
  seq.push_back(a);
}

int main()
{
  int T; cin >> T;
  for (int i = 1; i <= T; i++) {
    input();
    cout << "Case " << i << ":" << endl;
    solve();
  }
  return 0;
}
