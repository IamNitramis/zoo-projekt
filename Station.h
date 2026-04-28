//
// Created by Radek on 28.04.2026.
//

#ifndef PROJEKT_ZOO_STATION_H
#define PROJEKT_ZOO_STATION_H

#include <vector>

#include "Position.h"

class Module;

class Station {
    std::vector<Module*> m_modules;
    std::vector<std::vector<Module*>> m_mapGrid;

public:
    Station(int mapWidth, int mapHeight);
    ~Station();
    void addModule(Module * module);
    Module * getStartModule();
    Module * getModuleAt(Position position);
    bool isSpaceFree(Position position);
};


#endif //PROJEKT_ZOO_STATION_H