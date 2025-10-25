#include "radio.h"

int main() {
    RadioRelay relaySystem;
    int choice;

    do {
        std::cout << "\n====== MENU ======\n";
        std::cout << "1. Dodaty radiorle\n";
        std::cout << "2. Vyvesty vsi radiorle\n";
        std::cout << "3. Vydalyty radiorle\n";
        std::cout << "4. Ochystyty spysok\n";
        std::cout << "5. Vstavka radiorle\n";
        std::cout << "6. Obmin dvokh elementiv\n";
        std::cout << "7. Vykhid\n";
        std::cout << "Vash vybir: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            relaySystem.addRelay();
            break;
        case 2:
            relaySystem.showRelays();
            break;
        case 3:
            relaySystem.deleteRelay();
            break;
        case 4:
            relaySystem.clearRelays();
            break;
        case 5:
            relaySystem.insertRelay();
            break;
        case 6:
            relaySystem.swapRelays();
            break;
        case 7:
            std::cout << "Zavershennia prohramy...\n";
            break;
        default:
            std::cout << "Nekorektnyi vybir! Sprobuit shche raz.\n";
        }

    } while (choice != 7);

    return 0;
}
