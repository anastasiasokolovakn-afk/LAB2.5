#pragma once
#include "Car.h"

using namespace std;

class Lorry
{
private:
	Car car;
	double capacity = 0.0;
public:
	Lorry();
	Lorry(const Car& car,double capacity);
	Lorry(const Lorry& other);

	const Car& GetCar() const;
	double GetCapacity() const;
	bool SetCar(const Car& value);
	bool SetCapacity(double value);

	Lorry& operator=(const Lorry& other);

	operator string() const;

	Lorry& operator++();
	Lorry& operator--();

	Lorry operator++(int);
	Lorry operator--(int);

	friend ostream& operator<<(ostream& out, const Lorry& obj);
	friend istream& operator>>(istream& in, Lorry& obj);

	bool ReassignBrand(const string& newBrand);
	bool ChangeCapacity(double newCapacity);
};

