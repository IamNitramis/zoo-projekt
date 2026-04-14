#include <iostream>
#include "Menu.h"
#include "Renderer.h"

int main() {
    Renderer renderer;
    Menu mainMenu;

    int choice = mainMenu.run(renderer);

    renderer.clearScreen();
    std::cout << "Selected option index: " << choice << "\n";

    return 0;
}