#include <iostream>
#include <windows.h>

int consist[10][10];
int lastcons[10][10];
int changeMove = 0;
int x = 4;
int y = 4;
int score = 0;
int speed = 1000;
boolean live = true;

void copy() {
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            lastcons[i][j] = consist[i][j];
}

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
    std::cout << "score: " << score << std::endl;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; j++)
            std::cout << consist[i][j] << ' ';
        std::cout << '\n';
    }
    std::cout << '\n';

}
void printLast(){
     for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; j++)
            std::cout << lastcons[i][j] << ' ';
        std::cout << '\n';
    }
    std::cout << '\n';
}

void death() {
    if (y >= 10 || x >= 10 || y < 0 || x < 0)
        live = false;

   if (lastcons[y][x] == 5)
       live = false;


}

void newApple() {
    ++score;
    speed -= 10;
    int newX = rand() % 9 + 0;
    int newY = rand() % 9 + 0;
    while (consist[newY][newX] == 5) {
        newX = rand() % 9 + 0;
        newY = rand() % 9 + 0;
    }
    consist[newY][newX] = 4;
}

void move() {

    if (changeMove == 0) {
        if (consist[y][x + 1] == 4) {
            newApple();
        } else { consist[y][x] = 0; }
        consist[y][++x] = 5;

    }
    if (changeMove == 1) {
        if (consist[y + 1][x] == 4) {
            newApple();
        } else { consist[y][x] = 0; }
        consist[++y][x] = 5;
        consist[y - 1][x] = 0;
    }
    if (changeMove == 2) {
        if (consist[y][x] == 4) {
            newApple();
        } else { consist[y][x] = 0; }
        consist[y][--x] = 5;
        consist[y][x + 1] = 0;
    }
    if (changeMove == 3) {
        if (consist[y - 1][x] == 4) {
            newApple();
        } else { consist[y][x] = 0; }
        consist[--y][x] = 5;
        consist[y + 1][x] = 0;
    }
    death();
    copy();
    if (live) {
        //printLast();
        printState();
    }
}

void getStateKey() {
    do {
        Sleep(speed);
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

    }
    return 0;
}