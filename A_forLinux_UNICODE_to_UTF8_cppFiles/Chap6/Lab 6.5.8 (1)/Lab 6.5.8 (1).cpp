// Lab 6.5.8 (1).cpp: определяет точку входа для консольного приложения.
//

#include "iostream"
#include "string"

using namespace std;


class IpAddress
{
private:
	string ipAdress;

public:
	IpAddress();
	IpAddress(string ipAdress);
	string ToString();
};

IpAddress::IpAddress()
{
	this->ipAdress = "0.0.0.0";
}

IpAddress::IpAddress(string ipAdress)
{
	this->ipAdress = ipAdress;
}

string IpAddress::ToString()
{
	return this->ipAdress;
}


struct Collection {
	int size;
	IpAddress *elements;
};


class Network
{
private:
	Collection network;
public:
	Network();
	void PrintAdressses();
	void AddAddress(IpAddress address);
};

Network::Network()
{
	this->network = Collection();
}

void Network::AddAddress(IpAddress newAddress)
{
	IpAddress *temp;

	temp = new IpAddress[this->network.size+ 1];

	for (int i = 0; i < this->network.size; i++) {
		temp[i] = this->network.elements[i];
	}

	delete[] this->network.elements;

	temp[this->network.size] = newAddress;
	this->network.elements = temp;
	this->network.size++;
}

void Network::PrintAdressses()
{
	for (int i = 0; i < this->network.size; i++)
		cout << this->network.elements[i].ToString() << endl;
}


int main()
{
	string input;
	Network *net1 = new Network();
	Network *net2 = new Network();

	cin >> input;
	net1->AddAddress(IpAddress(input));

	cin >> input;
	net1->AddAddress(IpAddress(input));

	cin >> input;
	IpAddress temp = IpAddress(input);
	net1->AddAddress(temp);
	net2->AddAddress(temp);

	cin >> input;
	net2->AddAddress(IpAddress(input));

	cin >> input;
	net2->AddAddress(IpAddress(input));

	cout << "Network 1:\n";
	net1->PrintAdressses();

	cout << "Network 2:\n";
	net2->PrintAdressses();

	system("pause");
	return 0;
}