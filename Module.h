//
// Created by Radek on 28.04.2026.
//

#ifndef PROJEKT_ZOO_MODULE_H
#define PROJEKT_ZOO_MODULE_H


#include <vector>

#include "Position.h"

class Hatch;

class Module {
    Position m_position;
    std::vector<Hatch *> m_hatches;
    const int m_MODULESIZE = 7;
public:
    Module(Position position);
    ~Module();
    Position getPosition();
    void addHatch(Hatch *hatch);
    std::vector<Hatch *> getHatches();
};


#endif //PROJEKT_ZOO_MODULE_H