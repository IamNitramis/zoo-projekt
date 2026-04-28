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

// Přidá modul do stationu
void Station::addModule(Module *module) {
    if (module == nullptr) {
        return;
    }

    m_modules.push_back(module);
    Position position = module->getPosition();
    m_mapGrid[position.x][position.y] = module;
}

// Vrátí první prvek tedy "airlock"
Module * Station::getStartModule() {
    if (m_modules.empty()) {
        return nullptr;
    }

    return m_modules.at(0);
}

// Vrácení modulu na pozici, kontrola velikosti mapy
Module * Station::getModuleAt(Position position) {
    if (position.x < 0 or position.x >= m_mapGrid.size() or
        position.y < 0 or position.y >= m_mapGrid[0].size()) {
            return nullptr;
        }

    return m_mapGrid[position.x][position.y];
}


// Kontrola zda je místo volné, kontrola velikosti mapy
bool Station::isSpaceFree(Position position) {
    if (position.x < 0 or position.x >= m_mapGrid.size() or
        position.y < 0 or position.y >= m_mapGrid[0].size()) {
            return false;
        }

    return m_mapGrid[position.x][position.y] == nullptr;
}
