#include "Planet.h"
#include <string>
#include <cmath>
#include <iostream>

Planet::Planet():mass(0.0),diameter(0.0),name("")
{
	;
}

//Accessors
double Planet::getMass() { return mass; }
double Planet::getDiameter() { return diameter; }
std::string Planet::getName() { return name; }

//Mutators
bool Planet::setMass(double m) {
	if (m >= 0.0) {
		mass = m;
		return true;
	}
	return false;
}
bool Planet::setDiameter(double r) {
	if (r >= 0.0) {
		diameter = r;
		return true;
	}
	return false;
}
bool Planet::setName(std::string n) {
	if (n != "") {
		name = n;
		return true;
	}
	return false;
}

//Methods
double Planet::surfaceArea() {
	return 4.0 * 3.14 * pow(diameter/2.0, 2.0);
}

double Planet::density() {
	return mass / ((4.0 / 3.0) * 3.14 * pow(diameter/2.0, 3.0));
}

double Planet::surfaceGravity() {
	return (mass * G) / (pow(diameter/2.0, 2.0));
}


void Planet::display() {
	std::cout.precision(3);
	std::cout.width(10);
	std::cout.setf(std::ios::showpoint);

	std::cout << "Planet name : " << name << "   |   ";
	std::cout << "Diameter : " << diameter << "   |   ";
	std::cout << "Mass : " << mass << "   |   ";
	std::cout << "Surface area: " << surfaceArea() << "   |   ";
	std::cout << "Density: " << density() << "   |   ";
	std::cout << "Surface gravity: " << surfaceGravity() << std::endl;
}