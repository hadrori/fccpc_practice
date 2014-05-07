#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>ago
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

inline double tri(double a) { return (double)a*a*a; }

int main()
{
    int P;
    cin >> P;
    rep(i, P) {
        int cn;
        double L, W, H, A, B, C, D;
        cin >> cn >> L >> W >> H >> A >> B >> C >> D;
        double ans;
        if(A < 0) D -= A*L;
        if(B < 0) D -= B*W;
        if(C < 0) D -= C*H;
        A = abs(A);
        B = abs(B);
        C = abs(C);
        if(abs(A) < EPS && abs(B) < EPS) {
            ans = L*W;
        } else if(abs(A) > EPS && abs(B) > EPS) {
            double sum = 0;
            if(D-C*H > 0) {
                if(L*A + W*B < D-C*H) {
                    sum += L*W*2;
                } else {
                    sum += (D-C*H) * (D-C*H)/(A*B);
                    if(A/(D-C*H) > L) sum -= (D-C*H-A*L) * (D-C*H-A*L)/(A*B);
                    if(B/(D-C*H) > W) sum -= (D-C*H-B*W) * (D-C*H-B*W)/(A*B);
                }
            }

            double sq = 1.0/sqrt(A*A + B*B + C*C);
            if(D > 0) sum += tri(D)/(A*B*C) / (D*sq);
            if(D-A*L > 0) sum -= tri(D-A*L)/(A*B*C) /((D-A*L)*sq);
            if(D-B*W > 0) sum -= tri(D-B*W)/(A*B*C) /((D-B*W)*sq);
            if(D-C*H > 0) sum -= tri(D-C*H)/(A*B*C) /((D-C*H)*sq);
            ans = sum/2;
        } else {
            if(abs(A) < EPS) {
                swap(A, B);
                swap(L, W);
            }
            double dx = W-(D-C*H)/B;
            double dy = H-(D-B*W)/C;
            ans = L*sqrt(dx*dx + dy*dy) + L*(D-C*H)/B;
        }
        cout << cn << " " << (int)ceil(ans) << endl;
    }
    return 0;
}
