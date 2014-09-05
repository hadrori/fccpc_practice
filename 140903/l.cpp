#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    rep(i, N) {
        x[i] += 2e8, y[i] += 2e8;
    }
    int min_x = x[0]-y[0], max_x = x[0]-y[0];
    int min_y = y[0]+x[0], max_y = y[0]+x[0];
    rep(i, N) {
        min_x = min(min_x, x[i]-y[i]);
        min_y = min(min_y, y[i]+x[i]);
        max_x = max(max_x, x[i]-y[i]);
        max_y = max(max_y, y[i]+x[i]);
    }
    double mid_x = (min_x + max_x)/2.0;
    double mid_y = (min_y + max_y)/2.0;
    double midxx = (mid_x + mid_y)/2.0;
    double midyy = (mid_y - mid_x)/2.0;
    swap(mid_x, midxx);
    swap(mid_y, midyy);

    double ans = 1e18;

    const double RANGE = 4.0;
    //const double eps = 1e-5;
    
    repi(ppx, (mid_x-RANGE)*2, (mid_x+RANGE)*2+1) {
        double px = ppx/2.0;
        repi(ppy, (mid_y-RANGE)*2, (mid_y+RANGE)*2+1) {        
            double py = ppy/2.0;
            bool ns = false;
            double tmp = 0;
            if(ppx%20 == 0 and ppy%20 == 0) {
                rep(i, N) {
                    tmp = max(tmp, abs(px-x[i]) + abs(py-y[i]));
                }
                ans = min(tmp, ans);
                continue;
            } else if(ppx%20 == 0) {
                ns = false;
            } else if(ppy%20 == 0) {
                ns = true;
            } else {
                continue;
            }

            rep(i, N) {
                if(!ns) {
                    if(ppx%2 == 0 and ppx/2 == x[i]) 
                        tmp = max(tmp, abs(py-y[i]));
                    else 
                        tmp = max(tmp,
                                  min(abs((int)(py/10)*10-py) + abs((int)(py/10)*10-y[i]) + abs(px-x[i]),
                                      abs((int)(py/10)*10+10-py) + abs((int)(py/10)*10+10-y[i]) + abs(px-x[i])));
                } else {
                    if(ppy%2 == 0 and ppy/2 == y[i])
                        tmp = max(tmp, abs(px-x[i]));
                    else
                        tmp = max(tmp,
                                  min(abs((int)(px/10)*10-px) + abs((int)(px/10)*10-x[i]) + abs(py-y[i]),
                                      abs((int)(px/10)*10+10-px) + abs((int)(px/10)*10+10-x[i]) + abs(py-y[i])));                    
                }
            }
            
            ans = min(tmp, ans);
        }
    }
    printf("%.3f\n", ans);
    // cout << ans << endl;
    
    return 0;
}
