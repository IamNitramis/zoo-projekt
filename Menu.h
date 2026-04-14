//
// Created by PC on 14.04.2026.
//

#ifndef PROJEKT_ZOO_MENU_H
#define PROJEKT_ZOO_MENU_H

#include <vector>
#include <string>
#include "Renderer.h"

class Menu {
private:
    std::vector<std::string> options;
    int selectedIndex;

    void initializeOptions();

public:
    Menu();

    void moveUp();
    void moveDown();
    int run(const Renderer& renderer);
};
#endif //PROJEKT_ZOO_MENU_H