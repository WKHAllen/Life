#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>

class Display {
    private:
        int w;
        int h;
        int cellSize;

    public:
        sf::RenderWindow window;
        void create(int width, int height, int fps);
        void fill(int r, int g, int b);
        void draw(int x, int y, int r, int g, int b);
        void update();
        bool isOpen();
};

#endif
