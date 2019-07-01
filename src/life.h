#ifndef LIFE_H
#define LIFE_H

#include "display.h"
#include <vector>

class Life {
    private:
        int w;
        int h;
        bool toroidal;
        std::vector< std::vector<int> > board;
        std::vector< std::vector<int> > neighbors;
        Display screen;
        int numNeighbors(std::vector< std::vector<int> > b, int x, int y);
        std::vector< std::vector<int> > clone(std::vector< std::vector<int> > b);
        void incNeighbors(int x, int y);
        void decNeighbors(int x, int y);

    public:
        Life(int width, int height, bool toroid, int fps);
        void next();
        void display();
        void run();
};

#endif
