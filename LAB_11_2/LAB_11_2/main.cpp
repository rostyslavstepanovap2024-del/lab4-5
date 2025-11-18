#include <iostream>
#include <limits>
#include "SoundManager.h"

int main() {
    SoundManager mgr;
    bool run = true;

    while (run) {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1 - Add Microphone\n";
        std::cout << "2 - Add Speaker\n";
        std::cout << "3 - Show All\n";
        std::cout << "4 - Calculate Statistics\n";
        std::cout << "5 - Delete Record\n";
        std::cout << "0 - Exit\n";
        std::cout << "Choice: ";

        int ch;
        std::cin >> ch;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (ch) {
        case 1: mgr.addMicrophone(); break;
        case 2: mgr.addSpeaker(); break;
        case 3: mgr.showAll(); break;
        case 4: mgr.calcStats(); break;
        case 5: {
            std::cout << "Enter index: ";
            size_t id;
            std::cin >> id;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            mgr.removeAt(id);
        }
              break;
        case 0: run = false; break;
        default: std::cout << "Invalid option.\n";
        }
    }

    std::cout << "Program finished.\n";
    return 0;
}
