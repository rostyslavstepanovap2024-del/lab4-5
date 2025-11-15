#include <iostream>
#include <limits>
#include "ChannelManager.h"

int main() {
    ChannelManager mgr;
    bool run = true;

    while (run) {
        std::cout << "\n===== MENU =====\n";
        std::cout << "1 - Add Radio Channel\n";
        std::cout << "2 - Add Fiber Channel\n";
        std::cout << "3 - Show All Records\n";
        std::cout << "4 - Remove Record By Index\n";
        std::cout << "5 - Compute Bandwidth Statistics\n";
        std::cout << "6 - Exit\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: mgr.addRadio(); break;
        case 2: mgr.addFiber(); break;
        case 3: mgr.listAll(); break;
        case 4: {
            std::cout << "Enter index to delete: ";
            size_t idx;
            std::cin >> idx;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            mgr.removeAt(idx);
            break;
        }
        case 5: mgr.computeStats(); break;
        case 6: run = false; break;

        default:
            std::cout << "Invalid option.\n";
            break;
        }
    }

    std::cout << "Program finished.\n";
    return 0;
}
