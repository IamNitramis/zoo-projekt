//
// Created by Radek on 28.04.2026.
//

#include "Module.h"

#include <iostream>
#include <ostream>

#include "Hatch.h"

Module::Module(int positionX, int positionY) {
    m_positionX = positionX;
    m_positionY = positionY;
}

// Protože je to kompozice je nutno vymazat všechny dveře po tom co zanikne modul
Module::~Module() {
    for (Hatch * hatch : m_hatches) {
        delete hatch;
    }

    m_hatches.clear();
}

int Module::getPositionX() {
    return m_positionX;
}

int Module::getPositionY() {
    return m_positionY;
}

// Přidá do modulu dveře
void Module::addHatch(Hatch *hatch) {
    if (hatch == nullptr) {
        std::cout << "Snazis se pridat prazdny {hatch}: " << hatch << std::endl;
        return;
    }

    m_hatches.push_back(hatch);
}

std::vector<Hatch *> Module::getHatches() {
    return m_hatches;
}
