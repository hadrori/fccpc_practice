#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(u) begin(u),end(u)
#define long uint64_t

const int K = 128;
const long p = 9973;

long pow_p[K] = {1};

void prepare()
{
  repi(i, 1, K) pow_p[i] = pow_p[i-1] * p;
}

string& make_lower(string& s)
{
  for (char& c : s) {
    if (isupper(c)) c += 'a' - 'A';
  }
  return s;
}

int id_of_string(const string& s)
{
  static map<string, int> mp;
  auto it = mp.find(s);
  const auto t = mp.size();
  return it == mp.end() ? mp[s] = t : mp[s];
}

int n;

set<long> mem;

void solve()
{
  mem.clear();
  mem.insert(id_of_string("joe"));
  bool testing = false;
  vector<string> ss;
  vector<long> vec(1);
  string s;
  while (cin >> s) {
    if (string(".,:;?!*#").find(s[0]) != string::npos) {
      rep(i, vec.size()-1) {
        const long t = vec[i+1] - p * vec[i];
        if (mem.find(t) == mem.end()) {
          if (testing) cout << "What does the word \"" << ss[i] << "\" mean?\n";
          mem.insert(t);
        }
      }
      if (testing) {
        bool flag = true;
        repi(len, 1, n+1) {
          rep(i, vec.size()-len) {
            const long t = vec[i+len] - pow_p[len] * vec[i];
            if (mem.find(t) == mem.end()) {
              flag = false;
              break;
            }
            if (!flag) break;
          }
        }
        if (!flag) {
          cout << "What does the sentence \"";
          rep(i, ss.size()) {
            if (i) cout << ' ';
            cout << ss[i];
          }
          cout << "\" mean?\n";
        }
      }
      repi(len, 1, n+1) {
        rep(i, vec.size()-len) {
          const long t = vec[i+len] - pow_p[len] * vec[i];
          mem.insert(t);
        }
      }
      ss.clear();
      vec.assign(1, 0);
      if (s[0] == '*') testing = true;
      if (s[0] == '#') break;
    } else {
      ss.push_back(s);
      make_lower(s);
      vec.push_back(vec.back() * p + id_of_string(s));
    }
  }
}

int main()
{
  prepare();
  int t = 0;
  while (cin >> n) {
    if (t) cout << endl;
    cout << "Learning case " << ++t << endl;
    solve();
  }
}
