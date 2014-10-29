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

typedef long long ll;
int n;
const int MAX = 24;
struct node {
    string a;
    char step;

    bool same(int i1, int i2, int i3, int i4) {
        return a[i1] == a[i2] and a[i2] == a[i3] and a[i3] == a[i4] and a[i4] == a[i1];
    }

    void swap4(int i1, int i2, int i3, int i4) {
        swap(a[i1], a[i2]);
        swap(a[i2], a[i3]);
        swap(a[i3], a[i4]);
    }

    void swap4b(int i1, int i2, int i3, int i4) {
        swap(a[i4], a[i3]);
        swap(a[i3], a[i2]);
        swap(a[i2], a[i1]);
    }

    void swap8(int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8) {
        swap4(i1, i3, i5, i7);
        swap4(i2, i4, i6, i8);
    }

    void swap8b(int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8) {
        swap4b(i1, i3, i5, i7);
        swap4b(i2, i4, i6, i8);
    }

    
    int count() {
        int ret = 0;
        if(same(0, 1, 2, 3)) ret++;
        if(same(4, 5,10,11)) ret++;
        if(same(6, 7,12,13)) ret++;
        if(same(8, 9,14,15)) ret++;
        if(same(16,17,18,19)) ret++;
        if(same(20,21,22,23)) ret++;
        return ret;
    }

    void move(int k) {
        if(k == 0) {
            swap8(0, 1, 9,15,19,18,10,4);
            swap4(20,22,23,21);
        } else if(k == 1) {
            swap8(4, 5, 6, 7, 8, 9,23,22);
            swap4(1, 0, 2, 3);
        } else if(k == 2) {
            swap8(23,21,19,17,13,7, 3, 1);
            swap4(8, 9,15,14);
        } else if(k == 3) {
            swap8b(0, 1, 9,15,19,18,10,4);
            swap4b(20,22,23,21);
        } else if(k == 4) {
            swap8b(4, 5, 6, 7, 8, 9,23,22);
            swap4b(1, 0, 2, 3);
        } else if(k == 5) {
            swap8b(23,21,19,17,13,7, 3, 1);
            swap4b(8, 9,15,14);
        }
        
    }
};

int solve() {
    const int N = 24;
    string a;
    rep(i, N) {
        char c;
        cin >> c;
        a += c;
    }
    
    queue<node> q;
    set<string> done;
    q.push(node{a, 0});
    int ans = 0;
    while(q.size()) {
        node now = q.front(); q.pop();
        if(now.step > n) continue;
        if(done.find(now.a) != done.end()) continue;
        done.insert(now.a);
        int cnt = now.count();
        ans = max(ans, cnt);
        if(cnt + (n-now.step)*3 <= ans) continue;
        if(ans == 6) return ans;
        
        rep(k, 6) {
            node nxt = now;
            nxt.move(k);
            nxt.step++;
            if(nxt.step <= n) q.push(nxt);
        }
    }
    return ans;
}

int main()
{
    while(cin >> n) cout << solve() << endl;
    
    return 0;
}
