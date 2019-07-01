#include "life.h"
#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

Life::Life(int width, int height, bool toroid, int fps) {
    if (width == 0) {
        width = 100;
    }
    if (height == 0) {
        height = 75;
    }
    w = width;
    h = height;
    toroidal = toroid;
    board.resize(w, std::vector<int>(h));
    neighbors.resize(w, std::vector<int>(h));
    screen.create(w, h, fps);
    screen.fill(0, 0, 0);
    srand(time(NULL));
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            board[i][j] = rand() % 2; // random board
            // board[i][j] = 0; // empty board
        }
    }
    // glider:
    // board[0][0] = board[2][0] = board[1][1] = board[1][2] = board[2][1] = 1;
    // glider gun:
    // board[1][5] = board[1][6] = board[2][5] = board[2][6] = board[11][5] = board[11][6] = board[11][7] = board[12][4] = board[12][8] = board[13][3] = board[13][9] = board[14][3] = board[14][9] = board[15][6] = board[16][4] = board[16][8] = board[17][5] = board[17][6] = board[17][7] = board[18][6] = board[21][3] = board[21][4] = board[21][5] = board[22][3] = board[22][4] = board[22][5] = board[23][2] = board[23][6] = board[25][1] = board[25][2] = board[25][6] = board[25][7] = board[35][3] = board[35][4] = board[36][3] = board[36][4] = 1;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            neighbors[i][j] = numNeighbors(board, i, j);
        }
    }
}

std::vector< std::vector<int> > Life::clone(std::vector< std::vector<int> > b) {
    std::vector< std::vector<int> > newboard;
    for (unsigned int i = 0; i < b.size(); i++) {
        std::vector<int> newrow;
        for (unsigned int j = 0; j < b[i].size(); j++) {
            newrow.push_back(b[i][j]);
        }
        newboard.push_back(newrow);
    }
    return newboard;
}

int Life::numNeighbors(std::vector< std::vector<int> > b, int x, int y) {
    int neighbors = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i != x || j != y) {
                if (toroidal) {
                    if (b[(i + w) % w][(j + h) % h] == 1) {
                        neighbors++;
                    }
                }
                else {
                    if (i >= 0 && i < w && j >= 0 && j < h && b[i][j] == 1) {
                        neighbors++;
                    }
                }
            }
        }
    }
    return neighbors;
}

void Life::incNeighbors(int x, int y) {
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i != x || j != y) {
                if (toroidal) {
                    neighbors[(i + w) % w][(j + h) % h]++;
                }
                else if (i >= 0 && i < w && j >= 0 && j < h) {
                    neighbors[i][j]++;
                }
            }
        }
    }
}

void Life::decNeighbors(int x, int y) {
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i != x || j != y) {
                if (toroidal) {
                    neighbors[(i + w) % w][(j + h) % h]--;
                }
                else if (i >= 0 && i < w && j >= 0 && j < h) {
                    neighbors[i][j]--;
                }
            }
        }
    }
}

void Life::next() {
    std::vector< std::vector<int> > oldneighbors = clone(neighbors);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if ((oldneighbors[i][j] < 2 || oldneighbors[i][j] > 3) && board[i][j] == 1) {
                board[i][j] = 0;
                decNeighbors(i, j);
            }
            else if (oldneighbors[i][j] == 3 && board[i][j] == 0) {
                board[i][j] = 1;
                incNeighbors(i, j);
            }
        }
    }
}

void Life::display() {
    screen.fill(0, 0, 0);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (board[i][j] == 1) {
                screen.draw(i, j, 255, 255, 255);
            }
        }
    }
    screen.update();
}

void Life::run() {
    while (screen.isOpen()) {
        display();
        next();
    }
}
