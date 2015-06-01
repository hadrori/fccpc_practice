#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(u) begin(u),end(u)

const int CS = 256;

const int MAX = 20005;
map<string, int> tbl;
string tbl2[MAX];
int freq[MAX];
int id;

string getString(int id) {
  return tbl2[id];
}

int getId(const string &s) {
  if(tbl.find(s) != tbl.end()) return tbl[s];
  tbl2[id] = s;
  return tbl[s] = id++;
}

void input()
{
  char s_[CS];
  id = 0; tbl.clear();
  memset(freq, 0, sizeof(freq));
  set<pair<int, int> > st;
  deque<vector<int> > deq;
  vector<int> v;
  while(scanf("%s", s_) != EOF) {
    string s(s_);
    if(s == "<text>") {
      continue;
    } else if(s == "</text>") {
      deq.push_back(v);
      for(int num : v) {
        st.erase(make_pair(-freq[num], num));
        freq[num]++;
        st.insert(make_pair(-freq[num], num));
      }
      v.clear();
      while(deq.size() > 7) {
        vector<int> u = deq.front();
        for(int num : u) {
          st.erase(make_pair(-freq[num], num));
          freq[num]--;
          st.insert(make_pair(-freq[num], num));
        }
        
        deq.pop_front();        
      }

    } else if(s == "<top") {
      int n;
      scanf("%d", &n);
      scanf("%s", s_);
      int bf = -1;
      printf("<top %d>\n", n);
      vector<pair<int, string> > ans;
      for(pair<int, int> p : st) {
        if(n <= 0 and bf != p.first) break;
        ans.push_back(make_pair(p.first, getString(p.second)));        
        bf = p.first;
        n--;
      }
      sort(all(ans));
      for(pair<int, string> p : ans) {
        printf("%s %d\n", p.second.c_str(), -p.first);
      }
      
      printf("</top>\n");
    } else if(s.size() >= 4) {
      v.push_back(getId(s));
    }
  }
  
  
}

void solve()
{
  
}

int main()
{
  input();
  solve();
}
