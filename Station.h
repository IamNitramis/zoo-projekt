//
// Created by Radek on 28.04.2026.
//

#ifndef PROJEKT_ZOO_STATION_H
#define PROJEKT_ZOO_STATION_H

#include "Module.h"

#include <vector>

class Station {
    std::vector<Module*> m_modules;
    std::vector<std::vector<Module*>> m_mapGrid;

public:
    Station(int mapWidth, int mapHeight);
    ~Station();
    void addModule(Module * module);
    Module * getStartModule();
    Module * getModuleAt(int positionX, int positionY);
    bool isSpaceFree(int positionX, int positionY);
};


#endif //PROJEKT_ZOO_STATION_H