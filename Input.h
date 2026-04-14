//
// Created by PC on 14.04.2026.
//

#ifndef PROJEKT_ZOO_INPUT_H
#define PROJEKT_ZOO_INPUT_H


#define INPUT_H

enum class KeyCode {
    Up,
    Down,
    Left,
    Right,
    W,
    A,
    S,
    D,
    Enter,
    Esc,
    Space,
    Num1,
    Num2,
    Num3,
    Num4,
    Unknown
};

class Input {
public:
    static KeyCode getKey();
};

#endif //PROJEKT_ZOO_INPUT_H