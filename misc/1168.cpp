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
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int w, h;

int dj[] = {-1,0,1,0};
int di[] = {0,1,0,-1};

vector<string> ori;
vector<string> museum;
vector<int> cnt;
vector<vector<bool> > flag;

int bottom;
int xl, xr;

void dfs(int i, int j, char c){
    museum[i][j] = 'A';
    if((i+1<h && museum[i+1][j] != '.' && museum[i+1][j] != c && museum[i+1][j] != 'A') || i==h-1){
        xl = min(xl, j);
        xr = max(xr, j);
        //    cout << xl << ' ' << xr << ' ' << i << ' ' << j <<endl;
    }
    rep(a,4){
        int ti = i + di[a];
        int tj = j + dj[a];

        if(ti>=0 && ti<h && tj>=0 && tj<w && museum[ti][tj]==c) dfs(i+di[a],j+dj[a],c);
    }
}

void centerg(int i, int j){
    cnt[j]++;
    flag[i][j] = true;
    rep(a,4){
        int ti = i + di[a];
        int tj = j + dj[a];
        if(ti<0 || ti>=h || tj<0 || tj>=w) continue;
        if(a!=3 && ori[ti][tj] != ori[i][j]) continue;
        if(!flag[ti][tj] && museum[ti][tj]=='A') centerg(i+di[a],j+dj[a]);
    }
}


bool ison(int i, int j, char c){
    flag[i][j] = true;
    if(i > 0 && museum[i-1][j] != 'A' && museum[i-1][j] != '.' && museum[i-1][j] != c) return true;
    rep(a,4){
        int ti = i + di[a];
        int tj = j + dj[a];
        if(ti >= 0 && ti < h && tj >= 0 && tj < w &&
           !flag[ti][tj] && museum[ti][tj] == c){
               if(ison(ti,tj,c)) return true;
        }
    }
    return false;
}

int main(){
    while(cin>>w>>h,w||h){
        museum.clear();
        museum.resize(h);
        cnt.clear();
        cnt.resize(w);
        xl = 0;
        xr = 0;
        rep(i,h) cin >> museum[i];
        ori = museum;
        /*
          rep(i,h) rep(j,w) if(museum[i][j] != '.'){
          dfs(i,j,museum[i][j]);
          goto soto;
          }
          soto:;
        */
        bool ok = true;
        bool mada = true;
        while(mada){
            mada = false;
            rep(i,h){
                rep(j,w){
                    //cout << i << ' ' << j << endl;
                    bottom = -1;
                    if(museum[i][j]!='.' && museum[i][j]!='A'){
                        flag.resize(h);
                        rep(k,h) flag[k] = vector<bool>(w,false);
                        if(ison(i,j,museum[i][j])){
                            mada = true;
                            flag.clear();
                            continue;
                        }
                        flag.clear();
                        //	cout << "hoge\n";
                        //	rep(a,h)rep(b,w)cout << museum[a][b] << (b==w-1? '\n': ' ');
                        //	cout << endl;
                        xl = 100000000;
                        xr = -1;
                        dfs(i,j,museum[i][j]);
                        //rep(a,h)rep(b,w)cout << museum[a][b] << (b==w-1? '\n': ' ');
                        //	cout << endl;
                        double cgx = 0;
                        
                        cnt.clear();
                        cnt.resize(w);
                        flag.clear();
                        flag.resize(h);
                        
                        rep(k,h) flag[k] = vector<bool>(w,false);
                        centerg(i,j);
                        int sum = 0;
                        rep(k,w){
                            sum += cnt[k];
                            cgx += (k+0.5)*cnt[k];
                        }
                        cgx /= sum;
                        //	cout << sum << ' ' << cgx << ' ' << xl << ' ' << xr << endl;
                        if(cgx<=xl+EPS || cgx+EPS>=xr+1){
                            ok = false;
//                            cout << i << ' ' << j << endl;
                            goto fail;
                        }
                    }
                }
            }
        }
    fail:;
        cout << (ok? "STABLE\n": "UNSTABLE\n");
    } 
}
