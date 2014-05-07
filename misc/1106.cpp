#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define rep(i,a) for(int i = 0; i < a; i++)
using namespace std;
int a, b, c;

int main(){
    // cout << __gcd(34, 51) << endl;

    while(cin >> a >> b >> c, a||b||c){
        //cout << "a\n";
        int D = b*b-4*a*c;
        int root = (int) (sqrt(D) + 0.5);
        if (root * root != D) {
            cout << "Impossible" << endl;
            continue;
        }
        int p, q, r, s;
        q = b-root;
        p = 2*a;
        s = b+root;
        r = 2*a;

        
        int gpq, grs;
        gpq = __gcd(p, q);
        grs = __gcd(r, s);
        p /= gpq;
        q /= gpq;
        r /= grs;
        s /= grs;
        if(p <= 0) {
            p = -p;
            q = -q;
        }
        if(r <= 0) {
            r = -r;
            s = -s;
        }        
        if(p <= r){
            int tmp;
            tmp = p;
            p = r;
            r = tmp;
            tmp = q;
            q = s;
            s = tmp;
        }
        if(p == r && q < s){
            swap(p, r);
            swap(q, s);
        }
        cout << p << " " << q << " " << r << " " << s << endl;
    }
}
