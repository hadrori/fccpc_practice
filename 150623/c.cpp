#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair
#define long int64_t

int main()
{
    long a, b;
    scanf("%I64d %I64d", &a, &b);
    
    if(b == 0) {
        printf("%I64d\n", a*a);
        rep(_, a) printf("o");
        puts("");
        return 0;
    } else if(a == 0) {
        printf("%I64d\n", -b*b);
        rep(_, b) printf("x");
        puts("");
        return 0;
    } else if(b == 1) {
        printf("%I64d\n", a*a-1);
        rep(_, a) printf("o");
        printf("x");
        puts("");
        return 0;
    }

    long ans_p = -1;
    const long inf = 1000000000000LL;
    long ans = -inf;
    repi(p, 2, min(b, a+1)+1) {
        long rem = b%p;
        long xv = ((b/p) * (b/p)) * (p-rem) + ((b/p+1) * (b/p+1)) * rem;
        long ov = (a-(p-2)) * (a-(p-2)) + 1*1*(p-2);
        long val = ov - xv;        
        if(ans < val) {
            ans = val;
            ans_p = p;
        }
    }

    //cout << "ans_p: " << ans_p << endl;
    printf("%I64d\n", ans);
    
    rep(i, ans_p-1) {
        // print x
        if(i < b%ans_p) {
            rep(_, b/ans_p+1) printf("%c", 'x');
        } else {
            rep(_, b/ans_p) printf("%c", 'x');
        }
        
        // print o
        if(i == 0) {
            rep(_, a-(ans_p-2)) printf("%c", 'o');
        } else {
            printf("%c", 'o');
        }        
    }
    rep(_, b/ans_p) printf("%c", 'x');
    
    
    puts("");
    return 0;
}
