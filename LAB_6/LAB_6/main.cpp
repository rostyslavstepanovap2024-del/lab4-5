#include "radio.h"
#include <iostream>

int main() {

    RadioRelay rr;

    std::size_t n;
    std::cout << "Laboratorna robota ¹6 — Radiorele (variant 20)\n";
    std::cout << "Maksymalna kilkist elementiv u masyvi: " << SIZE << "\n";

    while (true) {
        std::cout << "Vvedit kilkist elementiv dlya zberezhennya (1.." << SIZE << "): ";
        if (!(std::cin >> n)) {
            std::cout << "Nevirnyi vvid. Sprobuyte shche raz.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        if (rr.setCount(n)) break;
        std::cout << "Kilkist maye buty vid 1 do " << SIZE << ". Sprobuyte shche raz.\n";
    }

    // Zapovnennya danikh z perevirkamy
    rr.inputAll();

    // Vyvid rezultativ
    rr.printAll();

    std::cout << "Programa zavershena.\n";
    return 0;
}
