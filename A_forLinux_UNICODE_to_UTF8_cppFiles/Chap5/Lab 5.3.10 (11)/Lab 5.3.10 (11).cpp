// Lab 5.3.10 (11).cpp : Defines the entry point for the console application.
//


#include <iostream>
using namespace std;
class FarmAnimal
{
public:
	FarmAnimal(double water_consumption, double eat_consumption);
	double getWaterConsumption();
	double getEatConsumption();
private:
	double water_consumption;
	double eat_consumption;
};
FarmAnimal::FarmAnimal(double water_consumption, double eat_consumption)
{
	this->water_consumption = water_consumption;
	this->eat_consumption = eat_consumption;
}
double FarmAnimal::getWaterConsumption()
{
	return water_consumption;
}
double FarmAnimal::getEatConsumption()
{
	return eat_consumption;
}
class DummyAnimal : public FarmAnimal
{
public:
	DummyAnimal();
};
DummyAnimal::DummyAnimal() : FarmAnimal(10.0, 15.0)
{
}
class DoublingAnimal : public FarmAnimal
{
public:
	DoublingAnimal(double given_water_consumption, double given_eat_consumption);
};

	DoublingAnimal::DoublingAnimal(double given_water_consumption, double given_eat_consumption)
	: FarmAnimal(2 * given_water_consumption, given_eat_consumption)
{
}
	 void printConsumption(FarmAnimal animal)
	 {
		 cout << "This animal consumes " << animal.getWaterConsumption()
			 << " liters of water" << endl;
		 cout << "This animal consumes " << animal.getEatConsumption()
			 << " ed of eat" << endl;
	 }
	 int main()
	 {
		 FarmAnimal animalA(5.0 , 10.0);
		 DummyAnimal animalB;
		 DoublingAnimal animalC(21.0, 11.0);
		 cout << "animalA consumes " << animalA.getWaterConsumption()
			 << " liters of water and " <<animalA.getEatConsumption() <<" ed of eat." << endl;
		 cout << "What about the others?" << endl;
		 printConsumption(animalB);
		 cout << "--------\n";
		 printConsumption(animalC);
		 return 0;
	 }
