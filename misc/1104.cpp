#include <iostream>
#include <vector>
#include <string>

#define rep(i,a) for(int i = 0; i < a; i++)

using namespace std;

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int main(){
    int w, h;
    while(cin >> w >> h, w || h){
        string command;
        int dir = 0;//n e s w
        int x = 0, y = 0;
        while(cin >> command, command != "STOP"){
            if(command == "RIGHT"){
                ++dir %= 4;
            }else if(command == "LEFT"){
                --dir;
                if(dir < 0) dir = 3;
            }
            else if(command == "FORWARD"){
                int d;
                cin >> d;
                x += dx[dir] * d;
                if(x >= w) x = w - 1;
                else if(x < 0) x = 0;
                y += dy[dir] * d;
                if(y >= h) y = h - 1;
                else if(y < 0) y = 0;
            }
            else if(command == "BACKWARD"){
                int d;
                cin >> d;
                x -= dx[dir] * d;
                if(x >= w) x = w - 1;
                else if(x < 0) x = 0;
                y -= dy[dir] * d;
                if(y >= h) y = h - 1;
                else if(y < 0) y = 0;
            }
        }

        cout << x + 1 << ' ' << y + 1 << endl;
    }
}
