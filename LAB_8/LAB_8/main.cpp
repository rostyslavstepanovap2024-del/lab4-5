#include "radio.h"

int main() {
    
    RadioRelay r1(12.0, 5.0, 3);

    cout << "Initial parameters:" << endl;
    r1.display();

    
    increaseCurrent(r1, 2.5);

    cout << "\nUpdated parameters:" << endl;
    r1.display();

    return 0;
}
