#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
#define mp make_pair
#define all(u) (u).begin(),(u).end()

const int MAX = 1 << 19;

typedef complex<double> cd;
vector<cd> fft(vector<cd> f, bool inv){
    int n, N = f.size();
    for(n=0;;n++) if(N == (1<<n)) break;
    rep(m,N){
        int m2 = 0;
        rep(i,n) if(m&(1<<i)) m2 |= (1<<(n-1-i));
        if(m < m2) swap(f[m], f[m2]);
    }

    for(int t=1;t<N;t*=2){
        double theta = acos(-1.0) / t;
        cd w(cos(theta), sin(theta));
        if(inv) w = cd(cos(theta), -sin(theta));
        for(int i=0;i<N;i+=2*t){
            cd power(1.0, 0.0);
            rep(j,t){
                cd tmp1 = f[i+j] + f[i+t+j] * power;
                cd tmp2 = f[i+j] - f[i+t+j] * power;
                f[i+j] = tmp1;
                f[i+t+j] = tmp2;
                power = power * w;
            }
        }
    }
    if(inv) rep(i,N) f[i] /= N;
    return f;
}

long long ans[MAX];

struct _{_(){
  vector<cd> v(2 * MAX);
  for (int i = 1; i < MAX; ++i) {
    for (int j = i; j < MAX; j += i) {
      v[j] += 1.0;
    }
  }
  v = fft(v, 0);
  rep(i, v.size()) v[i] *= v[i];
  v = fft(v, 1);
  rep(i, MAX) ans[i] = round(real(v[i]));
}}_;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int l, r;
    cin >> l >> r;
    int pos = max_element(ans + l, ans + r + 1) - ans;
    cout << pos << ' ' << ans[pos] << endl;
  }
  return 0;
}
