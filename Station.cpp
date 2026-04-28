//
// Created by Radek on 28.04.2026.
//

#include "Station.h"
#include "Module.h"

// Chytré nastavení velikosti a vyplnění gridu
Station::Station(int mapWidth, int mapHeight) {
    m_mapGrid.resize(mapWidth, std::vector<Module*>(mapHeight, nullptr));
}

Station::~Station() {
    for (Module * module : m_modules) {
        delete module;
    }

    m_modules.clear();
}

void Station::addModule(Module *module) {
    if (module == nullptr) {
        return;
    }

    m_modules.push_back(module);
}

// Vrátí první prvek tedy airlock
Module * Station::getStartModule() {
    if (m_modules.empty()) {
        return nullptr;
    }

    return m_modules.at(0);
}

// Vrácení modulu na pozici, kontrola velikosti mapy
Module * Station::getModuleAt(int positionX, int positionY) {
    if (positionX < 0 || positionX >= m_mapGrid.size() ||
        positionY < 0 || positionY >= m_mapGrid[0].size()) {

        return nullptr;
    }

    return m_mapGrid[positionX][positionY];
}

bool Station::isSpaceFree(int positionX, int positionY) {
    if (positionX < 0 || positionX >= m_mapGrid.size() ||
        positionY < 0 || positionY >= m_mapGrid[0].size()) {

        return false;
    }

    return m_mapGrid[positionX][positionY] == nullptr;
}
