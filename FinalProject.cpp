// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "readValue.h"
#include "Planet.h"
#include <string>
#include <vector>
#include <cctype>
#include <exception>

using namespace std;

bool DeletePlanet(vector<Planet>& planets, long pos);
long search(vector<Planet>& planets, std::string target);
void insertionSort(vector<Planet>& planets);

int main()
{
    string menu = "1. Add Planet\n2. Delete Planet\n3. Find Planet\n4. List All Planets\n5. Sort Planets By Name\n6. Quit";
    int menuChoice = 0;
    vector<Planet> planets;
    while (menuChoice != 6) {
        cout << menu << endl;
        menuChoice = ReadValue("Select a menu option: ", 0, 6);

        switch (menuChoice) {
        case 1:
        {
            Planet newPlanet;
            string newName = "";
            do {
                cout << "Input the planet's name" << endl;
                getline(cin, newName);
            } while (!newPlanet.setName(newName));

            double newMass = 0.0;
            do {
                newMass = ReadValue("Input the planet's mass", 0);
            } while (!newPlanet.setMass(newMass));

            double newDiameter = 0.0;
            do {
                newDiameter = ReadValue("Input the planet's diameter", 0);
            } while (!newPlanet.setDiameter(newDiameter));

            planets.push_back(newPlanet);
            cout << "New Planet Created Successfully" << endl;
            break;
        }
        case 2:
        {
            string target;
            cout << "Input the planet's name" << endl;
            getline(cin, target);
            if (DeletePlanet(planets, search(planets, target))) {
                cout << "Planet deleted" << endl;
            }
            else {
                cerr << "Error! Unable to delete planet with given name" << endl;
            }
            break;
        }
        case 3:
        {
            string target = "";
            cout << "Input the planet's name" << endl;
            getline(cin, target);
            long pos = search(planets, target);
            if (pos != -1) {
                planets[pos].display();
            }
            else {
                cerr << "Planet not found" << endl;
            }
            break;
        }
        case 4:
        {
            cout.clear();
            if (!planets.empty()) {
                long len = planets.size();
                for (long i = 0;i < len;i++) {
                    planets[i].display();
                }
                cout << endl;
            }
            else {
                cerr << "Error! No planets found" << endl;
            }
            break;
        }
        case 5:
        {
            insertionSort(planets);
            cout << "Planets have been sorted" << endl;
            break;
        }
        }
    }
}

long search(vector<Planet>& planets, std::string target) {
    long index = -1;
    long len = planets.size();
    for (long i = 0;i < len;i++) {
        if (planets[i].getName() == target) {
            index = i;
        }
    }
    return index;
}

bool DeletePlanet(vector<Planet>& planets, long pos) {
    long len = planets.size();
    if (pos >= 0 && pos < len) {
        long end = len - 1;
        for (long i = pos;i < end;i++) {
            planets[i].setName(planets[i + 1].getName());
            planets[i].setMass(planets[i + 1].getMass());
            planets[i].setDiameter(planets[i + 1].getDiameter());
        }
        planets.pop_back();
        return true;
    }
    return false;
}

void insertionSort(vector<Planet>& planets) {
    long len = planets.size();
    for (long i = 1; i < len; i++) {
        Planet current = planets[i];
        int ascii = static_cast<int>(current.getName()[0]);
        long j = i - 1;
        while (j >= 0 && (static_cast<int>((planets[j].getName())[0])) > ascii) {
            planets[j + 1].setName(planets[j].getName());
            planets[j + 1].setDiameter(planets[j].getDiameter());
            planets[j + 1].setMass(planets[j].getMass());
            j--;
        }
        planets[j + 1].setName(current.getName());
        planets[j + 1].setDiameter(current.getDiameter());
        planets[j + 1].setMass(current.getMass());
    }
}

