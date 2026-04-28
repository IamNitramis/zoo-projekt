#include <iostream>

// Marťas
#include "Menu.h"
#include "Renderer.h"

// Ráďa
#include "Station.h"
#include "ModuleFactory.h"
#include "Module.h"
#include "Hatch.h"

// Vojta

// Partik


int main() {
    Renderer renderer;
    Menu mainMenu;

    int choice = mainMenu.run(renderer);

    renderer.clearScreen();
    std::cout << "Selected option index: " << choice << "\n";

    return 0;

    /*
    // 1. Založení světa (mapa 20x20)
    Station spaceStation(20, 20);
    ModuleFactory factory(&spaceStation);

    // 2. Vytvoření první místnosti (Airlocku) a usazení hráče
    Module* startModule = factory.createStartingAirlock();
    Module* currentPlayerModule = startModule;

    // 3. ukázka toho jak by mohla funkce na přesunutí fungovat

        bool GameManager::tryMovePlayer(HatchDirection direction) {
            // 1. KROK: Najdeme dveře požadovaným směrem
            Hatch* selectedHatch = nullptr;
            for (Hatch* hatch : m_currentPlayerModule->getHatches()) {
                if (hatch->getHatchDirection() == direction) {
                    selectedHatch = hatch;
                    break;
                }
            }

            // Žádné dveře tímto směrem nejsou (je tam zeď)
            if (selectedHatch == nullptr) {
                return false;
            }

            // 2. KROK: Zjistíme, co je za dveřmi
            Module* targetRoom = selectedHatch->getTargetModule(m_currentPlayerModule);

            // 3. KROK: Rozhodovací logika (přesun vs. stavba)
            if (targetRoom != nullptr) {
                // A) Místnost už existuje -> pouze se přesuneme
                m_currentPlayerModule = targetRoom;
                return true;
            }
            else {
                // B) Místnost neexistuje -> musíme ji postavit
                Module* newlyBuiltRoom = m_factory->generateNextModule(selectedHatch);

                if (newlyBuiltRoom != nullptr) {
                    m_currentPlayerModule = newlyBuiltRoom;
                    return true;
                } else {
                    return false;
                }
            }
        }
     */
}