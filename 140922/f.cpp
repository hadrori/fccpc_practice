#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)

const int N = 600010;

int n, k;
int rnk[N], tmp[N], sa[N], lcp[N];

bool compare_sa(int i, int j)
{
    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
    else {
        int ri = i + k <= n ? rnk[i+k] : -1;
        int rj = j + k <= n ? rnk[j+k] : -1;
        return ri < rj;
    }
}

void construct_sa(char *S) {
    for (int i = 0; i <= n; i++) {
        sa[i] = i;
        rnk[i] = i < n ? S[i] : -1;
    }
    for (k = 1; k <= n; k *= 2) {
        sort(sa, sa+n+1, compare_sa);
        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; i++) {
            tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i <= n; i++) {
            rnk[i] = tmp[i];
        }
    }
}

void construct_lcp(char *S) {
    for (int i = 0; i <= n; i++) rnk[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
        int j = sa[rnk[i] - 1];
        if (h > 0) h--;
        for (; j + h < n && i + h < n; h++) {
            if (S[j+h] != S[i+h]) break;
        }
        lcp[rnk[i] - 1] = h;
    }
}

int m;
char combined[N];
int x_ind[100010], y_ind[100010];

const int K = 20;

int min_sa[K][N], max_sa[K][N];

void construct_min_st(int (*st)[N], int* a)
{
    rep(i, K - 1) rep(j, n - (1 << i) + 1) {
        st[i + 1][j] = min(st[i][j], st[i][j + (1 << i)]);
    }
}

void construct_max_st(int (*st)[N], int* a)
{
    rep(i, K - 1) rep(j, n - (1 << i) + 1) {
        st[i + 1][j] = max(st[i][j], st[i][j + (1 << i)]);
    }
}

const int inf = 1e9;

int s_len;

void prepare_st()
{
    rep(i, n + 1) {
        // min_sa[0][i] = sa[i] < s_len ? sa[i] : inf;
        max_sa[0][i] = sa[i] < s_len ? sa[i] : -inf;
        min_sa[0][i] = lcp[i];
    }
}

void input()
{
    char *p = combined;
    scanf("%s", p), p += s_len = strlen(p);
    *p++ = '$';
    scanf("%d", &m);
    rep(i, m) {
        x_ind[i] = p - combined;
        scanf("%s", p), p += strlen(p);
        *p++ = ' ';
        y_ind[i] = p - combined;
        scanf("%s", p), p += strlen(p);
        *p++ = ' ';
    }
    *--p = '\0';
    n = p - combined;
}

int min_st(int (*st)[N], int l, int r)
{
    const int sz = 31 - __builtin_clz(r - l);
    return min(st[sz][l], st[sz][r - (1 << sz)]);
}

int max_st(int (*st)[N], int l, int r)
{
    const int sz = 31 - __builtin_clz(r - l);
    return max(st[sz][l], st[sz][r - (1 << sz)]);
}

void prepare()
{
    construct_sa(combined);
    construct_lcp(combined);
    prepare_st();
    // construct_min_st(min_sa, sa);
    construct_max_st(max_sa, sa);
    construct_min_st(min_sa, lcp);
    /*
    cerr << n << ' ' << combined << endl;
    rep(i, m) {
        cerr << x_ind[i] << ' ' << y_ind[i] << endl;
    }
    */
}

int x_len[100010], y_len[100010];
int x_query[100010], y_query[100010];

void find_min(int i)
{
    const int id = rnk[x_ind[i]];
    {
        int pos = x_ind[i];
        while (pos < n and isalpha(combined[pos])) {
            ++pos;
        }
        x_len[i] = pos - x_ind[i];
    }
    if (lcp[id] < x_len[i]) {
        x_query[i] = -1;
        return;
    }
    int l = id, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (min_st(min_sa, l, m) >= x_len[i]) {
            l = m;
        } else {
            r = m;
        }
    }
    // return min_st(min_sa, id, l + 1);
    x_query[i] = l + 1;
}

#define dump(x) (cerr<<#x<<" = "<<(x)<<endl)

void find_max(int i)
{
    const int id = rnk[y_ind[i]];
    {
        int pos = y_ind[i];
        while (pos < n and isalpha(combined[pos])) {
            ++pos;
        }
        y_len[i] = pos - y_ind[i];
    }
    if (lcp[id] < y_len[i]) {
        y_query[i] = -1;
        return;
    }
    int l = id, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (min_st(min_sa, l, m) >= y_len[i]) {
            l = m;
        } else {
            r = m;
        }
    }
    // return max_st(max_sa, id, l + 1);
    y_query[i] = l + 1;
}

void solve()
{
    prepare();
    rep(i, m) {
        /*
        const int mn = find_min(i);
        const int mx = find_max(i);
        */
        find_min(i);
        find_max(i);
    }
    rep(i, n + 1) min_sa[0][i] = sa[i] < s_len ? sa[i] : inf;
    construct_min_st(min_sa, sa);
    rep(i, m) {
        if (x_query[i] < 0 or y_query[i] < 0) {
            puts("0");
            continue;
        }
        const int mn = min_st(min_sa, rnk[x_ind[i]], x_query[i]);
        const int mx = max_st(max_sa, rnk[y_ind[i]], y_query[i]);
        if (mn <= mx and mn + x_len[i] <= mx + y_len[i]) {
            const int ans = mx + y_len[i] - mn;
            printf("%d\n", ans);
        } else {
            puts("0");
        }
    }
}

int main()
{
    input();
    solve();

    return 0;
}
