//
// Created by PC on 14.04.2026.
//

#include "Menu.h"
#include "Input.h"

void Menu::initializeOptions() {
    options.clear();
    options.push_back("new game");
    options.push_back("load game");
    options.push_back("quit");
}

Menu::Menu() : selectedIndex(0) {
    initializeOptions();
}

void Menu::moveUp() {
    if (selectedIndex > 0) {
        selectedIndex--;
    }
}

void Menu::moveDown() {
    if (selectedIndex < options.size() - 1) {
        selectedIndex++;
    }
}

int Menu::run(const Renderer& renderer) {
    while (true) {
        renderer.clearScreen();
        renderer.drawMenu(options, selectedIndex);

        KeyCode key = Input::getKey();

        if (key == KeyCode::Up || key == KeyCode::W) {
            moveUp();
        }
        else if (key == KeyCode::Down || key == KeyCode::S) {
            moveDown();
        }
        else if (key == KeyCode::Enter || key == KeyCode::Space) {
            return selectedIndex;
        }
    }
}