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

#define repi(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i =(a); i >= (b); i--)
#define repit(i,a) for(__typedef((a).begin()) i =(a); i != (a).end(); i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)), (u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int N = 100010;

int W, a[N];

void input()
{
    cin >> W;
    rep(i, W)
	cin >> a[i];
}

int lexit[N] = {}, rexit[N] = {};

void gen()
{
    int l = -1;
    rep(i, W) {
	if (a[i] == 0)
	    l = i;
	else if (a[i] > 0)
	    lexit[i] = l;
    }
    int r = W;
    repd(i, W - 1, 0) {
	if (a[i] == 0)
	    r = i;
	else if (a[i] > 0)
	    rexit[i] = r;
    }
}

int block, froml[N], blockl[500], fromr[N], blockr[500];

void gen1()
{
    block = (int) sqrt(W);
    fill(froml, froml + N, INF);
    fill(fromr, fromr + N, INF);
    fill(blockl, blockl + 500, INF);
    fill(blockr, blockr + 500, INF);

    rep(i, W) {
	if (a[i] < 0) {
	    froml[i] = min(froml[i], -a[i] + i);
	    blockl[i / block] = min(blockl[i / block], -a[i] + i);
	    fromr[i] = min(fromr[i], -a[i] - i);
	    blockr[i / block] = min(blockr[i / block], -a[i] - i);
	}
    }
}

int queryl(int l, int r)
{
    int ret = INF;
    int lb = l / block;
    int rb = r / block;
    if (lb == rb) {
	repi(i, l, r + 1)
	    ret = min(ret, froml[i]);
    } else {
	repi(i, l, (lb + 1) * block)
	    ret = min(ret, froml[i]);
	repi(i, lb + 1, rb)
	    ret = min(ret, blockl[i]);
	repi(i, rb * block, r + 1)
	    ret = min(ret, froml[i]);
    }
    return ret;
}

int queryr(int l, int r)
{
    int ret = INF;
    int lb = l / block;
    int rb = r / block;
    if (lb == rb) {
	repi(i, l, r + 1)
	    ret = min(ret, fromr[i]);
    } else {
	repi(i, l, (lb + 1) * block)
	    ret = min(ret, fromr[i]);
	repi(i, lb + 1, rb)
	    ret = min(ret, blockr[i]);
	repi(i, rb * block, r + 1)
	    ret = min(ret, fromr[i]);
    }
    return ret;
}

int solve()
{
    int ret = 0;
    rep(i, W) {
	if (a[i] > 0) {
	    int part = 0;
	    if (lexit[i] >= 0)
		part = max(part, min(a[i], queryl(lexit[i], i) - i));
	    if (rexit[i] < W)
		part = max(part, min(a[i], queryr(i, rexit[i]) + i));
	    ret += part;
	}
    }
    return ret;
}

int main()
{
    input();
    gen();
    gen1();
    cout << solve() << endl;

    return 0;
}
