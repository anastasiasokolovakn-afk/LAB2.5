#include "Car.h"
#include <iostream>
#include <sstream>
#include <string>

Car::Car() {
	brand = "";
	cylinders = 0;
	power = 0.0;
}
Car::Car(const string& brand, int cylinders, double power) {
	if (!SetBrand(brand)) this->brand = "Unknown";
	if (!SetCylinders(cylinders)) this->cylinders = 1;
	if (!SetPower(power)) this->power = 1.0;
}
Car::Car(const Car& other) {
	brand = other.brand;
	cylinders = other.cylinders;
	power = other.power;
}

string Car::GetBrand() const {
	return brand;
}
int Car::GetCylinders() const {
	return cylinders;
}
double Car::GetPower() const {
	return power;
}

bool Car::SetBrand(const string& value) {
	if (!value.empty()) {
		brand = value;
		return true;
	}
	else {
		cout << "Не вказано бренд" << endl;
		return false;
	}
}
bool Car::SetCylinders(int value) {
	if (value > 0) {
		cylinders = value;
		return true;
	}
	else {
		return false;
	}
}
bool Car::SetPower(double value) {
	if (value > 0) {
		power = value;
		return true;
	}
	else {
		return false;
	}
}

Car& Car::operator=(const Car& other) {
	if (this != &other) {
		brand = other.brand;
		cylinders = other.cylinders;
		power = other.power;
	}
	return *this;

}

Car::operator string() const {
	stringstream sout;
	sout << "(Марка: " << brand << ", Циліндри: " << cylinders << ", Потужність: " << power << ")";
	return sout.str();
}

Car& Car::operator++() {
	power += 10.0;
	return *this;
}
Car& Car::operator--() {
	if (power > 10.0) power -= 10.0;
	return *this;
}

Car Car::operator++(int) {
	Car temp = *this; 
	power += 10.0;
	return temp;
}
Car Car::operator--(int) {
	Car temp = *this;
	if (power > 10.0) power -= 10.0;
	return temp;
}

ostream& operator<<(ostream& out, const Car& obj) {
	out << string(obj);
	return out;
}
istream& operator>>(istream& in, Car& obj) {
	string b;
	int c;
	double p;

	cout << "Введіть марку автомобіля: ";
	in >> b;
	cout << "Введіть кількість циліндрів: ";
	in >> c;
	cout << "Введіть потужність: ";
	in >> p;

	obj.SetBrand(b);
	obj.SetCylinders(c);
	obj.SetPower(p);

	return in;
}

bool Car::ChangePower(double newPower) {
	return SetPower(newPower);
}
bool Car::ReassignBrand(const string& newBrand) {
	return SetBrand(newBrand);
}