//
// Created by Radek on 28.04.2026.
//

#include "Module.h"

#include <iostream>
#include <ostream>

#include "Hatch.h"

Module::Module(Position position) {
    m_position = position;
}

// Protože je to kompozice je nutno vymazat všechny dveře po tom co zanikne modul
Module::~Module() {
    for (Hatch * hatch : m_hatches) {
        delete hatch;
    }

    m_hatches.clear();
}

Position Module::getPosition() {
    return m_position;
}

// Přidá do modulu dveře
void Module::addHatch(Hatch *hatch) {
    if (hatch == nullptr) {
        return;
    }

    m_hatches.push_back(hatch);
}

std::vector<Hatch *> Module::getHatches() {
    return m_hatches;
}
