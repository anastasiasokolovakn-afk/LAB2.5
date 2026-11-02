#pragma once
#include <string>
#include <iostream>

using namespace std;

class Car
{
private:
	string brand = "";
	int cylinders = 0;
	double power = 0.0;
public:
	Car();
	Car(const string& brand, int cylinders, double power);
	Car(const Car& other);

	string GetBrand() const;
	int GetCylinders() const;
	double GetPower() const;

	bool SetBrand(const string& value);
	bool SetCylinders(int value);
	bool SetPower(double value);

	Car& operator=(const Car& other);

	operator string() const;

	Car& operator++();
	Car& operator--();

	Car operator++(int);
	Car operator--(int);

	friend ostream& operator<<(ostream& out, const Car& obj);
	friend istream& operator>>(istream& in, Car& obj);

	bool ChangePower(double newPower);
	bool ReassignBrand(const string& newBrand);
};
