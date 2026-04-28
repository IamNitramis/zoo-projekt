//
// Created by Radek on 28.04.2026.
//

#include "Hatch.h"
#include "Module.h"



Hatch::Hatch(Module *moduleFrom, bool isLocked, HatchDirection hatchDirection) {
    m_moduleFrom = moduleFrom;
    m_moduleTo = nullptr;
    m_isLocked = isLocked;
    m_hatchDirection = hatchDirection;
}

Hatch::~Hatch() {

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

Module * Hatch::getFromModule() {
    return m_moduleFrom;
}

HatchDirection Hatch::getHatchDirection() {
    return m_hatchDirection;
}

bool Hatch::isLocked() {
    return m_isLocked;
}

void Hatch::unlock() {
    m_isLocked = false;
}
