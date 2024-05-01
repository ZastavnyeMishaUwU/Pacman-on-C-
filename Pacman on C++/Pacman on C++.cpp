#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <cmath>

using namespace std;

bool gameOver;
const int width = 42, height = 11;
int x, y, score;
int ghostX, ghostY;
int ghost2X, ghost2Y;
int ghost3X, ghost3Y;
int ghost4X, ghost4Y;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
char arr[height][width];

void Setup() {
    gameOver = false;
    x = 21;
    y = 9;
    score = 0;
    ghostX = 18;
    ghostY = 3;
    ghost2X = 20;
    ghost2Y = 3;
    ghost3X = 22;
    ghost3Y = 3;
    ghost4X = 24;
    ghost4Y = 3;
    dir = STOP;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
                arr[i][j] = '#';
            else
                arr[i][j] = ' ';
        }
    }
}

void Draw() {
    system("cls");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 2 && j == 4 ||
                i == 2 && j == 5 ||
                i == 2 && j == 6 ||


                i == 3 && j == 4 ||
                i == 4 && j == 4 ||

                i == 6 && j == 4 ||
                i == 7 && j == 4 ||

                i == 8 && j == 4 ||
                i == 8 && j == 5 ||
                i == 8 && j == 6 ||

                i == 1 && j == 11 ||
                i == 2 && j == 11 ||

                i == 4 && j == 9 ||
                i == 4 && j == 10 ||
                i == 4 && j == 11 ||


                i == 8 && j == 11 ||
                i == 9 && j == 11 ||

                i == 6 && j == 9 ||
                i == 6 && j == 10 ||
                i == 6 && j == 11 ||




                i == 2 && j == 37 ||
                i == 2 && j == 36 ||
                i == 2 && j == 35 ||


                i == 3 && j == 37 ||
                i == 4 && j == 37 ||

                i == 6 && j == 37 ||
                i == 7 && j == 37 ||

                i == 8 && j == 37 ||
                i == 8 && j == 35 ||
                i == 8 && j == 36 ||

                i == 1 && j == 31 ||
                i == 2 && j == 31 ||

                i == 4 && j == 31 ||
                i == 4 && j == 32 ||
                i == 4 && j == 33 ||


                i == 8 && j == 31 ||
                i == 9 && j == 31 ||

                i == 6 && j == 31 ||
                i == 6 && j == 32 ||
                i == 6 && j == 33 ||


                i == 8 && j >= 16 && j <= 27 ||



                i == 2 && j >= 16 && j <= 27 ||
                i == 3 && j == 16 ||
                i == 4 && j == 16 ||
                i == 3 && j == 27 ||
                i == 4 && j == 27 ||
                i == 4 && j == 26 ||
                i == 4 && j == 17) {
                arr[i][j] = '#';
            }
            if (i == y && j == x)
                cout << 'O';
            else if (i == ghostY && j == ghostX)
                cout << 'X';
            else if (i == ghost2Y && j == ghost2X)
                cout << 'Y';
            else if (i == ghost3Y && j == ghost3X)
                cout << 'Z';
            else if (i == ghost4Y && j == ghost4X)
                cout << 'W';
            else
                cout << arr[i][j];
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    int prevX = x;
    int prevY = y;
    int prevGhostX = ghostX;
    int prevGhostY = ghostY;
    int prevGhost2X = ghost2X;
    int prevGhost2Y = ghost2Y;
    int prevGhost3X = ghost3X;
    int prevGhost3Y = ghost3Y;
    int prevGhost4X = ghost4X;
    int prevGhost4Y = ghost4Y;

    switch (dir) {
    case UP:
        if (arr[y - 1][x] != '#')
            y--;
        break;
    case DOWN:
        if (arr[y + 1][x] != '#')
            y++;
        break;
    case LEFT:
        if (arr[y][x - 1] != '#')
            x--;
        break;
    case RIGHT:
        if (arr[y][x + 1] != '#')
            x++;
        break;
    }

    if (abs(x - ghostX) + abs(y - ghostY) <= 3) {
        if (x < ghostX && arr[ghostY][ghostX - 1] != '#')
            ghostX--;
        else if (x > ghostX && arr[ghostY][ghostX + 1] != '#')
            ghostX++;
        else if (y < ghostY && arr[ghostY - 1][ghostX] != '#')
            ghostY--;
        else if (y > ghostY && arr[ghostY + 1][ghostX] != '#')
            ghostY++;
    }
    else {
        int randomDirection = rand() % 4;
        switch (randomDirection) {
        case 0:
            if (ghostY > 0 && arr[ghostY - 1][ghostX] != '#')
                ghostY--;
            break;
        case 1:
            if (ghostY < height - 1 && arr[ghostY + 1][ghostX] != '#')
                ghostY++;
            break;
        case 2:
            if (ghostX > 0 && arr[ghostY][ghostX - 1] != '#')
                ghostX--;
            break;
        case 3:
            if (ghostX < width - 1 && arr[ghostY][ghostX + 1] != '#')
                ghostX++;
            break;
        }
    }

    if (abs(x - ghost2X) + abs(y - ghost2Y) <= 3) {
        if (x < ghost2X && arr[ghost2Y][ghost2X - 1] != '#')
            ghost2X--;
        else if (x > ghost2X && arr[ghost2Y][ghost2X + 1] != '#')
            ghost2X++;
        else if (y < ghost2Y && arr[ghost2Y - 1][ghost2X] != '#')
            ghost2Y--;
        else if (y > ghost2Y && arr[ghost2Y + 1][ghost2X] != '#')
            ghost2Y++;
    }
    else {
        int randomDirection = rand() % 4;
        switch (randomDirection) {
        case 0:
            if (ghost2Y > 0 && arr[ghost2Y - 1][ghost2X] != '#')
                ghost2Y--;
            break;
        case 1:
            if (ghost2Y < height - 1 && arr[ghost2Y + 1][ghost2X] != '#')
                ghost2Y++;
            break;
        case 2:
            if (ghost2X > 0 && arr[ghost2Y][ghost2X - 1] != '#')
                ghost2X--;
            break;
        case 3:
            if (ghost2X < width - 1 && arr[ghost2Y][ghost2X + 1] != '#')
                ghost2X++;
            break;
        }
    }

    if (abs(x - ghost3X) + abs(y - ghost3Y) <= 3) {
        if (x < ghost3X && arr[ghost3Y][ghost3X - 1] != '#')
            ghost3X--;
        else if (x > ghost3X && arr[ghost3Y][ghost3X + 1] != '#')
            ghost3X++;
        else if (y < ghost3Y && arr[ghost3Y - 1][ghost3X] != '#')
            ghost3Y--;
        else if (y > ghost3Y && arr[ghost3Y + 1][ghost3X] != '#')
            ghost3Y++;
    }
    else {
        int randomDirection = rand() % 4;
        switch (randomDirection) {
        case 0:
            if (ghost3Y > 0 && arr[ghost3Y - 1][ghost3X] != '#')
                ghost3Y--;
            break;
        case 1:
            if (ghost3Y < height - 1 && arr[ghost3Y + 1][ghost3X] != '#')
                ghost3Y++;
            break;
        case 2:
            if (ghost3X > 0 && arr[ghost3Y][ghost3X - 1] != '#')
                ghost3X--;
            break;
        case 3:
            if (ghost3X < width - 1 && arr[ghost3Y][ghost3X + 1] != '#')
                ghost3X++;
            break;
        }
    }

    if (abs(x - ghost4X) + abs(y - ghost4Y) <= 3) {
        if (x < ghost4X && arr[ghost4Y][ghost4X - 1] != '#')
            ghost4X--;
        else if (x > ghost4X && arr[ghost4Y][ghost4X + 1] != '#')
            ghost4X++;
        else if (y < ghost4Y && arr[ghost4Y - 1][ghost4X] != '#')
            ghost4Y--;
        else if (y > ghost4Y && arr[ghost4Y + 1][ghost4X] != '#')
            ghost4Y++;
    }
    else {
        int randomDirection = rand() % 4;
        switch (randomDirection) {
        case 0:
            if (ghost4Y > 0 && arr[ghost4Y - 1][ghost4X] != '#')
                ghost4Y--;
            break;
        case 1:
            if (ghost4Y < height - 1 && arr[ghost4Y + 1][ghost4X] != '#')
                ghost4Y++;
            break;
        case 2:
            if (ghost4X > 0 && arr[ghost4Y][ghost4X - 1] != '#')
                ghost4X--;
            break;
        case 3:
            if (ghost4X < width - 1 && arr[ghost4Y][ghost4X + 1] != '#')
                ghost4X++;
            break;
        }
    }

    if (x == ghostX && y == ghostY) {
        gameOver = true;
        cout << "Game over " << endl;
    }

    if (x == ghost2X && y == ghost2Y) {
        gameOver = true;
        cout << "Game over " << endl;
    }

    if (x == ghost3X && y == ghost3Y) {
        gameOver = true;
        cout << "Game over " << endl;
    }

    if (x == ghost4X && y == ghost4Y) {
        gameOver = true;
        cout << "Game over " << endl;
    }

    if (x < 0 || x >= width || y < 0 || y >= height) {
        gameOver = true;
        cout << "Game over " << endl;
    }

    if (arr[y][x] == '#') {
        x = prevX;
        y = prevY;
    }

    if (arr[ghostY][ghostX] == '#') {
        ghostX = prevGhostX;
        ghostY = prevGhostY;
    }

    if (arr[ghost2Y][ghost2X] == '#') {
        ghost2X = prevGhost2X;
        ghost2Y = prevGhost2Y;
    }

    if (arr[ghost3Y][ghost3X] == '#') {
        ghost3X = prevGhost3X;
        ghost3Y = prevGhost3Y;
    }

    if (arr[ghost4Y][ghost4X] == '#') {
        ghost4X = prevGhost4X;
        ghost4Y = prevGhost4Y;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(200);
    }
    return 0;
}
