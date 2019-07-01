#include "display.h"
#include <SFML/Graphics.hpp>

void Display::create(int width, int height, int fps) {
    w = width;
    h = height;
    cellSize = 8;
    window.create(sf::VideoMode(w * cellSize, h * cellSize), "Conway's Game of Life");
    if (fps != 0) {
        window.setFramerateLimit(fps);
    }
    else {
        window.setVerticalSyncEnabled(true);
    }
}

void Display::fill(int r, int g, int b) {
    window.clear(sf::Color(r, g, b));
}

void Display::draw(int x, int y, int r, int g, int b) {
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    cell.setPosition(sf::Vector2f(cellSize * x, cellSize * y));
    window.draw(cell);
}

void Display::update() {
    window.display();
}

bool Display::isOpen() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    return window.isOpen();
}
