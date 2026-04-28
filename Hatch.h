//
// Created by Radek on 28.04.2026.
//

#ifndef PROJEKT_ZOO_HATCH_H
#define PROJEKT_ZOO_HATCH_H

class Module;

enum class HatchDirection {
    North, South, East, West
};

class Hatch {
    bool m_isLocked;
    Module* m_moduleFrom;
    Module* m_moduleTo;
    HatchDirection m_hatchDirection;

public:
    Hatch(Module * moduleFrom, bool isLocked, HatchDirection hatchDirection);
    ~Hatch();
    void connectToModule(Module * moduleTo);
    Module * getTargetModule(Module * moduleFrom);
    Module * getFromModule();
    HatchDirection getHatchDirection();
    bool isLocked();
    void unlock();
};


#endif //PROJEKT_ZOO_HATCH_H