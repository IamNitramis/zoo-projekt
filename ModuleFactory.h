//
// Created by Radek on 28.04.2026.
//

#ifndef PROJEKT_ZOO_MODULEFACTORY_H
#define PROJEKT_ZOO_MODULEFACTORY_H

class Station;
class Hatch;
class Module;

class ModuleFactory {
    Station * m_stationReference;

public:
    ModuleFactory(Station * station);
    Module * createStartingAirlock();
    Module * generateNextModule(Hatch * hatchFrom);
};


#endif //PROJEKT_ZOO_MODULEFACTORY_H