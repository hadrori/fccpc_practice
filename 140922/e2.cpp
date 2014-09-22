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

const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
const string ds = "NESW";

char f[64][64];
int h, w, pi, pj, cur, dir, ans, done[64][64][1024][4];
string s;

void program();

void to_end(char l, char r)
{
    int res = 1;
    while(res){
        if(s[cur] == l) res++;
        else if(s[cur] == r) res--;
        cur++;
    }
}

int cond()
{
    int ret = 0;
    if(s[cur] == '~') {
        ret = 1;
        cur++;
    }
    char cd = ds[dir];
    if(s[cur] == 'T') ret ^= 1;
    else if(s[cur] == 'C') {
        int ni = pi+di[dir], nj = pj+dj[dir];
        if(f[ni][nj] == '#') ret ^= 1;
    }
    else if(cd == s[cur]) ret ^= 1;
    cur++;
    return ret;
}

void ifs()
{
    cur++;
    if(cond()) program();
    to_end('[',']');
}

void whiles()
{
    cur++;
    int head = cur;
    while(cond()){
        program();
        cur = head;
    }
    to_end('{','}');
}

void move()
{
    ans++;
    if(s[cur] == '^') {
        int ni = pi+di[dir], nj = pj+dj[dir];
        if(f[ni][nj] != '#') pi = ni, pj = nj;
    }
    else if(s[cur] == 'v') {
        int ni = pi-di[dir], nj = pj-dj[dir];
        if(f[ni][nj] != '#') pi = ni, pj = nj;
    }
    else if(s[cur] == '<') dir = (dir+3)%4;
    else dir = (dir+1)%4;
    cur++;
    if(f[pi][pj] == 'g') throw ans;
}

void program()
{
    if(f[pi][pj] == 'g') throw ans;
    if(done[pi][pj][cur][dir]) throw -1;
    done[pi][pj][cur][dir] = 1;
    cur++;
    if(s[cur] == '[') ifs();
    else if(s[cur] == '{') whiles();
    else move();
    cur++;
}

int solve()
{
    memset(done, 0, sizeof(done));
    try{
        program();
    }catch(int e){
        return e;
    }
    return -1;
}

void input()
{
    cin >> h >> w;
    rep(i,h)rep(j,w){
        cin >> f[i][j];
        if(f[i][j] == 's') pi = i, pj = j;
    }
    cin >> s;
}

int main()
{
    input();
    cout << solve() << endl;
    return 0;
}
