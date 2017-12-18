// Lab 6.3.7 (1).cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

class IPAddress
{
public:
	IPAddress()
	{
		ip = "0.0.0.0";
	}
	IPAddress(string ip)
	{
		this->ip = ip;
	}
	IPAddress(IPAddress *ip)
	{
		this->ip = ip->ip;
	}

	virtual void Print()
	{
		cout << ip;
	}

protected:
	string ip;
};

class IPAddressChecked : public IPAddress
{
public:
	IPAddressChecked()
	{
		isCorrect = true;
	}
	IPAddressChecked(string ip) : IPAddress(ip)
	{
		this->isCorrect = CheckValidity();
	}
	IPAddressChecked(IPAddressChecked *ip) : IPAddress(ip)
	{
		isCorrect = ip->isCorrect;
	}

	void Print()
	{
		IPAddress::Print();
		cout << " - "; 
		if (isCorrect)
		{
			cout << "Correct";
		}
		else
		{
			cout << "Not Correct";
		}
	}
private:
	bool isCorrect;

	bool CheckValidity()
	{
		string octet;
		int i = -1;
		int octetN = 0;

		while ((i = ip.find('.', i + 1)) != -1)
			octetN++;

		if (octetN != 3 )
			return false;

		i = -1;

		for (int j = 0; j < 4; j++)
		{
			if (j == 3)
			{
				if ((i + 1) < ip.length())
				{
					octet = this->ip.substr(i + 1);
				}
				else return false;
			}
			else
			{
				if ((this->ip.find('.', i + 1) - i - 1) > 0)
				{
					octet = this->ip.substr(i + 1, this->ip.find('.', i + 1) - i - 1);
				}
				else return false;
			}

			i = this->ip.find('.', i + 1);


			if (stoi(octet) < 0 || stoi(octet) > 255)
				return false;
			

		}
		return true;
	}
};

int main()
{
	IPAddress **ip = new IPAddress*[3];
	string str;

	getline(cin, str);
	ip[0] = new IPAddress(str);

	getline(cin, str);
	ip[1] = new IPAddressChecked(str);

	getline(cin, str);
	ip[2] = new IPAddressChecked(str);


	for (int i = 0; i < 3; i++)
	{
		ip[i]->Print();
		cout << endl;
	}

	return 0;
}