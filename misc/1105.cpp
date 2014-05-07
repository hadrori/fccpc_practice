#include <cstring>
#include <iostream>
#include <vector>

#define rep(i,a) for(int i = 0; i < a; i++)

using namespace std;

const int N = 1000010;

int n, a, b;
int arr[N];

int solve() {
    memset(arr, 0, sizeof(arr));
    arr[0] = 1;

    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (i >= a)
            arr[i] |= arr[i - a];
        if (i >= b)
            arr[i] |= arr[i - b];
        if (arr[i] == 0)
            ++ret;
    }
    return ret;
}

int main(){
    while (cin >> n >> a >> b, n) {
        cout << solve() << endl;
    }
}
