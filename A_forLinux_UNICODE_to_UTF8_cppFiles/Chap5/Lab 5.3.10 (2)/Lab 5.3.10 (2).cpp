// Lab 5.3.10 (2).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <string>
class FlightBooking
{
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool canceReservations(int number_ob_seats);
private:
	int id;
	int capacity;
	int reserved;
};
// ...
void FlightBooking::printStatus()
{
	std::cout << "Flight" << id << " : " << reserved << " / " << capacity << " ( " << std::setprecision(0) << std::fixed << ((double)reserved / (double)capacity * 100.0) << " % ) seats taken" << std::endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = capacity;
	if (reserved < 0) { reserved = 0; }
	if (((double)reserved / (double)capacity ) > 1.05)
	{
		reserved = capacity * 1.05;
	}
	this->reserved = reserved;
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
	if ((((double)reserved + (double)number_ob_seats) / (double)capacity) > 1.05)
	{
		return false;
	}
	else
	{
		reserved += number_ob_seats;
		return true;
	}
}
bool FlightBooking::canceReservations(int number_ob_seats)
{
	// try to cancel reservations and return 'true' on success
	// keep the limits in mind
	if (number_ob_seats < 0) { return false; }
	if ((reserved - number_ob_seats) > 0)
	{
		reserved -= number_ob_seats;
		return true;
	}
	return false;
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
	std::string command = "";
	while (command != "quit")
	{
		booking.printStatus();
		std::cout << "What would you like to do?: ";
		std::getline(std::cin , command);
		// handle the command
		int i = command.find(" ");
		if (command.substr(0, i) == "add")
		{
			int j = std::stoi(command.substr(i+1));
			bool flag = booking.reserveSeats(j);
			if (flag) { booking.printStatus(); }
			else
			{
				std::cout << "Cannot perform this operation\n";
			}
		}

		if (command.substr(0, i) == "cancel")
		{
			int j = std::stoi(command.substr(i+1));
			bool flag = booking.canceReservations(j);
			if (flag) { booking.printStatus(); }
			else
			{
				std::cout << "Cannot perform this operation\n";
			}
		}
	}
	return 0;
}

