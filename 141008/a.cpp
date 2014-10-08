#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

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

struct frac
{
    ll num, den;
    frac(){}
    frac(ll num, ll den):num(num),den(den){normalize();}
    frac(ll num):num(num){den=1;}
    void normalize(){
        if(num == 0) {
            den = 1;
            return;
        }
        if(den < 0) {
            num *= -1;
            den *= -1;
        }
        ll t = __gcd(abs(num),den);
        num /= t;
        den /= t;
    }
    frac operator*=(const frac &f){
        ll t = __gcd(den, f.num), u = __gcd(f.den,num);
        num *= f.num/t;
        den *= f.den/u;
        return *this;
    }
    frac operator*(const frac &f) const { return frac(*this)*=f;}
    frac operator/=(const frac &f){
        ll t = __gcd(den,f.den), u = __gcd(f.num,num);
        num *= f.den/t;
        den *= f.num/u;
        if(den < 0) {
            num *= -1;
            den *= -1;
        }
        return *this;
    }
    frac operator/(const frac &f) const { return frac(*this)/=f;}
    frac operator+=(const frac &f){
        ll t = __gcd(den,f.den);
        num = f.den/t*num+den/t*f.num;
        den = den/t*f.den;
        normalize();
        return *this;
    }
    frac operator+(const frac &f) const { return frac(*this)+=f;}
    frac operator-=(const frac &f){
        ll t = __gcd(den,f.den);
        num = f.den/t*num-den/t*f.num;
        den = den/t*f.den;
        normalize();
        return *this;
    }
    frac operator-(const frac &f) const { return frac(*this)-=f;}
    bool operator<(const frac &f) const { return num*f.den < den*f.num;}
    bool operator>(const frac &f) const { return num*f.den > den*f.num;}
    bool operator==(const frac &f) const { return num*f.den == den*f.num;}
};

frac zero() { return frac(0, 1); }

struct point
{
    frac x, y, z;
    point(){}
    point(frac x, frac y, frac z):x(x),y(y),z(z){}
    point operator+=(const point &p){
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
    point operator+(const point &p) const { return point(*this)+=p;}
    point operator-=(const point &p){
        x -= p.x;
        y -= p.y;
        z -= p.z;
        return *this;
    }
    point operator-(const point &p) const { return point(*this)-=p;}
    point operator*=(const frac &f){
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
    point operator*(const frac &f) const { return point(*this)*=f;}

    frac norm() { return x*x+y*y+z*z;}
    frac dot(point p) { return x*p.x+y*p.y+z*p.z;}
    point cross(point p) { return point(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x);}
};

point operator*(const frac &f, const point &p) { point ret = p*f; return ret;}
frac abs(frac f) { return frac(abs(f.num),f.den);}
frac dot(point p, point q) { return q.x*p.x+q.y*p.y+q.z*p.z;}
point cross(point q, point p) { return point(q.y*p.z-q.z*p.y, q.z*p.x-q.x*p.z, q.x*p.y-q.y*p.x);}
point n;

struct line
{
    point a, b;
    line(){}
    line(point a, point b):a(a),b(b){}
    point vec() { return a-b;}
    frac norm() { return (a-b).norm();}
};

int ccw(point a, point b, point c)
{
    b -= a; c -= a;
    if(dot(cross(b, c), n) > zero()) return 1;
    if(dot(cross(b, c), n) < zero()) return -1;
    return 0;
}

bool intersectLS(line l, line s) {
    return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) <= 0;
}

bool intersectSS(line s, line t) {
    return intersectLS(s, t) and intersectLS(t, s);
}
bool intersectSP(line &l, point &p){ return (l.a-p).norm()+(l.b-p).norm() == l.norm();}
frac min(frac f, frac g)
{
    if(f < g) return f;
    return g;
}

frac distanceSP(line &s, point &p){
    frac a = (s.a-p).norm(), b = (s.b-p).norm(), c = s.norm();
    frac tmp = a-b+c;
    frac h = a-tmp*tmp/(frac(4,1)*c);
    if(tmp < zero() or tmp > frac(2)*c) return min(a, b);
    return min(h,min(a,b));
}

frac distanceSS(line s, line t){ return min(min(distanceSP(s,t.a),distanceSP(s,t.b)), min(distanceSP(t,s.a),distanceSP(t,s.b)));}

std::ostream &operator<<(std::ostream &os, const frac &f){
    os<<f.num<<" "<<f.den;
    return os;
}
std::ostream &operator<<(std::ostream &os, const point &p){
    os<<"("<<p.x<<","<<p.y<<","<<p.z<<")";
    return os;
}

frac solve() {
    vector<ll> x(4), y(4), z(4);
    rep(i, 4) {
        scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);
    }
    
    point a = point(frac(x[0]), frac(y[0]), frac(z[0]));
    point b = point(frac(x[1]), frac(y[1]), frac(z[1]));
    point c = point(frac(x[2]), frac(y[2]), frac(z[2]));
    point d = point(frac(x[3]), frac(y[3]), frac(z[3]));
    
    n = cross(b-a, d-c);
    if(n.norm() == zero()) {
        n = cross(b-a, d-a);
        if(n.norm() == zero()) {
            n = cross(b-a, c-a);
            if(n.norm() == zero()) {
                //cout << "n == 0" << endl;
                if(dot(c-a, d-a) < zero()) return zero();
                if(dot(c-b, d-b) < zero()) return zero();
                return min(min((a-c).norm(), (a-d).norm()),
                           min((b-c).norm(), (b-d).norm()));
            }
        }
    }
    cout << "n before: " << n << endl;
    ll t = __gcd(__gcd(n.x.den,n.y.den),n.z.den);
    n.x.den /= t;
    n.y.den /= t;
    n.z.den /= t;
    t = __gcd(__gcd(n.x.num,n.y.num),n.z.num);
    n.x.num /= t;
    n.y.num /= t;
    n.z.num /= t;
    cout << "abcd " << a << " " << b << " " << c << " " << d << endl;
    cout << "n: " << n << endl;
    cout << dot(n, a) - dot(n, c) << endl;
    cout << n.norm() << endl;
    frac h = (dot(n, a) - dot(n, c)) / n.norm();
    h.normalize();
    line l1 = line(a, b), l2 = line(c+h*n, d+h*n);
    //cout << "l1 " << l1.a << " " << l1.b << endl;
    //cout << "l2 " << l2.a << " " << l2.b << endl;
    if(intersectSS(l1, l2)) {
        cerr << "intersect" << endl;
        return h*h;
    } else {
        cerr << "not intersect " << h << endl;
        return distanceSS(l1, l2) + h*h;
    }
}

int main()
{
    int T;
    cin >> T;
    rep(i, T) {
        frac ans = solve();
        ans.normalize();
        cout << ans << endl;
    }
    return 0;
}
