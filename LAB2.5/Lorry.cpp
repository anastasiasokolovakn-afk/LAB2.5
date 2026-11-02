#include "Lorry.h"
#include <iostream>
#include <string>
#include <sstream>

Lorry::Lorry() {
	capacity = 0.0;
}
Lorry::Lorry(const Car& car, double capacity) {
	SetCar(car);
	if (!SetCapacity(capacity)) this->capacity = 1.0;
}
Lorry::Lorry(const Lorry& other) {
	car = other.car;
	capacity = other.capacity;
}

const Car& Lorry::GetCar() const {
	return car;
}
double Lorry::GetCapacity() const {
	return capacity;
}
bool Lorry::SetCar(const Car& value) {
	car = value;
	return true;
}
bool Lorry::SetCapacity(double value) {
	if (value > 0) {
		capacity = value;
		return true;
	}
	else {
		cout << "Помилкове значення" << endl;
		return false;
	}
}

Lorry& Lorry::operator=(const Lorry& other) {
	if (this != &other) {
		car = other.car;
		capacity = other.capacity;
	}
	return *this;
}

Lorry::operator string() const {
	stringstream sout;
	sout << "Вантажівка: " << string(car) << ", Вантажопідйомність: " << capacity << " т";
	return sout.str();
}

Lorry& Lorry::operator++() {
	capacity += 10.0;
	return *this;
}
Lorry& Lorry::operator--() {
	if (capacity > 10.0) capacity -= 10.0;
	return *this;
}

Lorry Lorry::operator++(int) {
	Lorry temp = *this;
	capacity += 10.0;
	return temp;
}
Lorry Lorry::operator--(int) {
	Lorry temp = *this;
	if (capacity > 10.0) capacity -= 10.0;
	return temp;
}

ostream& operator<<(ostream& out, const Lorry& obj) {
	out << string(obj);
	return out;
}

istream& operator>>(istream& in, Lorry& obj) {
	Car c;
	double cap;
	cout << "--- Введення даних вантажівки ---" << endl;
	in >> c;
	cout << "Введіть вантажопідйомність: ";
	in >> cap;
	obj.SetCar(c);
	obj.SetCapacity(cap);

	return in;
}

bool Lorry::ReassignBrand(const string& newBrand) {
	return car.SetBrand(newBrand);
}
bool Lorry::ChangeCapacity(double newCapacity) {
	return SetCapacity(newCapacity);
}