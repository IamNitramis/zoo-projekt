//
// Created by PC on 14.04.2026.
//

#include "Input.h"
#include <conio.h>

KeyCode Input::getKey() {
    int ch = _getch();

    // Detekce sipek (vraci 0 nebo 224, nasleduje kod sipky)
    if (ch == 0 || ch == 224) {
        ch = _getch();
        switch (ch) {
            case 72: return KeyCode::Up;
            case 80: return KeyCode::Down;
            case 75: return KeyCode::Left;
            case 77: return KeyCode::Right;
            default: return KeyCode::Unknown;
        }
    }

    // Standardni klavesy
    switch (ch) {
        case 13: return KeyCode::Enter;
        case 27: return KeyCode::Esc;
        case 32: return KeyCode::Space;

        case 'w': case 'W': return KeyCode::W;
        case 's': case 'S': return KeyCode::S;
        case 'a': case 'A': return KeyCode::A;
        case 'd': case 'D': return KeyCode::D;

        case '1': case '+': return KeyCode::Num1;
        case '2': case -42: return KeyCode::Num2;
        case '3': case -25: return KeyCode::Num3;
        case '4': case -97: return KeyCode::Num4;

        default: return KeyCode::Unknown;
    }
}