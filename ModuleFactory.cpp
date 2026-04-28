//
// Created by Radek on 28.04.2026.
//

#include "ModuleFactory.h"
#include "Module.h"
#include "Station.h"
#include "Hatch.h"

// Odkaz na station
ModuleFactory::ModuleFactory(Station *station) {
    if (station == nullptr) {
        return;
    }

    m_stationReference = station;
}

// Vytvoření a vrácení "airlocku" (prvního modulu)
Module * ModuleFactory::createStartingAirlock() {
    if (m_stationReference == nullptr) {
        return nullptr;
    }

    Module * airlock = new Module(Position{5, 1});
    m_stationReference->addModule(airlock);

    airlock->addHatch(new Hatch(airlock, false, HatchDirection::West));
    airlock->addHatch(new Hatch(airlock, false, HatchDirection::East));

    return airlock;
}

// Vytvoření a vrácení nového modulu
Module * ModuleFactory::generateNextModule(Hatch *hatchFrom) {
    if (m_stationReference == nullptr or hatchFrom == nullptr) {
        return nullptr;
    }

    Module * currentModule = hatchFrom->getFromModule();
    Module * newModule = nullptr;
    Hatch * returnHatch = nullptr;

    Position newModulePosition = currentModule->getPosition();
    HatchDirection returnHatchDirection = HatchDirection::South;

    switch (hatchFrom->getHatchDirection()) {
        case HatchDirection::North:
            newModulePosition.y -= 1 ;
            returnHatchDirection = HatchDirection::South;
            break;
        case HatchDirection::South:
            newModulePosition.y += 1 ;
            returnHatchDirection = HatchDirection::North;
            break;
        case HatchDirection::East:
            newModulePosition.x += 1 ;
            returnHatchDirection = HatchDirection::West;
            break;
        case HatchDirection::West:
            newModulePosition.x -= 1 ;
            returnHatchDirection = HatchDirection::East;
            break;
    }

    if (m_stationReference->isSpaceFree(newModulePosition) == false) {
        return nullptr;
    };

    newModule = new Module(newModulePosition);
    returnHatch = new Hatch(newModule, false, returnHatchDirection);
    returnHatch->connectToModule(currentModule);
    newModule->addHatch(returnHatch);
    hatchFrom->connectToModule(newModule);

    m_stationReference->addModule(newModule);

    return newModule;
}
