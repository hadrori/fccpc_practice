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

map<int, int> narrow, wide, wide_erased;

void init()
{
    narrow.clear();
    wide.clear();
    wide_erased.clear();
}

bool beat(int px, int py, char type, int x, int y)
{
    const int c = type == 'N' ? 2 : 1;
    return (py - y) >= c * abs(px - x);
}

bool chk(map<int, int>& mp, int x, int y, char type)
{
    map<int, int>::iterator it = mp.lower_bound(x);
    if (it != mp.end() and beat(it->first, it->second, type, x, y)) {
        return false;
    }
    if (it == mp.begin()) return true;
    --it;
    if (beat(it->first, it->second, type, x, y)) {
        return false;
    }
    return true;
}

void modify(map<int, int>& mp, int x, int y, char type)
{
    {
        map<int, int>::iterator it = mp.lower_bound(x);
        if (it != mp.begin()) {
            --it;
            while (beat(x, y, type, it->first, it->second)) {
                if (it == mp.begin()) {
                    mp.erase(it);
                    break;
                }
                mp.erase(it--);
            }
        }
    }
    {
        map<int, int>::iterator it = mp.lower_bound(x);
        while (it != mp.end() and beat(x, y, type, it->first, it->second)) {
            mp.erase(it++);
        }
    }
}

void modify_nw(int x, int y)
{
    {
        map<int, int>::iterator it = wide.lower_bound(x);
        if (it != wide.begin()) {
            --it;
            while (beat(x, y, 'N', it->first, it->second)) {
                if (it == wide.begin()) {
                    modify(wide_erased, it->first, it->second, 'W');
                    wide_erased.insert(*it);
                    wide.erase(it);
                    break;
                }
                modify(wide_erased, it->first, it->second, 'W');
                wide_erased.insert(*it);
                wide.erase(it--);
            }
        }
    }
    {
        map<int, int>::iterator it = wide.lower_bound(x);
        while (it != wide.end() and beat(x, y, 'N', it->first, it->second)) {
            modify(wide_erased, it->first, it->second, 'W');
            wide_erased.insert(*it);
            wide.erase(it++);
        }
    }
}

void add(int x, int y, char type)
{
    if (not chk(narrow, x, y, 'N') or
        not chk(wide, x, y, 'W') or
        not chk(wide_erased, x, y, 'W')) {
        puts("FAIL");
        return;
    }
    modify(narrow, x, y, type);
    if (type == 'W') {
        modify(wide, x, y, type);
        modify(wide_erased, x, y, type);
    } else modify_nw(x, y);
    
    if (type == 'N') {
        narrow[x] = y;
    } else {
        wide[x] = y;
    }
    int ans = narrow.size() + wide.size();
    cout << ans << endl;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        int n;
        scanf("%d", &n);
        rep(_, n) {
            int x, y; char type;
            scanf("%d%d %c", &x, &y, &type);
            add(x, y, type);
        }
    }

    return 0;
}
