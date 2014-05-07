#include <algorithm>
#include <bitset>
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


char s[40004];
int a[40004];
int m, n;
int ans;
typedef unsigned long long ui;
const ui BASE = 1000000007;
const ui MOD = 10000003;
int table[MOD];
ui BASES[40004];
ui hashes[40004];

bool C(int &l) {
    if(l > n) return false;
    if(l == 0) return true;
    //memset(table, 0, sizeof(table));
    ui hash = 0;
    ui BL = BASES[l];
    hash = hashes[l-1];
    bool ret = false;
    
    vector<int> v;
    v.pb(hash%MOD);
    if(++table[hash%MOD] >= m) {
	ret = true;
	ans = 0;
    }

    repi(i, l, n) {
	hash = hash * BASE - a[i-l] * BL + a[i];
	if(++table[hash%MOD] >= m) {
	    ret = true;
	    ans = i - l + 1;
	}
	v.pb(hash%MOD);
    }
    rep(i, v.size()) table[v[i]] = 0;
    return ret;
}

int main() {
    /*
      cout << 20000 << endl;
      rep(i, 40000) cout << 'a';
      cout << endl;
      cout << 0 << endl;
      return 0;*/
    BASES[0] = 1;
    rep(i, 40001) BASES[i+1] = BASES[i] * BASE;
    
    while(scanf("%d", &m), m) {
	scanf("%s", s);
	n = 0;
	while(s[n]) {
	    a[n] = s[n] - 'a' + 1;
	    n++;
	}
	
	hashes[0] = a[0];
	rep(i, n) {
	    hashes[i+1] = hashes[i] * BASE + a[i+1];
	}
	
	int lower = 0;
	int upper = n+1;
	int mid;
	while(upper - lower > 1) {
	    mid = (lower + upper) / 2;
	    if(C(mid)) lower = mid;
	    else upper = mid;
	}
	if(lower) printf("%d %d\n", lower, ans);
	else printf("none\n");
    }
    return 0;
}
