#include <iostream>
#include <string>
#include <locale>
using namespace std;

class RadioRelay {
private:
    double coilVoltage;        
    double maxCurrent;         
    int contactGroups;         

public:
    
    RadioRelay() {
        coilVoltage = 0.0;
        maxCurrent = 0.0;
        contactGroups = 0;
        cout << "Створено об'єкт RadioRelay (за замовчуванням)" << endl;
    }

    
    RadioRelay(double voltage, double current, int groups) {
        setCoilVoltage(voltage);
        setMaxCurrent(current);
        setContactGroups(groups);
        cout << "Створено об'єкт RadioRelay (з параметрами)" << endl;
    }

    
    ~RadioRelay() {
        cout << "Об'єкт RadioRelay знищено" << endl;
    }


    void setCoilVoltage(double voltage) {
        if (voltage > 0)
            coilVoltage = voltage;
        else {
            coilVoltage = 0;
            cout << "Помилка: напруга має бути > 0!" << endl;
        }
    }

    void setMaxCurrent(double current) {
        if (current > 0)
            maxCurrent = current;
        else {
            maxCurrent = 0;
            cout << "Помилка: струм має бути > 0!" << endl;
        }
    }

    void setContactGroups(int groups) {
        if (groups > 0)
            contactGroups = groups;
        else {
            contactGroups = 0;
            cout << "Помилка: кількість груп має бути > 0!" << endl;
        }
    }

    
    double getCoilVoltage() const { return coilVoltage; }
    double getMaxCurrent() const { return maxCurrent; }
    int getContactGroups() const { return contactGroups; }

    
    void inputData() {
        double v, c;
        int g;
        cout << "Введіть напругу котушки: ";
        cin >> v;
        setCoilVoltage(v);

        cout << "Введіть максимальний струм: ";
        cin >> c;
        setMaxCurrent(c);

        cout << "Введіть кількість груп контактів: ";
        cin >> g;
        setContactGroups(g);
    }

    
    void displayData() const {
        cout << "=== Інформація про радіореле ===" << endl;
        cout << "Напруга котушки: " << coilVoltage << " В" << endl;
        cout << "Максимальний струм: " << maxCurrent << " А" << endl;
        cout << "Кількість груп контактів: " << contactGroups << endl;
    }

        bool matchesCriteria(double minVoltage, double minCurrent) const {
        return (coilVoltage >= minVoltage && maxCurrent >= minCurrent);
    }
};

int main() {
    
    setlocale(LC_ALL, "ukr");   // для Linux / MinGW
    // system("chcp 65001 > nul"); // для Windows-консолі (UTF-8)

    
    RadioRelay r1;
    r1.inputData();
    r1.displayData();

    cout << endl;

    
    RadioRelay r2(12, 5, 3);
    r2.displayData();

    cout << endl;

        double requiredVoltage = 10;
    double requiredCurrent = 4;

    cout << "Перевірка критерію (U >= " << requiredVoltage
        << " В, I >= " << requiredCurrent << " А):" << endl;

    if (r1.matchesCriteria(requiredVoltage, requiredCurrent)) {
        cout << "Об'єкт r1 відповідає критерію" << endl;
    }
    else {
        cout << "Об'єкт r1 не відповідає критерію" << endl;
    }

    if (r2.matchesCriteria(requiredVoltage, requiredCurrent)) {
        cout << "Об'єкт r2 відповідає критерію" << endl;
    }
    else {
        cout << "Об'єкт r2 не відповідає критерію" << endl;
    }

    return 0;
}
