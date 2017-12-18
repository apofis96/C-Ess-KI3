// Lab 5.3.10 (1).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
class FlightBooking
{
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
private:
	int id;
	int capacity;
	int reserved;
};
void FlightBooking::printStatus()
{
	std::cout << "Flight" << id << " : " << reserved << " / " << capacity << " ( " << std::setprecision(0) << std::fixed << ((double)reserved / (double)capacity * 100.0) << " % ) seats taken" << std::endl;
}
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
}
int main()
{
	int reserved = 0,
		capacity = 0;
	std::cout << "Provide flight capacity: ";
	std::cin >> capacity;
	std::cout << "Provide number of reserved seats: ";
	std::cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	booking.printStatus();
	return 0;
}