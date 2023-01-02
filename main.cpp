#include <iostream>
#include <windows.h>

int consist[10][10];
int changeMove = 0;
int x = 4;
int y = 4;
boolean live = true;

void clearScreen() {
    int n;
    for (n = 0; n < 10; n++)
        printf("\n\n\n\n\n\n\n\n\n\n");
}

void makeNULL() {
    for (auto &i: consist)
        for (int &j: i)
            j = 0;
    consist[4][4] = 5;
    consist[4][7] = 4;
}

void printState() {
    clearScreen();
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; j++)
            std::cout << consist[i][j] << ' ';
        std::cout << '\n';
    }
    std::cout << '\n';

}

void death() {
    if (y >= 10 || x >= 10 || y < 0 || x < 0) {
        live = false;
    }
}

void move() {
    if (changeMove == 0) {
        consist[y][++x] = 5;
        consist[y][x - 1] = 0;
    }
    if (changeMove == 1) {
        consist[++y][x] = 5;
        consist[y - 1][x] = 0;
    }
    if (changeMove == 2) {
        consist[y][--x] = 5;
        consist[y][x + 1] = 0;
    }
    if (changeMove == 3) {
        consist[--y][x] = 5;
        consist[y + 1][x] = 0;
    }
    death();
    if (live) {
        printState();
    }
}

void getStateKey() {
    do {
        Sleep(1000);
        if (GetAsyncKeyState(VK_LEFT)) {
            keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
            if (changeMove != 0)
                changeMove = 2;
        }

        if (GetAsyncKeyState(VK_RIGHT)) {
            keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
            if (changeMove != 2)
                changeMove = 0;
        }

        if (GetAsyncKeyState(VK_DOWN)) {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
            if (changeMove != 3)
                changeMove = 1;

        }

        if (GetAsyncKeyState(VK_UP)) {
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
            if (changeMove != 1)
                changeMove = 3;

        }

        move();

    } while (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_DOWN) &&
             !GetAsyncKeyState(VK_UP) && live);
    move();
}


int main() {
    makeNULL();
    while (live) {
        getStateKey();
        printState();
        move();
    }
    return 0;
}