// Lab 5.3.10 (3).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <iomanip>
class FlightBooking
{
public:
	FlightBooking(int id, int capacity, int reserved);
	FlightBooking();
	void printStatus();
	void deleteFlight() { id = 0; };
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);
	int getId() { return id; }
private:
	int id;
	int capacity;
	int reserved;
};
FlightBooking::FlightBooking()
{
	id = 0; capacity = 0; reserved = 0;
}
// ...
void FlightBooking::printStatus()
{
	std::cout << "Flight " << id << " : " << reserved << " / " << capacity << " ( " << std::setprecision(0) << std::fixed << ((double)reserved / (double)capacity * 100.0) << " % ) seats taken" << std::endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = capacity;
	if (reserved < 0) { reserved = 0; }
	if (((double)reserved / (double)capacity) > 1.05)
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
bool FlightBooking::cancelReservations(int number_ob_seats)
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
	FlightBooking booking[10];
	bool flag = true;
	// Use this to have some starting value
	// booking[0] = FlightBooking(1, 400, 0);
	// booking[0].printStatus();
	std::string command = "";
	while (command != "quit")
	{
		flag = true;
		for each (FlightBooking var in booking)
		{
			if (var.getId() != 0)
			{
				flag = false;
				var.printStatus();
			}
		}
		if (flag)
		{
			std::cout << "No flights in the system\n";
		}

		std::cout << "What would you like to do?: ";
		std::getline(std::cin, command);
		// handle the command
		int i = command.find(" ");
		if (command.substr(0, i) == "create")
		{
			int k = command.substr(i + 1).find(" ");
			int j = std::stoi(command.substr(i + 1, k));
			//std::cout << j << std::endl;
			int l = std::stoi(command.substr(i + 1).substr(k + 1));
			//std::cout << l << std::endl;
			if (j != 0)
			{
				int a = 0;
				for (; a < 10; a++)
				{
					if (booking[a].getId() == 0) { break; }
				}
				booking[a] = FlightBooking(j, l, 0);
				//booking[a].printStatus();
			}
			else 
			{
				std::cout << "Cannot perform this operation : ID can't be 0!\n";
			}
		}

		if (command.substr(0, i) == "delete")
		{

			bool f = false;
			int j = std::stoi(command.substr(i + 1));
			int a = 0;

			for (; a < 10; a++)
			{
				if (booking[a].getId() == j) { f = true; break; }
			}
			if (f)
			{
				booking[a].deleteFlight();
			}
			else 
			{
				std::cout << "Cannot perform this operation : ID not found\n";
			}
		}

		if (command.substr(0, i) == "add")
		{
			int k = command.substr(i + 1).find(" ");
			int j = std::stoi(command.substr(i + 1, k));
			//std::cout << j << std::endl;
			int l = std::stoi(command.substr(i + 1).substr(k + 1));
			bool f = false;
			int a = 0;

			for (; a < 10; a++)
			{
				if (booking[a].getId() == j) { f = true; break; }
			}
			if (f)
			{
				bool flag = booking[a].reserveSeats(l);
				if (flag) { }
				else
				{
					std::cout << "Cannot perform this operation : overbooking\n";
				}
			}
			else
			{
				std::cout << "Cannot perform this operation : ID not found\n";
			}

		}

		if (command.substr(0, i) == "cancel")
		{

			int k = command.substr(i + 1).find(" ");
			int j = std::stoi(command.substr(i + 1, k));
			//std::cout << j << std::endl;
			int l = std::stoi(command.substr(i + 1).substr(k + 1));
			bool f = false;
			int a = 0;

			for (; a < 10; a++)
			{
				if (booking[a].getId() == j) { f = true; break; }
			}
			if (f)
			{
				bool flag = booking[a].cancelReservations(l);
				if (flag) { }
				else
				{
					std::cout << "Cannot perform this operation\n";
				}
			}
			else
			{
				std::cout << "Cannot perform this operation : ID not found\n";
			}


		}
	}
	return 0;
}

