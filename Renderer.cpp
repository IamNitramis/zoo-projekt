//
// Created by PC on 14.04.2026.
//

#include "Renderer.h"
#include <iostream>
#include <cstdlib>

Renderer::Renderer() {
    clearScreen();
}

void Renderer::clearScreen() const {
    system("cls");
}

void Renderer::drawMenu(const std::vector<std::string>& options, int selectedIndex) const {
    const int CONSOLE_WIDTH = 80;
    const int CONSOLE_HEIGHT = 24;
    const int MENU_WIDTH = 30;

    // Vertikalni centrování
    int menuHeight = 4 + options.size();
    int topPadding = (CONSOLE_HEIGHT - menuHeight) / 2;

    // Horizontalni centrování
    int leftPadding = (CONSOLE_WIDTH - MENU_WIDTH) / 2;
    std::string padding(leftPadding, ' ');

    // Padding na zacatku
    for (int i = 0; i < topPadding; ++i) {
        std::cout << "\n";
    }

    // Horni okraj
    std::cout << padding;
    for (int i = 0; i < MENU_WIDTH; ++i) std::cout << "=";
    std::cout << "\n";

    // Nadpis - centrovany v rámci menu width
    std::string title = "ZOO MENU";
    int titlePadding = (MENU_WIDTH - title.length()) / 2;
    std::cout << padding;
    for (int i = 0; i < titlePadding; ++i) std::cout << " ";
    std::cout << title;
    for (int i = 0; i < MENU_WIDTH - titlePadding - title.length(); ++i) std::cout << " ";
    std::cout << "\n";

    // Separator
    std::cout << padding;
    for (int i = 0; i < MENU_WIDTH; ++i) std::cout << "-";
    std::cout << "\n";

    // Menu polozky
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << padding;
        std::string line;
        if (i == selectedIndex) {
            line = ">>> " + options[i] + " <<<";
        } else {
            line = "    " + options[i];
        }

        // Zarovnani na MENU_WIDTH
        std::cout << line;
        for (int j = 0; j < MENU_WIDTH - line.length(); ++j) std::cout << " ";
        std::cout << "\n";
    }

    // Dolni okraj
    std::cout << padding;
    for (int i = 0; i < MENU_WIDTH; ++i) std::cout << "=";
    std::cout << "\n";
}