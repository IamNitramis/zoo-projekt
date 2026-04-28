//
// Created by Radek on 28.04.2026.
//

#include "Hatch.h"

#include <iostream>
#include <ostream>


Hatch::Hatch(int positionX, int positionY, Module *moduleFrom, bool isLocked) {
    m_positionX = positionX;
    m_positionY = positionY;
    m_moduleFrom = moduleFrom;
    m_moduleTo = nullptr;
    m_isLocked = isLocked;
}

Hatch::~Hatch() {

}

int Hatch::getPositionX() {
    return m_positionX;
}

int Hatch::getPositionY() {
    return m_positionY;
}

// Připojí modul, kterým se pokračuje
void Hatch::connectToModule(Module *moduleTo) {
    if (moduleTo == nullptr) {
        return;
    }

    m_moduleTo = moduleTo;
}

// Když hráč přijde ke dveřím, tak se dozví z jaké strany jde, *moduleFrom je vlastně směr, ze kterého jde hráč
Module * Hatch::getTargetModule(Module *moduleFrom) {
    if (moduleFrom == nullptr) {
        return nullptr;
    }

    if (moduleFrom == m_moduleFrom) {
        return m_moduleTo;
    }
    if (moduleFrom == m_moduleTo) {
        return m_moduleFrom;
    }

    return nullptr;
}

bool Hatch::isLocked() {
    return m_isLocked;
}

void Hatch::unlock() {
    m_isLocked = false;
}
