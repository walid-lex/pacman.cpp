#include <iostream>
using namespace std;

const int rows = 9;
const int columns = 12;

const char wall = '#';
const char emptySpace = ' ';
const char pacMan = '@';

void drawMap(char pacmanMap[rows][columns]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 12; ++j) {
            std::cout << pacmanMap[i][j];
        }
        std::cout << std::endl;
    }
}

void movePacman(char pacmanMap[rows][columns], int &x, int &y, int pacmanDirection) {
    if (pacmanDirection == 2) {
        if (pacmanMap[y + 1][x] != wall) {
            pacmanMap[y][x] = emptySpace;
            pacmanMap[y + 1][x] = pacMan;
            y++;
        }
    }
    if (pacmanDirection == 3) {
        if (pacmanMap[y - 1][x] != wall) {
            pacmanMap[y][x] = emptySpace;
            pacmanMap[y - 1][x] = pacMan;
            y--;
        }
    }
    if (pacmanDirection == 0) {
        if (pacmanMap[y][x + 1] != wall) {
            pacmanMap[y][x] = emptySpace;
            pacmanMap[y][x + 1] = pacMan;
            x++;
        }
    }
    if (pacmanDirection == 1) {
        if (pacmanMap[y][x - 1] != wall) {
            pacmanMap[y][x] = emptySpace;
            pacmanMap[y][x - 1] = pacMan;
            x--;
        }
    }
}

int main() {
    char pacmanMap[rows][columns] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int pacmanX = 1;
    int pacmanY = 1;
    int pacmanDirection = 0;

    movePacman(pacmanMap, pacmanX, pacmanY, pacmanDirection);
    drawMap(pacmanMap);

    return 0;
}
