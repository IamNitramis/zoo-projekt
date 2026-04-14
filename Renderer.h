//
// Created by PC on 14.04.2026.
//

#ifndef PROJEKT_ZOO_RENDERER_H
#define PROJEKT_ZOO_RENDERER_H

#include <vector>
#include <string>

class Renderer {
public:
    Renderer();
    void clearScreen() const;
    void drawMenu(const std::vector<std::string>& options, int selectedIndex) const;
};

#endif //PROJEKT_ZOO_RENDERER_H