#include "vehicle.h"

Vehicle::Vehicle( int wheels ) : wheels(wheels) // konstruktor z listą inicjalizacyjną
{
	cout << "Vehicle constructed" << endl;
}

Vehicle::~Vehicle()
{
	cout << "Vehicle destructed" << endl;
}
