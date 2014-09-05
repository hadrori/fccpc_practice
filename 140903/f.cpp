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

const int H = 19;
const int W = 15;
char f[32][32];
void input() {
    rep(i, H) rep(j, W) cin >> f[i][j];
}

int num[32][32];

void numbering() {
    int cnt = 0;
    rep(i, H) rep(j, W) if(f[i][j] == 'X') {
        num[j][i] = cnt++;
    }
}

bool inrange(int x, int y) {
    return x >= 0 and y >= 0 and x < W and y < H;
}

void solve() {
    // init
    queue<pair<pair<int, int> , pair<int, int> > > q;
    rep(i, H) rep(j, W) {
        if(f[i][j] == 'O') q.push(mp(mp(0, 0), mp(j, i)));
    }

    // BFS
    const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
    const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
    set<pair<int, pair<int, int> > >done;
    int ans = -1;
    while(q.size()) {
        int used = q.front().first.first;
        int step = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second; q.pop();

        // cut
        pair<int, pair<int, int> > key = mp(used, mp(x, y));
        if(done.find(key) != done.end()) continue;
        done.insert(key);

        // end
        if((y == H-1 and inrange(x, y)) or y == H) {
            ans = step;
            break;
        }

        // invalid
        if(!inrange(x, y)) {
            continue;
        }

        // next step
        rep(dir, 8) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(!inrange(nx, ny) or f[ny][nx] != 'X' or ((used>>num[nx][ny])&1)) continue;
            int nused = used;
            while(inrange(nx, ny) and f[ny][nx] == 'X' and !((used>>num[nx][ny])&1)) {
                nused |= 1<<num[nx][ny];
                nx += dx[dir];
                ny += dy[dir];
            }
            q.push(mp(mp(nused, step+1), mp(nx, ny)));
        }
    }
    cout << ans << endl;
}

int main()
{
    input();
    numbering();
    solve();
    
    return 0;
}
