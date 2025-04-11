#ifndef PLANET_H
#define PLANET_H
#include <string>
class Planet
{
private:
	const double G = 6.67430e-11;
	double mass, diameter;
	std::string name;
public:
	Planet();
	double surfaceArea();
	double density();
	double surfaceGravity();

	bool setMass(double m);
	bool setDiameter(double r);
	bool setName(std::string n);

	double getMass();
	double getDiameter();
	std::string getName();

	void display();
};
#endif

