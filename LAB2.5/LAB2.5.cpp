#include "Car.h"
#include "Lorry.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>

using namespace std;

#pragma pack(push, 1)
class CarPacked {
private:
    string brand;
    int cylinders;
    double power;
};
#pragma pack(pop)

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "--- Демонстрація конструкторів ---" << endl;
    Car car1;
    Car car2("Toyota", 4, 150.0);
    Car car3 = car2;

    Lorry lorry1;
    Lorry lorry2(car2, 5.0);
    Lorry lorry3 = lorry2;

    cout << "Створена вантажівка: " << lorry2 << endl;

    cout << "\n--- Демонстрація методів та операторів ---" << endl;
    lorry2.ChangeCapacity(7.5);
    lorry2.ReassignBrand("Ford");
    cout << "Після зміни марки та вантажопідйомності: " << lorry2 << endl;

    cout << "\nІнкремент (префіксний, збільшує ємність): " << ++lorry2 << endl;
    cout << "Декремент (постфіксний, повертає старе): " << lorry2-- << endl;
    cout << "Після постфіксного декременту: " << lorry2 << endl;

    cout << "\n--- Демонстрація масиву об'єктів ---" << endl;
    const int SIZE = 2;
    Lorry fleet[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "\nЗаповнення вантажівки #" << i + 1 << ":" << endl;
        cin >> fleet[i];
    }

    cout << "\nВаш автопарк:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << fleet[i] << endl;
    }

    cout << "\n--- Демонстрація розміру класів ---" << endl;
    cout << "Розмір стандартного класу Car: " << sizeof(Car) << " байт" << endl;
    cout << "Розмір упакованого класу CarPacked (#pragma pack(1)): " << sizeof(CarPacked) << " байт" << endl;

    return 0;
}