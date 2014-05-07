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

int N, T;
struct C{
    int M, L, K;
    C(int M, int L, int K):M(M),L(L),K(K){}
};
vector<C> customers;

bool can(int n){
    priority_queue<int> op;
    vector<C> cust = customers;
    bool done[1024] = {false};
    rep(i,n) op.push(0);
    while(-op.top() <= T){
	int tim = -op.top(); op.pop();
	int use = -1, dif = INF;
//	cerr << tim << endl;
	bool exist = false;
	repit(itr,cust)if(!*(done + (int)(itr - cust.begin()))){
	    int t = tim % (itr->L + itr->K);
	    int tmp = itr->L + itr->K - t;
	    if( tmp >= itr->K ) tmp = 0;
	    if(tmp < dif){
		use = itr - cust.begin();
		dif = tmp;
	    }
	    exist = true;
	}
	if(!exist) return true;
	int tmp = -cust[use].M - dif - tim;
	if(tmp < -T) return false;
	op.push(tmp);
	done[use] = true;
    }
    return true;
}

int main()
{
    while(cin >> N >> T, N || T){
	customers.clear();
	rep(i,N){
	    int m, l, k;
	    cin >> m >> l >> k;
	    customers.pb(C(m,l,k));
	}
	rep(i,N)if(can(i+1)){
	    cout << i + 1 << endl;
	    break;
	}
/*
	while(lb + 1 < ub){
	    mid = (ub + lb) / 2;
	    if(can(mid)) ub = mid;
	    else lb = mid;
	    cerr << endl;
	}
	cout << ub << endl;
*/
    }
    return 0;
}
