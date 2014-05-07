#include <cstdio>
#include <iostream>
using namespace std;
#define HOGE HOGE
#ifdef HOGE
void hoge(){cout << "hoge" << endl;}
#endif HOGE

int main(){
    hoge();
    cout << "test" << endl;
    return 0;
}
