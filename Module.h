//
// Created by Radek on 28.04.2026.
//

#ifndef PROJEKT_ZOO_MODULE_H
#define PROJEKT_ZOO_MODULE_H

class Hatch;

#include <vector>

class Module {
    int m_positionX;
    int m_positionY;
    std::vector<Hatch *> m_hatches;
    const int m_MODULESIZE = 7;
public:
    Module(int positionX, int positionY);
    ~Module();
    int getPositionX();
    int getPositionY();
    void addHatch(Hatch *hatch);
    std::vector<Hatch *> getHatches();
};


#endif //PROJEKT_ZOO_MODULE_H