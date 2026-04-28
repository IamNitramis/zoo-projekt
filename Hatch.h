//
// Created by Radek on 28.04.2026.
//

#ifndef PROJEKT_ZOO_HATCH_H
#define PROJEKT_ZOO_HATCH_H

class Module;

class Hatch {
    int m_positionX;
    int m_positionY;
    bool m_isLocked;
    Module* m_moduleFrom;
    Module* m_moduleTo;

public:
    Hatch(int positionX, int positionY, Module * moduleFrom, bool isLocked);
    ~Hatch();
    int getPositionX();
    int getPositionY();
    void connectToModule(Module * moduleTo);
    Module * getTargetModule(Module * moduleFrom);
    bool isLocked();
    void unlock();
};


#endif //PROJEKT_ZOO_HATCH_H