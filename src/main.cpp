#include "life.h"
#include <string>

int main(int argc, char *argv[]) {
    int width = 0;
    int height = 0;
    bool toroid = true;
    int fps = 0;
    for (int i = 1; i < argc; i++) {
        if (((std::string)argv[i] == "-w" || (std::string)argv[i] == "--width") && i + 1 < argc) {
            try {
                width = atoi(argv[++i]);
            } catch(std::exception) {}
        }
        else if (((std::string)argv[i] == "-h" || (std::string)argv[i] == "--height") && i + 1 < argc) {
            try {
                height = atoi(argv[++i]);
            } catch(std::exception) {}
        }
        else if ((std::string)argv[i] == "-t" || (std::string)argv[i] == "--toroid") {
            toroid = true;
        }
        else if (((std::string)argv[i] == "-f" || (std::string)argv[i] == "--fps") && i + 1 < argc) {
            try {
                fps = atoi(argv[++i]);
            } catch(std::exception) {}
        }
    }
    Life life(width, height, toroid, fps);
    life.run();
    return 0;
}
