#include <iostream>
#include <windows.h>

int consist[10][10];

void makeNULL() {
    for (auto &i: consist)
        for (int &j: i)
            j = 0;
    consist[4][4] = 5;
    consist[4][7] = 4;
}
void getStateKey() {
    do {
        if (GetAsyncKeyState(VK_LEFT)) {
            keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);

        }

        if (GetAsyncKeyState(VK_RIGHT)) {
            keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);

        }

        if (GetAsyncKeyState(VK_DOWN)) {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);

        }

        if (GetAsyncKeyState(VK_UP)) {
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);

        }
    }while(!GetAsyncKeyState(VK_LEFT)&&!GetAsyncKeyState(VK_RIGHT)&&!GetAsyncKeyState(VK_DOWN)&&!GetAsyncKeyState(VK_UP));
}
void printState(){
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; j++)
            std::cout << consist[i][j] << ' ';
        std::cout<<'\n';
    }
    std::cout<<'\n';
}
int main() {
    makeNULL();
    while (true) {
        getStateKey();
        printState();
    }
    return 0;
}